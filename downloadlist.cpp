#include "downloadlist.h"
#include "ui_downloadlist.h"
#include "widget.h"
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
    action_dpkg->setText(tr("dpkg"));
    action_gdebi->setText(tr("gdebi"));
    action_deepin->setText(tr("deepin deb installer"));
    connect(action_dpkg,&QAction::triggered,[=](){downloadlist::install(1);});
    connect(action_gdebi,&QAction::triggered,[=](){downloadlist::install(0);});
    connect(action_deepin,&QAction::triggered,[=](){downloadlist::install(2);});
    menu_install->addAction(action_gdebi);
    //ssinstall命令存在时再加入该选项
    QFile ssinstall("/bin/ssinstall");
    ssinstall.open(QIODevice::ReadOnly);
    if(ssinstall.isOpen()){
        menu_install->addAction(action_dpkg);
    }
    QFile deepin("/bin/deepin-deb-installer");
    deepin.open(QIODevice::ReadOnly);
    if(deepin.isOpen()){
        menu_install->addAction(action_deepin);
    }

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
        ui->label_2->setText(tr("Downloaded, waiting to install"));
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
    if(ui->progressBar->value()!= ui->progressBar->maximum() && !close){
        ui->progressBar->hide();
        ui->pushButton_install->show();
        ui->pushButton_2->hide();
        Widget::sendNotification(tr("Failed to download %1").arg(ui->label->text()), 5000,
                                 "/tmp/spark-store/icon_"+QString::number(num).toUtf8()+".png");
        ui->label_2->setText(tr("Download Failed，Check Your Connection"));
        ui->pushButton_install->setEnabled(false);
        return;

    }
    if(!close){
        ui->progressBar->hide();
        ui->pushButton_install->setEnabled(true);
        ui->pushButton_install->show();
        ui->pushButton_2->hide();
        Widget::sendNotification(tr("Finished downloading %1, awaiting to install").arg(ui->label->text()), 5000,
                                    "/tmp/spark-store/icon_"+QString::number(num).toUtf8()+".png");
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

void downloadlist::install(int t)
{
    if(!isInstall){
        isInstall=true;
        ui->pushButton_install->hide();
        ui->widget_spinner->show();
        qDebug()<<"/tmp/spark-store/"+ui->label_filename->text().toUtf8();
        ui->label_2->setText(tr("Installing..."));
        QtConcurrent::run([=](){
            QProcess installer;
            if(!reinstall){
                switch (t) {
                case 0:
                    installer.start("pkexec gdebi -n /tmp/spark-store/"+ui->label_filename->text().toUtf8());
                    break;
                case 1:
                    installer.start("pkexec ssinstall /tmp/spark-store/"+ui->label_filename->text().toUtf8());
                    break;
                case 2:
                    installer.start("deepin-deb-installer /tmp/spark-store/"+ui->label_filename->text().toUtf8());
                    break;
                }
            }else {
                switch (t) {
                case 0:
                    installer.start("pkexec gdebi -n /tmp/spark-store/"+ui->label_filename->text().toUtf8());
                    break;
                case 1:
                    installer.start("pkexec ssinstall /tmp/spark-store/"+ui->label_filename->text().toUtf8());
                    break;
                case 2:
                    installer.start("deepin-deb-installer /tmp/spark-store/"+ui->label_filename->text().toUtf8());
                    break;
                }
            }
            bool haveError=false;
            bool notRoot=false;
            installer.waitForFinished();
            out=installer.readAllStandardOutput();
            QStringList everyOut=out.split("\n");
            for (int i=0;i<everyOut.size();i++) {
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
                ui->label_2->setText(tr("Finish"));
                ui->pushButton_3->show();
            }else {
                ui->pushButton_install->show();
                ui->pushButton_install->setText(tr("Retry"));
                ui->label_2->setText(tr("Error happened in dpkg progress , you can try it again"));
                ui->pushButton_3->show();
            }
            if(notRoot){
                ui->label_2->setText(tr("dpkg progress had been aborted，you can retry installation"));
                ui->pushButton_install->show();
                ui->pushButton_3->hide();
            }
            ui->widget_spinner->hide();
            downloadlist::isInstall=false;

        });

        qDebug()<<ui->label_filename->text().toUtf8();
    }

}

void downloadlist::on_pushButton_install_clicked()
{
    //弹出菜单
    menu_install->exec(cursor().pos());
}

void downloadlist::on_pushButton_2_clicked()
{
    ui->label_2->setText(tr("Download canceled"));
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
