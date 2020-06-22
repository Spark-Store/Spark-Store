#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QFileInfo>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QVBoxLayout>
#include "urls.h"
#include <QDir>
#include <QProcess>
#include <QJsonDocument>
#include <QFile>
#include <QJsonObject>
#include <QByteArray>
#include <QPixmap>
#include <QtConcurrent> //并发
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->webView->setUrl(QUrl(URL_MAIN));
    ui->webView->page()->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);
    ui->stackedWidget->setCurrentIndex(0);
    ui->listWidget->hide();
    manager = new QNetworkAccessManager(this);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_webView_linkClicked(const QUrl &arg1)
{
    //判断，如果末尾是/就直接访问，如果是app.json就打开详情页
    if(arg1.path().right(1)=="/"){
        ui->webView->setUrl(arg1);
    }else if(arg1.path().right(8)=="app.json"){
        load.cancel();//打开并发加载线程前关闭正在执行的线程
        load.waitForFinished();
        QPixmap pixmap_null;//一个空的图片指针，用来清空先有内容
        ui->label_appicon->setPixmap(pixmap_null);
        ui->screen_1->setPixmap(pixmap_null);
        ui->screen_2->setPixmap(pixmap_null);
        ui->screen_3->setPixmap(pixmap_null);
        ui->screen_4->setPixmap(pixmap_null);
        ui->screen_5->setPixmap(pixmap_null);
        //先隐藏详情页负责显示截图的label
        ui->screen_1->hide();
        ui->screen_2->hide();
        ui->screen_3->hide();
        ui->screen_4->hide();
        ui->screen_5->hide();
        ui->label_more->setText("");//清空详情介绍
        ui->label_info->setText("");
        ui->label_appname->setText("");
        ui->stackedWidget->setCurrentIndex(2);
        load = QtConcurrent::run([=](){
            loadappinfo(arg1);
        });
    }
}
void Widget::loadappinfo(QUrl arg1)
{

    ui->label_show->setText("正在加载，请稍候");


    QProcess get_json;
    QDir dir;
    dir.cd("/tmp");
    dir.mkdir("deepin-community-store");
    QDir::setCurrent("/tmp/deepin-community-store");
    get_json.start("wget -O app.json "+arg1.toString());
    get_json.waitForFinished();
    QFile app_json("app.json");
    if(app_json.open(QIODevice::ReadOnly)){
//        //成功得到json文件
        QByteArray json_array=app_json.readAll();
        urladdress=arg1.toString().left(arg1.toString().length()-8);
        QJsonObject json= QJsonDocument::fromJson(json_array).object();
        appName = json["name"].toString();
        url=urladdress + json["filename"].toString();
        qDebug()<<appName;
        ui->label_appname->setText(appName);
        system("rm -r *.png");
        ui->label_show->show();
        //图标加载
        get_json.start("wget -O icon.png "+urladdress+"icon.png");
        get_json.waitForFinished();
        QPixmap appicon;
        qDebug()<<appicon.load("icon.png");
        ui->label_appicon->setPixmap(appicon);
        //软件信息加载
        QString info;
        info="版本号："+json["version"].toString()+"\n";
        info+="作者："+json["author"].toString()+"\n";
        info+="官网："+json["website"].toString()+"\n";
        ui->label_info->setText(info);
        ui->label_more->setText(json["more"].toString());

        get_json.start("wget "+urladdress+"screen_1.png");
        get_json.waitForFinished();
        if(screen[0].load("screen_1.png")){
            ui->screen_1->show();
            ui->screen_1->setPixmap(screen[0]);
            ui->screen_1->setScaledContents(true);
        }
        get_json.start("wget "+urladdress+"screen_2.png");
        get_json.waitForFinished();
        if(screen[1].load("screen_2.png")){
            ui->screen_2->show();
            ui->screen_2->setPixmap(screen[1]);
            ui->screen_2->setScaledContents(true);
        }
        get_json.start("wget "+urladdress+"screen_3.png");
        get_json.waitForFinished();
        if(screen[2].load("screen_3.png")){
            ui->screen_3->show();
            ui->screen_3->setPixmap(screen[2]);
            ui->screen_3->setScaledContents(true);
        }
        get_json.start("wget "+urladdress+"screen_4.png");
        get_json.waitForFinished();
        if(screen[3].load("screen_4.png")){
            ui->screen_4->show();
            ui->screen_4->setPixmap(screen[3]);
            ui->screen_4->setScaledContents(true);
        }
        get_json.start("wget "+urladdress+"screen_5.png");
        get_json.waitForFinished();
        if(screen[4].load("screen_5.png")){
            ui->screen_5->show();
            ui->screen_5->setPixmap(screen[4]);
            ui->screen_5->setScaledContents(true);
        }
        ui->label_show->setText("");
        ui->label_show->hide();

    }

}
void Widget::on_pushButton_clicked()
{
    on_menu_btn_download_clicked();
    allDownload+=1;
    QFileInfo info(url.path());
    QString fileName(info.fileName());  //获取文件名
    if(fileName.isEmpty())
    {
        fileName = "index.html";
    }

    download_list[allDownload-1].setParent(ui->listWidget);
    QListWidgetItem *item=new QListWidgetItem(ui->listWidget);
    item->setSizeHint(download_list[allDownload-1].size());
    ui->listWidget->setItemWidget(item,&download_list[allDownload-1]);
    urList.append(url);
    download_list[allDownload-1].setName(appName);
    download_list[allDownload-1].setFileName(fileName);
    if(!isBusy){
        file = new QFile(fileName);
        if(!file->open(QIODevice::WriteOnly))
        {
            qDebug()<<"file open error";
            delete file;
            file = 0;
            return ;
        }
        nowDownload+=1;
        startRequest(urList.at(nowDownload-1)); //进行链接请求
    }
}

