#include "downloadlist.h"
#include "ui_downloadlist.h"
#include <QDebug>
downloadlist::downloadlist(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::downloadlist)
{
    ui->setupUi(this);
    ui->pushButton->setEnabled(false);
    ui->progressBar->setValue(0);
    ui->label_filename->hide();
    ui->label->setStyleSheet("color:#000000");
}

downloadlist::~downloadlist()
{
    delete ui;
}

void downloadlist::setValue(long long value)
{
    ui->progressBar->setValue(value);
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
    return ui->label->text();
}

void downloadlist::readyInstall()
{
    ui->progressBar->hide();
    ui->pushButton->setEnabled(true);
}

void downloadlist::choose(bool isChoosed)
{
    if(isChoosed){
        ui->label->setStyleSheet("color:#FFFFFF");
    }else {
        ui->label->setStyleSheet("color:#000000");
    }
}

void downloadlist::setFileName(QString fileName)
{
    ui->label_filename->setText(fileName);
}

void downloadlist::on_pushButton_clicked()
{
    system("deepin-terminal -e sudo dpkg -i ./"+ui->label_filename->text().toUtf8()+" && sudo apt install -f");
    qDebug()<<ui->label_filename->text().toUtf8();
}
