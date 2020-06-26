#include "downloadlist.h"
#include "ui_downloadlist.h"
#include <QDebug>
#include <QIcon>
#include <QPixmap>
#include <QtConcurrent>
#include <QProcess>
bool downloadlist::isInstall=false;

downloadlist::downloadlist(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::downloadlist)
{
    ui->setupUi(this);
    ui->pushButton->setEnabled(false);
    ui->progressBar->setValue(0);
    ui->label_filename->hide();
    ui->pushButton->hide();
    ui->label->setStyleSheet("color:#000000");
}

downloadlist::~downloadlist()
{
    delete ui;
}

void downloadlist::setValue(long long value)
{
    ui->progressBar->setValue(value);
    ui->label_2->setText(QString::number((double)value/100)+"%");
    if(ui->label_2->text()=="100%"){
        ui->label_2->setText("已完成，等待安装");
    }
}

void downloadlist::setMax(long long max)
{
    ui->progressBar->setMaximum(max);
}

void downloadlist::setName(QString name)
{
    ui->label->setText(name);
}

QString downloadlist::getName()
{
    return ui->label_filename->text();
}

void downloadlist::readyInstall()
{
    if(!close){
        ui->progressBar->hide();
        ui->pushButton->setEnabled(true);
        ui->pushButton->show();
        ui->pushButton_2->hide();
        system("notify-send \""+ui->label->text().toUtf8()+"下载完成，等待安装\"");
    }
}

void downloadlist::choose(bool isChoosed)
{
    if(isChoosed){
        ui->label->setStyleSheet("color:#FFFFFF");
        ui->label_2->setStyleSheet("color:#FFFFFF");
    }else {
        ui->label->setStyleSheet("color:#000000");
        ui->label_2->setStyleSheet("color:#000000");
    }
}

void downloadlist::setFileName(QString fileName)
{
    ui->label_filename->setText(fileName);
}

void downloadlist::seticon(const QPixmap icon)
{
    ui->label_3->setPixmap(icon);
}

void downloadlist::closeDownload()
{
    on_pushButton_2_clicked();
}

void downloadlist::on_pushButton_clicked()
{
    if(!isInstall){
        isInstall=true;
        ui->pushButton->setEnabled(false);
        ui->label_2->setText("正在安装，请稍候");
        QtConcurrent::run([=](){
            QProcess installer;
            installer.start("pkexec apt install -y /tmp/deepin-community-store/"+ui->label_filename->text().toUtf8());
            installer.waitForFinished();
            QString error=QString::fromStdString(installer.readAllStandardError().toStdString());
            QStringList everyError=error.split("\n");
            bool haveError=false;
            for (int i=0;i<everyError.size();i++) {
                qDebug()<<everyError[i].left(2);
                if(everyError[i].left(2)=="E:"){
                    haveError=true;
                }
            }
            if(!haveError){
                ui->pushButton->hide();
                ui->label_2->setText("安装完成");
            }else {
                ui->pushButton->hide();
                ui->label_2->setText("安装出现错误");
            }
            isInstall=false;
        });
    //    system("x-terminal-emulator -e sudo apt install -y ./"+ui->label_filename->text().toUtf8());
        qDebug()<<ui->label_filename->text().toUtf8();
    }

}

void downloadlist::on_pushButton_2_clicked()
{
    ui->label_2->setText("已取消下载");
    ui->pushButton_2->setEnabled(false);
    ui->progressBar->hide();
    close=true;
}