void Widget::startRequest(QUrl url)
{
    ui->listWidget->show();
    ui->label->hide();
    isBusy=true;
    isdownload=true;
    reply = manager->get(QNetworkRequest(url));
    connect(reply,SIGNAL(finished()),this,SLOT(httpFinished()));
    connect(reply,SIGNAL(readyRead()),this,SLOT(httpReadyRead()));
    connect(reply,SIGNAL(downloadProgress(qint64,qint64)),this,SLOT(updateDataReadProgress(qint64,qint64)));

}

void Widget::closeList(int)
{

}


void Widget::httpReadyRead()
{
    if(file)
    {
        file->write(reply->readAll());
    }
}
void Widget::updateDataReadProgress(qint64 bytesRead, qint64 totalBytes)
{
    download_list[nowDownload-1].setMax(1000); //最大值
    download_list[nowDownload-1].setValue((bytesRead*1000)/totalBytes); //当前值
}

void Widget::httpFinished() //完成下载
{

file->flush();
file->close();
reply->deleteLater();
reply = 0;
delete file;
file = 0;
isdownload=false;
isBusy=false;
download_list[nowDownload-1].readyInstall();
qDebug()<<nowDownload;
qDebug()<<allDownload;
if(nowDownload<allDownload){
    QString fileName=download_list[nowDownload].getName();
    file = new QFile(fileName);
    if(!file->open(QIODevice::WriteOnly))
    {
        qDebug()<<"file open error";
        delete file;
        file = 0;
        return ;
    }
    nowDownload+=1;
    startRequest(urList.at(nowDownload-1));
}
}
void Widget::on_listWidget_currentRowChanged(int currentRow)
{
    qDebug()<<currentRow;
    for (int i=0;i<allDownload;i++) {
        download_list[i].choose(false);
    }
    download_list[currentRow].choose(true);
}
//菜单切换逻辑
void Widget::on_menu_btn_main_clicked() //主页
{
    ui->menu_btn_main->setStyleSheet("color:#FFFFFF");
    ui->menu_bg_main->setStyleSheet("background-color:#0081FF;border-radius:8");//蓝色
    //取消其他样式
    ui->menu_bg_dev->setStyleSheet("");
    ui->menu_bg_chat->setStyleSheet("");
    ui->menu_bg_game->setStyleSheet("");
    ui->menu_bg_read->setStyleSheet("");
    ui->menu_bg_music->setStyleSheet("");
    ui->menu_bg_other->setStyleSheet("");
    ui->menu_bg_photo->setStyleSheet("");
    ui->menu_bg_video->setStyleSheet("");
    ui->menu_bg_office->setStyleSheet("");
    ui->menu_bg_system->setStyleSheet("");
    ui->menu_bg_network->setStyleSheet("");
    ui->menu_bg_download->setStyleSheet("");
    ui->menu_btn_dev->setStyleSheet("");
    ui->menu_btn_chat->setStyleSheet("");
    ui->menu_btn_game->setStyleSheet("");
    ui->menu_btn_read->setStyleSheet("");
    ui->menu_btn_music->setStyleSheet("");
    ui->menu_btn_other->setStyleSheet("");
    ui->menu_btn_photo->setStyleSheet("");
    ui->menu_btn_video->setStyleSheet("");
    ui->menu_btn_office->setStyleSheet("");
    ui->menu_btn_system->setStyleSheet("");
    ui->menu_btn_network->setStyleSheet("");
    ui->menu_btn_download->setStyleSheet("");
    ui->menu_btn_theme->setStyleSheet("");
    ui->menu_bg_theme->setStyleSheet("");
    ui->stackedWidget->setCurrentIndex(0);
    ui->webView->setUrl(QUrl(URL_MAIN));
}
void Widget::on_menu_btn_network_clicked() //网络应用
{
    ui->menu_btn_network->setStyleSheet("color:#FFFFFF");
    ui->menu_bg_network->setStyleSheet("background-color:#0081FF;border-radius:8");//蓝色
    //取消其他样式
    ui->menu_bg_dev->setStyleSheet("");
    ui->menu_bg_chat->setStyleSheet("");
    ui->menu_bg_game->setStyleSheet("");
    ui->menu_bg_read->setStyleSheet("");
    ui->menu_bg_music->setStyleSheet("");
    ui->menu_bg_other->setStyleSheet("");
    ui->menu_bg_photo->setStyleSheet("");
    ui->menu_bg_video->setStyleSheet("");
    ui->menu_bg_office->setStyleSheet("");
    ui->menu_bg_system->setStyleSheet("");
    ui->menu_bg_main->setStyleSheet("");
    ui->menu_bg_download->setStyleSheet("");
    ui->menu_btn_dev->setStyleSheet("");
    ui->menu_btn_chat->setStyleSheet("");
    ui->menu_btn_game->setStyleSheet("");
    ui->menu_btn_read->setStyleSheet("");
    ui->menu_btn_music->setStyleSheet("");
    ui->menu_btn_other->setStyleSheet("");
    ui->menu_btn_photo->setStyleSheet("");
    ui->menu_btn_video->setStyleSheet("");
    ui->menu_btn_office->setStyleSheet("");
    ui->menu_btn_system->setStyleSheet("");
    ui->menu_btn_main->setStyleSheet("");
    ui->menu_btn_download->setStyleSheet("");
    ui->menu_btn_theme->setStyleSheet("");
    ui->menu_bg_theme->setStyleSheet("");
    ui->stackedWidget->setCurrentIndex(0);
    ui->webView->setUrl(QUrl(URL_NETWORK));
}
void Widget::on_menu_btn_chat_clicked()//社交沟通
{
    ui->menu_btn_chat->setStyleSheet("color:#FFFFFF");
    ui->menu_bg_chat->setStyleSheet("background-color:#0081FF;border-radius:8");//蓝色
    //取消其他样式
    ui->menu_bg_dev->setStyleSheet("");
    ui->menu_bg_network->setStyleSheet("");
    ui->menu_bg_game->setStyleSheet("");
    ui->menu_bg_read->setStyleSheet("");
    ui->menu_bg_music->setStyleSheet("");
    ui->menu_bg_other->setStyleSheet("");
    ui->menu_bg_photo->setStyleSheet("");
    ui->menu_bg_video->setStyleSheet("");
    ui->menu_bg_office->setStyleSheet("");
    ui->menu_bg_system->setStyleSheet("");
    ui->menu_bg_main->setStyleSheet("");
    ui->menu_bg_download->setStyleSheet("");
    ui->menu_btn_dev->setStyleSheet("");
    ui->menu_btn_network->setStyleSheet("");
    ui->menu_btn_game->setStyleSheet("");
    ui->menu_btn_read->setStyleSheet("");
    ui->menu_btn_music->setStyleSheet("");
    ui->menu_btn_other->setStyleSheet("");
    ui->menu_btn_photo->setStyleSheet("");
    ui->menu_btn_video->setStyleSheet("");
    ui->menu_btn_office->setStyleSheet("");
    ui->menu_btn_system->setStyleSheet("");
    ui->menu_btn_main->setStyleSheet("");
    ui->menu_btn_download->setStyleSheet("");
    ui->menu_btn_theme->setStyleSheet("");
    ui->menu_bg_theme->setStyleSheet("");
     ui->stackedWidget->setCurrentIndex(0);
     ui->webView->setUrl(QUrl(URL_CHAT));
}
void Widget::on_menu_btn_music_clicked()//音乐欣赏
{
    ui->menu_btn_music->setStyleSheet("color:#FFFFFF");
    ui->menu_bg_music->setStyleSheet("background-color:#0081FF;border-radius:8");//蓝色
    //取消其他样式
    ui->menu_bg_dev->setStyleSheet("");
    ui->menu_bg_network->setStyleSheet("");
    ui->menu_bg_game->setStyleSheet("");
    ui->menu_bg_read->setStyleSheet("");
    ui->menu_bg_chat->setStyleSheet("");
    ui->menu_bg_other->setStyleSheet("");
    ui->menu_bg_photo->setStyleSheet("");
    ui->menu_bg_video->setStyleSheet("");
    ui->menu_bg_office->setStyleSheet("");
    ui->menu_bg_system->setStyleSheet("");
    ui->menu_bg_main->setStyleSheet("");
    ui->menu_bg_download->setStyleSheet("");
    ui->menu_btn_dev->setStyleSheet("");
    ui->menu_btn_network->setStyleSheet("");
    ui->menu_btn_game->setStyleSheet("");
    ui->menu_btn_read->setStyleSheet("");
    ui->menu_btn_chat->setStyleSheet("");
    ui->menu_btn_other->setStyleSheet("");
    ui->menu_btn_photo->setStyleSheet("");
    ui->menu_btn_video->setStyleSheet("");
    ui->menu_btn_office->setStyleSheet("");
    ui->menu_btn_system->setStyleSheet("");
    ui->menu_btn_main->setStyleSheet("");
    ui->menu_btn_download->setStyleSheet("");
    ui->menu_btn_theme->setStyleSheet("");
    ui->menu_bg_theme->setStyleSheet("");//蓝色
     ui->stackedWidget->setCurrentIndex(0);
     ui->webView->setUrl(QUrl(URL_MUSIC));
}
void Widget::on_menu_btn_video_clicked()//视频播放
{
    ui->menu_btn_video->setStyleSheet("color:#FFFFFF");
    ui->menu_bg_video->setStyleSheet("background-color:#0081FF;border-radius:8");//蓝色
    //取消其他样式
    ui->menu_bg_dev->setStyleSheet("");
    ui->menu_bg_network->setStyleSheet("");
    ui->menu_bg_game->setStyleSheet("");
    ui->menu_bg_read->setStyleSheet("");
    ui->menu_bg_chat->setStyleSheet("");
    ui->menu_bg_other->setStyleSheet("");
    ui->menu_bg_photo->setStyleSheet("");
    ui->menu_bg_music->setStyleSheet("");
    ui->menu_bg_office->setStyleSheet("");
    ui->menu_bg_system->setStyleSheet("");
    ui->menu_bg_main->setStyleSheet("");
    ui->menu_bg_download->setStyleSheet("");
    ui->menu_btn_dev->setStyleSheet("");
    ui->menu_btn_network->setStyleSheet("");
    ui->menu_btn_game->setStyleSheet("");
    ui->menu_btn_read->setStyleSheet("");
    ui->menu_btn_chat->setStyleSheet("");
    ui->menu_btn_other->setStyleSheet("");
    ui->menu_btn_photo->setStyleSheet("");
    ui->menu_btn_music->setStyleSheet("");
    ui->menu_btn_office->setStyleSheet("");
    ui->menu_btn_system->setStyleSheet("");
    ui->menu_btn_main->setStyleSheet("");
    ui->menu_btn_download->setStyleSheet("");
    ui->menu_btn_theme->setStyleSheet("");
    ui->menu_bg_theme->setStyleSheet("");//蓝色
     ui->stackedWidget->setCurrentIndex(0);
     ui->webView->setUrl(QUrl(URL_VIDEO));
}
void Widget::on_menu_btn_photo_clicked()//图形图像
{
    ui->menu_btn_photo->setStyleSheet("color:#FFFFFF");
    ui->menu_bg_photo->setStyleSheet("background-color:#0081FF;border-radius:8");//蓝色
    //取消其他样式
    ui->menu_bg_dev->setStyleSheet("");
    ui->menu_bg_network->setStyleSheet("");
    ui->menu_bg_game->setStyleSheet("");
    ui->menu_bg_read->setStyleSheet("");
    ui->menu_bg_chat->setStyleSheet("");
    ui->menu_bg_other->setStyleSheet("");
    ui->menu_bg_video->setStyleSheet("");
    ui->menu_bg_music->setStyleSheet("");
    ui->menu_bg_office->setStyleSheet("");
    ui->menu_bg_system->setStyleSheet("");
    ui->menu_bg_main->setStyleSheet("");
    ui->menu_bg_download->setStyleSheet("");
    ui->menu_btn_dev->setStyleSheet("");
    ui->menu_btn_network->setStyleSheet("");
    ui->menu_btn_game->setStyleSheet("");
    ui->menu_btn_read->setStyleSheet("");
    ui->menu_btn_chat->setStyleSheet("");
    ui->menu_btn_other->setStyleSheet("");
    ui->menu_btn_video->setStyleSheet("");
    ui->menu_btn_music->setStyleSheet("");
    ui->menu_btn_office->setStyleSheet("");
    ui->menu_btn_system->setStyleSheet("");
    ui->menu_btn_main->setStyleSheet("");
    ui->menu_btn_download->setStyleSheet("");
    ui->menu_btn_theme->setStyleSheet("");
    ui->menu_bg_theme->setStyleSheet("");//蓝色
     ui->stackedWidget->setCurrentIndex(0);
     ui->webView->setUrl(QUrl(URL_PHOTO));
}
void Widget::on_menu_btn_game_clicked()//游戏娱乐
{
    ui->menu_btn_game->setStyleSheet("color:#FFFFFF");
    ui->menu_bg_game->setStyleSheet("background-color:#0081FF;border-radius:8");//蓝色
    //取消其他样式
    ui->menu_bg_dev->setStyleSheet("");
    ui->menu_bg_network->setStyleSheet("");
    ui->menu_bg_photo->setStyleSheet("");
    ui->menu_bg_read->setStyleSheet("");
    ui->menu_bg_chat->setStyleSheet("");
    ui->menu_bg_other->setStyleSheet("");
    ui->menu_bg_video->setStyleSheet("");
    ui->menu_bg_music->setStyleSheet("");
    ui->menu_bg_office->setStyleSheet("");
    ui->menu_bg_system->setStyleSheet("");
    ui->menu_bg_main->setStyleSheet("");
    ui->menu_bg_download->setStyleSheet("");
    ui->menu_btn_dev->setStyleSheet("");
    ui->menu_btn_network->setStyleSheet("");
    ui->menu_btn_photo->setStyleSheet("");
    ui->menu_btn_read->setStyleSheet("");
    ui->menu_btn_chat->setStyleSheet("");
    ui->menu_btn_other->setStyleSheet("");
    ui->menu_btn_video->setStyleSheet("");
    ui->menu_btn_music->setStyleSheet("");
    ui->menu_btn_office->setStyleSheet("");
    ui->menu_btn_system->setStyleSheet("");
    ui->menu_btn_main->setStyleSheet("");
    ui->menu_btn_download->setStyleSheet("");
    ui->menu_btn_theme->setStyleSheet("");
    ui->menu_bg_theme->setStyleSheet("");
     ui->stackedWidget->setCurrentIndex(0);
     ui->webView->setUrl(QUrl(URL_GAME));
}
void Widget::on_menu_btn_office_clicked()//办公学习
{
    ui->menu_btn_office->setStyleSheet("color:#FFFFFF");
    ui->menu_bg_office->setStyleSheet("background-color:#0081FF;border-radius:8");//蓝色
    //取消其他样式
    ui->menu_bg_dev->setStyleSheet("");
    ui->menu_bg_network->setStyleSheet("");
    ui->menu_bg_photo->setStyleSheet("");
    ui->menu_bg_read->setStyleSheet("");
    ui->menu_bg_chat->setStyleSheet("");
    ui->menu_bg_other->setStyleSheet("");
    ui->menu_bg_video->setStyleSheet("");
    ui->menu_bg_music->setStyleSheet("");
    ui->menu_bg_game->setStyleSheet("");
    ui->menu_bg_system->setStyleSheet("");
    ui->menu_bg_main->setStyleSheet("");
    ui->menu_bg_download->setStyleSheet("");
    ui->menu_btn_dev->setStyleSheet("");
    ui->menu_btn_network->setStyleSheet("");
    ui->menu_btn_photo->setStyleSheet("");
    ui->menu_btn_read->setStyleSheet("");
    ui->menu_btn_chat->setStyleSheet("");
    ui->menu_btn_other->setStyleSheet("");
    ui->menu_btn_video->setStyleSheet("");
    ui->menu_btn_music->setStyleSheet("");
    ui->menu_btn_game->setStyleSheet("");
    ui->menu_btn_system->setStyleSheet("");
    ui->menu_btn_main->setStyleSheet("");
    ui->menu_btn_download->setStyleSheet("");
    ui->menu_btn_theme->setStyleSheet("");
    ui->menu_bg_theme->setStyleSheet("");//蓝色
     ui->stackedWidget->setCurrentIndex(0);
     ui->webView->setUrl(QUrl(URL_OFFICE));
}
void Widget::on_menu_btn_read_clicked()//阅读翻译
{
    ui->menu_btn_read->setStyleSheet("color:#FFFFFF");
    ui->menu_bg_read->setStyleSheet("background-color:#0081FF;border-radius:8");//蓝色
    //取消其他样式
    ui->menu_bg_dev->setStyleSheet("");
    ui->menu_bg_network->setStyleSheet("");
    ui->menu_bg_photo->setStyleSheet("");
    ui->menu_bg_office->setStyleSheet("");
    ui->menu_bg_chat->setStyleSheet("");
    ui->menu_bg_other->setStyleSheet("");
    ui->menu_bg_video->setStyleSheet("");
    ui->menu_bg_music->setStyleSheet("");
    ui->menu_bg_game->setStyleSheet("");
    ui->menu_bg_system->setStyleSheet("");
    ui->menu_bg_main->setStyleSheet("");
    ui->menu_bg_download->setStyleSheet("");
    ui->menu_btn_dev->setStyleSheet("");
    ui->menu_btn_network->setStyleSheet("");
    ui->menu_btn_photo->setStyleSheet("");
    ui->menu_btn_office->setStyleSheet("");
    ui->menu_btn_chat->setStyleSheet("");
    ui->menu_btn_other->setStyleSheet("");
    ui->menu_btn_video->setStyleSheet("");
    ui->menu_btn_music->setStyleSheet("");
    ui->menu_btn_game->setStyleSheet("");
    ui->menu_btn_system->setStyleSheet("");
    ui->menu_btn_main->setStyleSheet("");
    ui->menu_btn_download->setStyleSheet("");
    ui->menu_btn_theme->setStyleSheet("");
    ui->menu_bg_theme->setStyleSheet("");//蓝色
     ui->stackedWidget->setCurrentIndex(0);
     ui->webView->setUrl(QUrl(URL_READ));
}
void Widget::on_menu_btn_dev_clicked()//编程开发
{
    ui->menu_btn_dev->setStyleSheet("color:#FFFFFF");
    ui->menu_bg_dev->setStyleSheet("background-color:#0081FF;border-radius:8");//蓝色
    //取消其他样式
    ui->menu_bg_read->setStyleSheet("");
    ui->menu_bg_network->setStyleSheet("");
    ui->menu_bg_photo->setStyleSheet("");
    ui->menu_bg_office->setStyleSheet("");
    ui->menu_bg_chat->setStyleSheet("");
    ui->menu_bg_other->setStyleSheet("");
    ui->menu_bg_video->setStyleSheet("");
    ui->menu_bg_music->setStyleSheet("");
    ui->menu_bg_game->setStyleSheet("");
    ui->menu_bg_system->setStyleSheet("");
    ui->menu_bg_main->setStyleSheet("");
    ui->menu_bg_download->setStyleSheet("");
    ui->menu_btn_read->setStyleSheet("");
    ui->menu_btn_network->setStyleSheet("");
    ui->menu_btn_photo->setStyleSheet("");
    ui->menu_btn_office->setStyleSheet("");
    ui->menu_btn_chat->setStyleSheet("");
    ui->menu_btn_other->setStyleSheet("");
    ui->menu_btn_video->setStyleSheet("");
    ui->menu_btn_music->setStyleSheet("");
    ui->menu_btn_game->setStyleSheet("");
    ui->menu_btn_system->setStyleSheet("");
    ui->menu_btn_main->setStyleSheet("");
    ui->menu_btn_download->setStyleSheet("");
    ui->menu_btn_theme->setStyleSheet("");
    ui->menu_bg_theme->setStyleSheet("");//蓝色
     ui->stackedWidget->setCurrentIndex(0);
     ui->webView->setUrl(QUrl(URL_DEV));
}
void Widget::on_menu_btn_system_clicked()//系统管理
{
    ui->menu_btn_system->setStyleSheet("color:#FFFFFF");
    ui->menu_bg_system->setStyleSheet("background-color:#0081FF;border-radius:8");//蓝色
    //取消其他样式
    ui->menu_bg_read->setStyleSheet("");
    ui->menu_bg_network->setStyleSheet("");
    ui->menu_bg_photo->setStyleSheet("");
    ui->menu_bg_office->setStyleSheet("");
    ui->menu_bg_chat->setStyleSheet("");
    ui->menu_bg_other->setStyleSheet("");
    ui->menu_bg_video->setStyleSheet("");
    ui->menu_bg_music->setStyleSheet("");
    ui->menu_bg_game->setStyleSheet("");
    ui->menu_bg_dev->setStyleSheet("");
    ui->menu_bg_main->setStyleSheet("");
    ui->menu_bg_download->setStyleSheet("");
    ui->menu_btn_read->setStyleSheet("");
    ui->menu_btn_network->setStyleSheet("");
    ui->menu_btn_photo->setStyleSheet("");
    ui->menu_btn_office->setStyleSheet("");
    ui->menu_btn_chat->setStyleSheet("");
    ui->menu_btn_other->setStyleSheet("");
    ui->menu_btn_video->setStyleSheet("");
    ui->menu_btn_music->setStyleSheet("");
    ui->menu_btn_game->setStyleSheet("");
    ui->menu_btn_dev->setStyleSheet("");
    ui->menu_btn_main->setStyleSheet("");
    ui->menu_btn_download->setStyleSheet("");
    ui->menu_btn_theme->setStyleSheet("");
    ui->menu_bg_theme->setStyleSheet("");//蓝色
     ui->stackedWidget->setCurrentIndex(0);
     ui->webView->setUrl(QUrl(URL_SYSTEM));
}
void Widget::on_menu_btn_other_clicked()//其他软件
{
    ui->menu_btn_other->setStyleSheet("color:#FFFFFF");
    ui->menu_bg_other->setStyleSheet("background-color:#0081FF;border-radius:8");//蓝色
    //取消其他样式
    ui->menu_bg_read->setStyleSheet("");
    ui->menu_bg_network->setStyleSheet("");
    ui->menu_bg_photo->setStyleSheet("");
    ui->menu_bg_office->setStyleSheet("");
    ui->menu_bg_chat->setStyleSheet("");
    ui->menu_bg_system->setStyleSheet("");
    ui->menu_bg_video->setStyleSheet("");
    ui->menu_bg_music->setStyleSheet("");
    ui->menu_bg_game->setStyleSheet("");
    ui->menu_bg_dev->setStyleSheet("");
    ui->menu_bg_main->setStyleSheet("");
    ui->menu_bg_download->setStyleSheet("");
    ui->menu_btn_read->setStyleSheet("");
    ui->menu_btn_network->setStyleSheet("");
    ui->menu_btn_photo->setStyleSheet("");
    ui->menu_btn_office->setStyleSheet("");
    ui->menu_btn_chat->setStyleSheet("");
    ui->menu_btn_system->setStyleSheet("");
    ui->menu_btn_video->setStyleSheet("");
    ui->menu_btn_music->setStyleSheet("");
    ui->menu_btn_game->setStyleSheet("");
    ui->menu_btn_dev->setStyleSheet("");
    ui->menu_btn_main->setStyleSheet("");
    ui->menu_btn_download->setStyleSheet("");
    ui->menu_btn_theme->setStyleSheet("");
    ui->menu_bg_theme->setStyleSheet("");//蓝色
     ui->stackedWidget->setCurrentIndex(0);
     ui->webView->setUrl(QUrl(URL_OTHER));
}
void Widget::on_menu_btn_download_clicked()
{
    ui->menu_btn_download->setStyleSheet("color:#FFFFFF");
    ui->menu_bg_download->setStyleSheet("background-color:#0081FF;border-radius:8");//蓝色
    //取消其他样式
    ui->menu_bg_dev->setStyleSheet("");
    ui->menu_bg_chat->setStyleSheet("");
    ui->menu_bg_game->setStyleSheet("");
    ui->menu_bg_read->setStyleSheet("");
    ui->menu_bg_music->setStyleSheet("");
    ui->menu_bg_other->setStyleSheet("");
    ui->menu_bg_photo->setStyleSheet("");
    ui->menu_bg_video->setStyleSheet("");
    ui->menu_bg_office->setStyleSheet("");
    ui->menu_bg_system->setStyleSheet("");
    ui->menu_bg_main->setStyleSheet("");
    ui->menu_bg_network->setStyleSheet("");
    ui->menu_btn_dev->setStyleSheet("");
    ui->menu_btn_chat->setStyleSheet("");
    ui->menu_btn_game->setStyleSheet("");
    ui->menu_btn_read->setStyleSheet("");
    ui->menu_btn_music->setStyleSheet("");
    ui->menu_btn_other->setStyleSheet("");
    ui->menu_btn_photo->setStyleSheet("");
    ui->menu_btn_video->setStyleSheet("");
    ui->menu_btn_office->setStyleSheet("");
    ui->menu_btn_system->setStyleSheet("");
    ui->menu_btn_main->setStyleSheet("");
    ui->menu_btn_network->setStyleSheet("");
    ui->menu_btn_theme->setStyleSheet("");
    ui->menu_bg_theme->setStyleSheet("");//蓝色
    ui->stackedWidget->setCurrentIndex(1);
}
void Widget::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Widget::on_webView_loadStarted()
{
    ui->label_show->setText("正在加载，请稍候");
    ui->label_show->show();
}

