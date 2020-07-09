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
    ui->pushButton_3->hide();
    ui->label->setStyleSheet("color:#000000");
}

downloadlist::~downloadlist()
{
    delete ui;
}

void downloadlist::setValue(long long value)
{
    ui->progressBar->setValue(value);
    ui->label_2->setText(QString::number((double)value/100)+"% ("+speed+")");
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
        system("notify-send \""+ui->label->text().toUtf8()+"下载完成，等待安装\"" +" --icon=/tmp/deepin-community-store/icon_"+QString::number(num).toUtf8()+".png");
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

void downloadlist::setSpeed(QString s)
{
    speed=s;
}

void downloadlist::on_pushButton_clicked()
{
    if(!isInstall){
        isInstall=true;
        ui->pushButton->setEnabled(false);
        qDebug()<<"/tmp/deepin-community-store/"+ui->label_filename->text().toUtf8();
        ui->label_2->setText("正在安装，请稍候");
        QtConcurrent::run([=](){
            QProcess installer;
            if(reinstall){
                installer.start("pkexec ssinstall /tmp/deepin-community-store/"+ui->label_filename->text().toUtf8());
            }else {
                installer.start("pkexec ssinstall /tmp/deepin-community-store/"+ui->label_filename->text().toUtf8());
            }

            installer.waitForFinished();
            error=installer.readAllStandardError();
            out=installer.readAllStandardOutput();
            QStringList everyError=error.split("\n");
            bool haveError=false;
            bool notRoot=false;
            for (int i=0;i<everyError.size();i++) {
                qDebug()<<everyError[i].left(2);
                if(everyError[i].left(2)=="E:"){
                    haveError=true;
                }
                if(everyError[i].right(14)=="Not authorized"){
                    notRoot=true;
                }
            }
            QProcess isInstall;
            isInstall.start("dpkg -s "+pkgName);
            isInstall.waitForFinished();
            int error=QString::fromStdString(isInstall.readAllStandardError().toStdString()).length();
            if(error==0){
                ui->pushButton->hide();
                ui->label_2->setText("安装完成");
                ui->pushButton_3->show();
            }else {
                ui->pushButton->hide();
                ui->label_2->setText("安装出现错误");
                ui->pushButton_3->show();
            }
            if(notRoot){
                ui->label_2->setText("安装被终止");
                ui->pushButton->setEnabled(true);
            }
        });
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

void downloadlist::on_pushButton_3_clicked()
{
    output_w.setoutput(out+"\nERROR:\n"+error);
    output_w.show();
}
