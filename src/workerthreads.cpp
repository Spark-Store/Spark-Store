
#include <QProcess>
#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include "workerthreads.h"
#include "widget.h"

void SpkAppInfoLoaderThread::run()
{
    emit requestResetUi();

    QProcess get_json;
    QString urladdress, deatils, more, packagename, appweb;
    QDir dir("/tmp");
    bool isInstalled;
    dir.mkdir("spark-store");
    QDir::setCurrent("/tmp/spark-store");

    get_json.start("curl -o app.json " + targetUrl.toString());
    if(waitDownload(get_json) == -1)
        return;
    if(get_json.exitCode())
    {
        Widget::sendNotification(tr("Failed to download app info. Please check internet connection."));
    }

    QFile app_json("app.json");
    if(app_json.open(QIODevice::ReadOnly)){
        // 成功得到json文件
        QByteArray json_array = app_json.readAll();
        // 将路径转化为相应源的下载路径
        urladdress = targetUrl.toString().left(targetUrl.toString().length()-8);
        QStringList downloadurl=urladdress.split("/");

        QString deburl = serverUrl;
        deburl = deburl.left(urladdress.length()-1);
        urladdress = "https://cdn.jsdelivr.net/gh/Jerrywang959/jsonpng@master/"; // 使用图片专用服务器请保留这行，删除后将使用源服务器
        urladdress = urladdress.left(urladdress.length()-1);

        for (int i=3;i<downloadurl.size();i++) {
            urladdress+="/"+downloadurl[i];
            deburl+="/"+downloadurl[i];
        }

        // 路径转化完成
        QJsonObject json= QJsonDocument::fromJson(json_array).object();
        QString appName = json["Name"].toString();
        QUrl fileUrl = deburl + json["Filename"].toString();

        // 软件信息加载
        QString details;
        details = tr("PkgName: ") + json["Pkgname"].toString()+"\n";
        details += tr("Version: ") + json["Version"].toString()+"\n";
        if(json["Author"].toString() != "" && json["Author"].toString() != " "){
            details += tr("Author: ") + json["Author"].toString() + "\n";
        }

        if(json["Website"].toString() != "" && json["Website"].toString() != " "){
            details += tr("Official Site: ") + json["Website"].toString() + "\n";
            //ui->pushButton_website->show(); move to setinfo slot
            appweb=json["Website"].toString();
        }
        details+=tr("Contributor: ")+json["Contributor"].toString()+"\n";
        details+=tr("Update Time: ")+json["Update"].toString()+"\n";
        details+=tr("Installed Size: ")+json["Size"].toString()+"\n";
        more = json["More"].toString();

        QProcess isInstall;
        packagename = json["Pkgname"].toString();
        isInstall.start("dpkg -s "+json["Pkgname"].toString());
        isInstall.waitForFinished();
        int error=QString::fromStdString(isInstall.readAllStandardError().toStdString()).length();
        if(error==0)
            isInstalled = true;
        else
            isInstalled = false;

        emit requestSetAppInformation(&appName, &details, &more, &appweb, &packagename, &fileUrl, isInstalled);

        //tag加载
        QString tags=json["Tags"].toString();
        QStringList tagList=tags.split(";");
        emit requestSetTags(&tagList);

        // 图标加载
        get_json.start("curl -o icon.png "+urladdress+"icon.png");
        if(waitDownload(get_json) == -1)
            return;
        if(!get_json.exitCode()) {
            QPixmap appicon("icon.png");
            emit finishedIconLoad(&appicon);
        }
        else
            Widget::sendNotification(tr("Failed to load application icon."));


        // 截图展示加载
        QPixmap screenshotCache[5];
        for (int i = 0; i < 5; i++) {
            QString cmd = "curl -o screen_"+QString::number(i+1)+".png "+urladdress+"screen_"+QString::number(i+1)+".png";
            get_json.start(cmd);
            if(waitDownload(get_json) == -1)
                return;
            bool s = screenshotCache[i].load(QString(TMP_PATH) + "/screen_"+QString::number(i+1)+".png");
            if(s){
                emit finishedScreenshotLoad(&screenshotCache[i], i);
            }else{
                emit finishedScreenshotLoad(nullptr, i);
                QFile::remove("screen_"+QString::number(i+1)+".png");
                break;
            }
        }
        emit finishAllLoading();
    }

}

void SpkAppInfoLoaderThread::setUrl(const QUrl &url)
{
    targetUrl = url;
}

void SpkAppInfoLoaderThread::setServer(const QString &server)
{
    serverUrl = server;
}

void SpkAppInfoLoaderThread::downloadFinished(int exitcode, QProcess::ExitStatus status)
{
    Q_UNUSED(exitcode);
    Q_UNUSED(status);
    qDebug() << "Finish one download";
    finishedDownload = true;
}

int SpkAppInfoLoaderThread::waitDownload(QProcess& downloader)
{
    while(!downloader.waitForFinished(100))
    {
        if(downloader.state() == QProcess::NotRunning)
            return -1;
        if(this->isInterruptionRequested())
        {
            downloader.terminate();
            downloader.waitForFinished(-1);
            qDebug() << "Appinfo loader thread was forcefully terminated";
            return -1;
        }
    }
    return 0;
}
