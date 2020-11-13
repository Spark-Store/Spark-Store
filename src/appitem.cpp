#include "appitem.h"
#include "ui_appitem.h"

AppItem::AppItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AppItem)
{
    ui->setupUi(this);
}

AppItem::~AppItem()
{
    delete ui;
}
