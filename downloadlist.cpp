#include "downloadlist.h"
#include "ui_downloadlist.h"
#include <QDebug>
#include <QIcon>
#include <QPixmap>
#include <QtConcurrent>
#include <QProcess>
#include <QTextBrowser>
bool downloadlist::isInstall=false;

downloadlist::downloadlist(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::downloadlist)
{
    ui->setupUi(this);
    ui->pushButton_install->setEnabled(false);
    ui->progressBar->setValue(0);
    ui->label_filename->hide();
    ui->pushButton_install->hide();
    ui->pushButton_3->hide();
    ui->widget_spinner->start();
    ui->widget_spinner->hide();
}

downloadlist::~downloadlist()
{
    delete ui;
}

void downloadlist::setValue(long long value)
{
    ui->progressBar->setValue(int(value));
    ui->label_2->setText(QString::number(double(value)/100)+"% ("+speed+")");
    if(ui->label_2->text().left(4)=="100%"){
        ui->label_2->setText("已完成，等待安装");
    }
}

void downloadlist::setMax(long long max)
{
    ui->progressBar->setMaximum(int(max));
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
    if(ui->progressBar->value()!= ui->progressBar->maximum()){
        ui->progressBar->hide();
        ui->pushButton_install->show();
        ui->pushButton_2->hide();
        system("notify-send \""+ui->label->text().toUtf8()+"下载失败\"" +" --icon=/tmp/spark-store/icon_"+QString::number(num).toUtf8()+".png");
        ui->label_2->setText("下载失败，可能是网络错误");
        ui->pushButton_install->setEnabled(false);
        return;

    }
    if(!close){
        ui->progressBar->hide();
        ui->pushButton_install->setEnabled(true);
        ui->pushButton_install->show();
        ui->pushButton_2->hide();
        system("notify-send \""+ui->label->text().toUtf8()+"下载完成，等待安装\"" +" --icon=/tmp/spark-store/icon_"+QString::number(num).toUtf8()+".png");
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

void downloadlist::on_pushButton_install_clicked()
{
    if(!isInstall){
        isInstall=true;
        ui->pushButton_install->hide();
        ui->widget_spinner->show();
        qDebug()<<"/tmp/spark-store/"+ui->label_filename->text().toUtf8();
        ui->label_2->setText("正在安装，请稍候");
        QtConcurrent::run([=](){
            QProcess installer;
            if(reinstall){
                installer.start("pkexec gdebi -n /tmp/spark-store/"+ui->label_filename->text().toUtf8());
            }else {
                installer.start("pkexec gdebi -n /tmp/spark-store/"+ui->label_filename->text().toUtf8());
            }

            installer.waitForFinished();
            out=installer.readAllStandardOutput();
            QStringList everyOut=out.split("\n");
            bool haveError=false;
            bool notRoot=false;
            for (int i=0;i<everyOut.size();i++) {
                qDebug()<<everyOut[i].left(2);
                if(everyOut[i].left(2)=="E:"){
                    haveError=true;
                }
                if(everyOut[i].right(14)=="Not authorized"){
                    notRoot=true;
                }
            }
            QProcess isInstall;
            isInstall.start("dpkg -s "+pkgName);
            isInstall.waitForFinished();
            int error=QString::fromStdString(isInstall.readAllStandardError().toStdString()).length();
            if(error==0){
                ui->pushButton_install->hide();
                ui->label_2->setText("安装完成");
                ui->pushButton_3->show();
            }else {
                ui->pushButton_install->show();
                ui->pushButton_install->show();
                ui->pushButton_install->setText("重装");
                ui->label_2->setText("安装出现错误，可重新安装");
                ui->pushButton_3->show();
            }
            if(notRoot){
                ui->label_2->setText("安装被终止，可重新安装");
                ui->pushButton_install->show();
                ui->pushButton_install->show();
                ui->pushButton_3->hide();
            }
            ui->widget_spinner->hide();
            downloadlist::isInstall=false;

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


    output_w.layout()->addWidget(textbrowser);
    textbrowser->setLineWidth(0);
    textbrowser->setText(out);
    output_w.layout()->setMargin(20);
    output_w.setTitle(ui->label->text());
    output_w.setMinimumHeight(600);
    output_w.setAttribute(Qt::WA_TranslucentBackground);
    output_w.show();
}
