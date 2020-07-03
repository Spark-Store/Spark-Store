#include "outputwindow.h"
#include "ui_outputwindow.h"
#include <QDebug>
#include <QDesktopWidget>
outputwindow::outputwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::outputwindow)
{
    ui->setupUi(this);
    setWindowTitle("安装详情");
    QDesktopWidget *desktop = QApplication::desktop();
    move((desktop->width() - width())/ 2, (desktop->height() - height()) /2);
}

outputwindow::~outputwindow()
{
    delete ui;
}

void outputwindow::setoutput(QString output)
{
    qDebug()<<output;
    ui->textBrowser->setText(output);
}