void Widget::on_webView_loadFinished(bool arg1)
{
    ui->label_show->setText("");
    ui->label_show->hide();
}

void Widget::on_menu_btn_theme_clicked()
{
    ui->menu_btn_theme->setStyleSheet("color:#FFFFFF");
    ui->menu_bg_theme->setStyleSheet("background-color:#0081FF;border-radius:8");//蓝色
    //取消其他样式
    ui->menu_bg_dev->setStyleSheet("");
    ui->menu_bg_chat->setStyleSheet("");
    ui->menu_bg_game->setStyleSheet("");
    ui->menu_bg_read->setStyleSheet("");
    ui->menu_bg_music->setStyleSheet("");
    ui->menu_bg_other->setStyleSheet("");
    ui->menu_bg_photo->setStyleSheet("");
    ui->menu_bg_video->setStyleSheet("");
    ui->menu_bg_office->setStyleSheet("");
    ui->menu_bg_system->setStyleSheet("");
    ui->menu_bg_main->setStyleSheet("");
    ui->menu_bg_network->setStyleSheet("");
    ui->menu_btn_dev->setStyleSheet("");
    ui->menu_btn_chat->setStyleSheet("");
    ui->menu_btn_game->setStyleSheet("");
    ui->menu_btn_read->setStyleSheet("");
    ui->menu_btn_music->setStyleSheet("");
    ui->menu_btn_other->setStyleSheet("");
    ui->menu_btn_photo->setStyleSheet("");
    ui->menu_btn_video->setStyleSheet("");
    ui->menu_btn_office->setStyleSheet("");
    ui->menu_btn_system->setStyleSheet("");
    ui->menu_btn_main->setStyleSheet("");
    ui->menu_btn_network->setStyleSheet("");
    ui->menu_bg_download->setStyleSheet("");
    ui->menu_btn_download->setStyleSheet("");
    ui->stackedWidget->setCurrentIndex(0);
    ui->webView->setUrl(QUrl(URL_THEME));
}
