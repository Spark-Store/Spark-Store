#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QFileInfo>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QVBoxLayout>
#include <fstream>
#include <QDir>
#include <QProcess>
#include <QJsonDocument>
#include <QFile>
#include <QJsonObject>
#include <QByteArray>
#include <QPixmap>
#include <QtConcurrent> //并发
#include <QSettings>
#include <QIcon>
#include <QWebFrame>
#include <QGraphicsOpacityEffect>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    QString serverUrl;
    std::fstream server;

    ui->setupUi(this);
    ui->webView->page()->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);//用来激活接受linkClicked信号
    ui->webView->page()->settings()->setAttribute(QWebSettings::JavascriptEnabled,true);
    ui->stackedWidget->setCurrentIndex(0);
    ui->listWidget->hide();
    ui->label_setting1->hide();
    manager = new QNetworkAccessManager(this);
    left_list[0]=ui->menu_btn_main;left_menu_bg[0]=ui->menu_bg_main;
    left_list[1]=ui->menu_btn_network;left_menu_bg[1]=ui->menu_bg_network;
    left_list[2]=ui->menu_btn_chat;left_menu_bg[2]=ui->menu_bg_chat;
    left_list[3]=ui->menu_btn_music;left_menu_bg[3]=ui->menu_bg_music;
    left_list[4]=ui->menu_btn_video;left_menu_bg[4]=ui->menu_bg_video;
    left_list[5]=ui->menu_btn_photo;left_menu_bg[5]=ui->menu_bg_photo;
    left_list[6]=ui->menu_btn_game;left_menu_bg[6]=ui->menu_bg_game;
    left_list[7]=ui->menu_btn_office;left_menu_bg[7]=ui->menu_bg_office;
    left_list[8]=ui->menu_btn_read;left_menu_bg[8]=ui->menu_bg_read;
    left_list[9]=ui->menu_btn_dev;left_menu_bg[9]=ui->menu_bg_dev;
    left_list[10]=ui->menu_btn_system;left_menu_bg[10]=ui->menu_bg_system;
    left_list[11]=ui->menu_btn_other;left_menu_bg[11]=ui->menu_bg_other;
    left_list[12]=ui->menu_btn_theme;left_menu_bg[12]=ui->menu_bg_theme;
    left_list[13]=ui->menu_btn_download;left_menu_bg[13]=ui->menu_bg_download;
    left_list[14]=ui->menu_btn_settings;left_menu_bg[14]=ui->menu_bg_settings;
    server.open(QDir::homePath().toUtf8()+"/.config/deepin-community-store/server.list",std::ios::in);
//    system("mkdir /etc/deepin-community-store/");
//    server.open("/etc/deepin-community-store/server.list",std::ios::in);
    std::string lineTmp;

    if(server){
        while (getline(server,lineTmp)) {
            ui->comboBox_server->addItem(QString::fromStdString(lineTmp));
        }
    }else {
        ui->comboBox_server->addItem("http://dcstore.shenmo.tech/");
    }

    QSettings readConfig(QDir::homePath()+"/.config/deepin-community-store/config.ini",QSettings::IniFormat);
    if(readConfig.value("server/choose").toString()!=""){
        ui->comboBox_server->setCurrentText(readConfig.value("server/choose").toString());
        serverUrl=readConfig.value("server/choose").toString();
    }else {
        serverUrl="http://dcstore.shenmo.tech/";
    }
    configCanSeve=true;
    qDebug()<<serverUrl;
    menuUrl[0]=serverUrl + "store/#/";
//    menuUrl[0]="http://127.0.0.1:8000/#/relations";
    menuUrl[1]=serverUrl + "store/#/network/";
    menuUrl[2]=serverUrl + "store/#/relations";
    menuUrl[3]=serverUrl + "store/#/musicandsound";
    menuUrl[4]=serverUrl + "store/#/videos";
    menuUrl[5]=serverUrl + "store/#/photos";
    menuUrl[6]=serverUrl + "store/#/games/";
    menuUrl[7]=serverUrl + "store/#/office";
    menuUrl[8]=serverUrl + "store/#/reading/";
    menuUrl[9]=serverUrl + "store/#/programming";
    menuUrl[10]=serverUrl + "store/#/tools/";
    menuUrl[11]=serverUrl + "store/#/others/";
    menuUrl[12]=serverUrl + "store/#/themes";
    ui->webView->setUrl(menuUrl[0]);
    for (int i =0; i<15;i++){
        download_list[i].num=i;
    }
    QGraphicsOpacityEffect *opacityEffect_1=new QGraphicsOpacityEffect;
    QGraphicsOpacityEffect *opacityEffect_2=new QGraphicsOpacityEffect;
    ui->line1_widget->setStyleSheet("background-color:#808080");
    ui->line2_widget->setStyleSheet("background-color:#808080");
    opacityEffect_1->setOpacity(0.2);
    opacityEffect_2->setOpacity(0.2);
    ui->line1_widget->setGraphicsEffect(opacityEffect_1);
    ui->line2_widget->setGraphicsEffect(opacityEffect_2);
    connect(ui->webView->page(),SIGNAL(javaScriptWindowObjectCleared()),this,SLOT([=](){qDebug()<<" ";}));
    download_speed.setInterval(1000);
    download_speed.start();
    connect(&download_speed,&QTimer::timeout,[=](){
        if(isdownload){
            size1=download_size;
            QString theSpeed;
            double bspeed;
            bspeed=size1-size2;
            if(bspeed<1024){
                theSpeed=QString::number(bspeed)+"B";
            }else if (bspeed<(1024*1024)) {
                theSpeed=QString::number(0.01*int(100*(bspeed/1024)))+"KB";
            }else if (bspeed<(1024*1024*1024)) {
                theSpeed=QString::number(0.01*int(100*(bspeed/(1024*1024))))+"MB";
            }else {
                theSpeed=QString::number(0.01*int(100*(bspeed/(1024*1024*1024))))+"GB";
            }
            download_list[nowDownload-1].setSpeed(theSpeed);
            size2=download_size;
        }
    });
    chooseLeftMenu(0);
    QFile aptserver("/etc/apt/sources.list.d/sparkstore.list");
    aptserver.open(QIODevice::ReadOnly);
    if(aptserver.isOpen()){
        ui->label_aptserver->setText(aptserver.readAll());
    }else {
        ui->label_aptserver->setText("不存在");
    }
    aptserver.close();
    ui->pushButton_5->hide();

}

Widget::~Widget()
{
    delete ui;
}
void Widget::on_webView_loadStarted()
{


    QUrl arg1=ui->webView->page()->mainFrame()->requestedUrl().toString();
    //判断，如果末尾是/就直接访问，如果是app.json就打开详情页
    if(arg1.path().right(8)=="app.json"){
        load.cancel();//打开并发加载线程前关闭正在执行的线程
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
        ui->pushButton->setEnabled(false);
        ui->stackedWidget->setCurrentIndex(2);
        load.cancel();//打开并发加载线程前关闭正在执行的线程
        load = QtConcurrent::run([=](){
            loadappinfo(arg1);
        });
    }
}
void Widget::loadappinfo(QUrl arg1)
{
    ui->pushButton_5->hide();


    ui->label_show->setText("正在加载，请稍候");
    ui->label_show->show();
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
        //将路径转化为相应源的下载路径
        urladdress=arg1.toString().left(arg1.toString().length()-8);
        QStringList downloadurl=urladdress.split("/");
        urladdress=ui->comboBox_server->currentText();
        for (int i=3;i<downloadurl.size();i++) {
            urladdress+="/"+downloadurl[i];
        }
        //路径转化完成
        QJsonObject json= QJsonDocument::fromJson(json_array).object();
        appName = json["Name"].toString();
        url=urladdress + json["Filename"].toString();
        ui->label_appname->setText(appName);
        system("rm -r *.png");
        ui->label_show->show();
        //软件信息加载
        QString info;
        info="包名： "+json["Pkgname"].toString()+"\n";
        info+="版本号： "+json["Version"].toString()+"\n";
        if(json["Author"].toString()!="" && json["Author"].toString()!=" "){
            info+="作者： "+json["Author"].toString()+"\n";
        }

        if(json["Website"].toString()!="" && json["Website"].toString()!=" "){
            info+="官网： "+json["Website"].toString()+"\n";
        }
        info+="投稿者： "+json["Contributor"].toString()+"\n";
        info+="更新时间： "+json["Update"].toString()+"\n";
        info+="大小： "+json["Size"].toString()+"\n";
        ui->label_info->setText(info);
        ui->label_more->setText(json["More"].toString());
        QProcess isInstall;
        pkgName=json["Pkgname"].toString();
        isInstall.start("dpkg -s "+json["Pkgname"].toString());
        isInstall.waitForFinished();
        int error=QString::fromStdString(isInstall.readAllStandardError().toStdString()).length();
        if(error==0){
            ui->pushButton->setText("重新安装");
            ui->pushButton_5->show();

        }else {
            ui->pushButton->setText("安装");
        }
        //图标加载
        get_json.start("wget -O icon.png "+urladdress+"icon.png");
        get_json.waitForFinished();
        QPixmap appicon;
        qDebug()<<appicon.load("icon.png");
        ui->label_appicon->setPixmap(appicon);
        ui->pushButton->setEnabled(true);
        //截图展示加载
        get_json.start("wget "+urladdress+"screen_1.png");
        get_json.waitForFinished();
        if(screen[0].load("screen_1.png")){
            ui->screen_1->show();
            ui->screen_1->setPixmap(screen[0]);
            ui->screen_1->setScaledContents(true);
            ui->screen_2->hide();
            ui->screen_3->hide();
            ui->screen_4->hide();
            ui->screen_5->hide();

        }
        get_json.start("wget "+urladdress+"screen_2.png");
        get_json.waitForFinished();
        if(screen[1].load("screen_2.png")){
            ui->screen_2->show();
            ui->screen_2->setPixmap(screen[1]);
            ui->screen_2->setScaledContents(true);
            ui->screen_3->hide();
            ui->screen_4->hide();
            ui->screen_5->hide();
        }
        get_json.start("wget "+urladdress+"screen_3.png");
        get_json.waitForFinished();
        if(screen[2].load("screen_3.png")){
            ui->screen_3->show();
            ui->screen_3->setPixmap(screen[2]);
            ui->screen_3->setScaledContents(true);
            ui->screen_4->hide();
            ui->screen_5->hide();
        }
        get_json.start("wget "+urladdress+"screen_4.png");
        get_json.waitForFinished();
        if(screen[3].load("screen_4.png")){
            ui->screen_4->show();
            ui->screen_4->setPixmap(screen[3]);
            ui->screen_4->setScaledContents(true);
            ui->screen_5->hide();
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

void Widget::chooseLeftMenu(int index)
{

    nowMenu=index;
    for (int i=0;i<15;i++) {
        left_list[i]->setStyleSheet("");
        left_list[i]->setFont(QFont("",11));
        left_menu_bg[i]->setStyleSheet("");
    }
    left_list[index]->setStyleSheet("color:#FFFFFF");
    left_menu_bg[index]->setStyleSheet("background-color:#0081FF;border-radius:8");
    if(index<=12){
        ui->webView->setUrl(menuUrl[index]);
        ui->stackedWidget->setCurrentIndex(0);
    }else if (index==13) {
        ui->stackedWidget->setCurrentIndex(1);
    }else if (index==14) {
        ui->stackedWidget->setCurrentIndex(3);
    }

}
void Widget::on_pushButton_clicked()
{
    on_menu_btn_download_clicked();
    allDownload+=1;
    QFileInfo info(url.path());
    QString fileName(info.fileName());  //获取文件名
    download_list[allDownload-1].pkgName=pkgName;
    if(fileName.isEmpty())
    {
        fileName = "index.html";
    }

    download_list[allDownload-1].setParent(ui->listWidget);
    QListWidgetItem *item=new QListWidgetItem(ui->listWidget);
    item->setSizeHint(download_list[allDownload-1].size());
    ui->listWidget->setItemWidget(item,&download_list[allDownload-1]);
    urList.append(url);
    qDebug()<<"下载:"<<url;
    download_list[allDownload-1].setName(appName);
    download_list[allDownload-1].setFileName(fileName);
    QPixmap icon;
    icon.load("icon.png");
    system("cp icon.png icon_"+QString::number(allDownload-1).toUtf8()+".png");
    download_list[allDownload-1].seticon(icon);
    if(!isBusy){
        file = new QFile(fileName);
        if(!file->open(QIODevice::WriteOnly)){
            delete file;
            file = nullptr;
            return ;
        }
        nowDownload+=1;
        startRequest(urList.at(nowDownload-1)); //进行链接请求
    }
    if(ui->pushButton->text()=="重新安装"){
        download_list[allDownload-1].reinstall=true;
    }
}

void Widget::startRequest(QUrl url)
{
    ui->listWidget->show();
    ui->label->hide();
    isBusy=true;
    isdownload=true;
    download_list[allDownload-1].free=false;
    reply = manager->get(QNetworkRequest(url));
    connect(reply,SIGNAL(finished()),this,SLOT(httpFinished()));
    connect(reply,SIGNAL(readyRead()),this,SLOT(httpReadyRead()));
    connect(reply,SIGNAL(downloadProgress(qint64,qint64)),this,SLOT(updateDataReadProgress(qint64,qint64)));

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
    download_list[nowDownload-1].setMax(10000); //最大值
    download_list[nowDownload-1].setValue((bytesRead*10000)/totalBytes); //当前值
    download_size=bytesRead;
    if(download_list[nowDownload-1].close){
        download_list[nowDownload-1].closeDownload();
        httpFinished();

    }
}

void Widget::httpFinished() //完成下载
{

    file->flush();
    file->close();
    reply->deleteLater();
    reply = nullptr;
    delete file;
    file = nullptr;
    isdownload=false;
    isBusy=false;
    download_list[nowDownload-1].readyInstall();
    download_list[nowDownload-1].free=true;
    if(nowDownload<allDownload){
        nowDownload+=1;
        while (download_list[nowDownload-1].close) {
            nowDownload+=1;
        }
        QString fileName=download_list[nowDownload-1].getName();
        file = new QFile(fileName);
        if(!file->open(QIODevice::WriteOnly))
        {
            delete file;
            file = nullptr;
            return ;
        }
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
    chooseLeftMenu(0);
}
void Widget::on_menu_btn_network_clicked() //网络应用
{
    chooseLeftMenu(1);
}
void Widget::on_menu_btn_chat_clicked()//社交沟通
{
    chooseLeftMenu(2);
}
void Widget::on_menu_btn_music_clicked()//音乐欣赏
{
    chooseLeftMenu(3);
}
void Widget::on_menu_btn_video_clicked()//视频播放
{
    chooseLeftMenu(4);
}
void Widget::on_menu_btn_photo_clicked()//图形图像
{
    chooseLeftMenu(5);
}
void Widget::on_menu_btn_game_clicked()//游戏娱乐
{
    chooseLeftMenu(6);
}
void Widget::on_menu_btn_office_clicked()//办公学习
{
    chooseLeftMenu(7);
}
void Widget::on_menu_btn_read_clicked()//阅读翻译
{
    chooseLeftMenu(8);
}
void Widget::on_menu_btn_dev_clicked()//编程开发
{
    chooseLeftMenu(9);
}
void Widget::on_menu_btn_system_clicked()//系统管理
{
    chooseLeftMenu(10);
}
void Widget::on_menu_btn_other_clicked()//其他软件
{
    chooseLeftMenu(11);
}
void Widget::on_menu_btn_theme_clicked()
{
    chooseLeftMenu(12);
}
void Widget::on_menu_btn_download_clicked()
{
    chooseLeftMenu(13);
}
void Widget::on_menu_btn_settings_clicked()
{
    chooseLeftMenu(14);
}
void Widget::on_pushButton_2_clicked()
{
    ui->webView->setUrl(menuUrl[nowMenu]);
    ui->stackedWidget->setCurrentIndex(0);
}



void Widget::on_webView_loadFinished()
{
    if(ui->webView->page()->mainFrame()->requestedUrl().toString().right(5)!=".json"){
        ui->label_show->setText("正在加载，请稍候");
        ui->label_show->hide();
    }
}





void Widget::on_comboBox_server_currentIndexChanged(const QString &arg1)
{
    if(configCanSeve){
        ui->label_setting1->show();
        QSettings *setConfig=new QSettings(QDir::homePath()+"/.config/deepin-community-store/config.ini",QSettings::IniFormat);
        qDebug()<<arg1;
        setConfig->setValue("server/choose",arg1);
    }
}


void Widget::on_pushButton_3_clicked()
{
    QtConcurrent::run([=](){
        ui->pushButton_3->setEnabled(false);
        ui->comboBox_server->clear();
        system("rm "+QDir::homePath().toUtf8()+"/.config/deepin-community-store/server.list");
        system("wget -P "+QDir::homePath().toUtf8()+"/.config/deepin-community-store http://dcstore.shenmo.tech/store/server.list");
        std::fstream server;
        server.open(QDir::homePath().toUtf8()+"/.config/deepin-community-store/server.list",std::ios::in);
        std::string lineTmp;
        if(server){
            while (getline(server,lineTmp)) {
                ui->comboBox_server->addItem(QString::fromStdString(lineTmp));
            }
        }else {
            ui->comboBox_server->addItem("http://dcstore.shenmo.tech/");
        }
        ui->pushButton_3->setEnabled(true);
        ui->comboBox_server->setCurrentIndex(0);
    });
}

void Widget::on_pushButton_4_clicked()
{
    QtConcurrent::run([=](){
       ui->pushButton_4->setEnabled(false);
       ui->label_aptserver->setText("请稍等，正在更新");
       std::fstream sourcesList;
       system("mkdir /tmp/spark-store");
       sourcesList.open("/tmp/spark-store/sparkstore.list",std::ios::out);
       if(sourcesList){
           sourcesList<<"deb [by-hash=force] ";
           sourcesList<<QString::fromUtf8(ui->comboBox_server->currentText().toUtf8()).toStdString();
           sourcesList<<" /";
           std::fstream update;
           update.open("/tmp/spark-store/update.sh",std::ios::out);
           update<<"#!/bin/sh\n";
           update<<"mv /tmp/spark-store/sparkstore.list /etc/apt/sources.list.d/sparkstore.list && apt update";
           update.close();
           system("chmod +x /tmp/spark-store/update.sh");
           QProcess runupdate;
           runupdate.start("pkexec /tmp/spark-store/update.sh");
           runupdate.waitForFinished();
           qDebug()<<runupdate.readAllStandardError();
           QString error=QString::fromStdString(runupdate.readAllStandardError().toStdString());
           QStringList everyError=error.split("\n");
           bool haveError=false;
           for (int i=0;i<everyError.size();i++) {
               qDebug()<<everyError[i].left(2);
               if(everyError[i].left(2)=="E:"){
                   haveError=true;
               }
           }
           if(!haveError){
               ui->label_aptserver->setText("deb [by-hash=force] "+ui->comboBox_server->currentText().toUtf8()+" /");
           }else {
               ui->label_aptserver->setText("更新中发生错误，请在终端使用apt update来查看错误原因");
           }
       }else {
           qDebug()<<"更新源失败";
       }

       ui->pushButton_4->setEnabled(true);
    });
}

void Widget::on_pushButton_5_clicked()
{
    QtConcurrent::run([=](){
        ui->pushButton->setEnabled(false);
        ui->pushButton_5->setEnabled(false);
        QProcess uninstall;
        uninstall.start("pkexec apt purge -y "+pkgName);
        uninstall.waitForFinished();
        ui->pushButton->setEnabled(true);
        ui->pushButton->setText("安装");
        ui->pushButton_5->hide();
        ui->pushButton_5->setEnabled(true);
        updatesEnabled();
        system("notify-send 卸载完成 --icon=spark-store");
    });
}
