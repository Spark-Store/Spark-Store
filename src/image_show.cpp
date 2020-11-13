#include "image_show.h"
#include <QHBoxLayout>
#include <QDebug>
#include <QPainter>
#include <DDialog>
#include <DBlurEffectWidget>
#include <DWidgetUtil>
#include <DApplication>
#include <QDesktopWidget>
DWIDGET_USE_NAMESPACE
image_show::image_show(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout *layout=new QHBoxLayout;
    layout->addWidget(m_label);
    setLayout(layout);
    m_label->setText("layout");
}

void image_show::setImage(QPixmap image)
{
    QImage screen0;
    screen0=image.toImage();
//    QPainter painter(&screen0);
    QImage re_screen1;
    QImage re_screen0=screen0.scaled(QSize(400,300),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    desktop_w=DApplication::desktop()->width();
    desktop_h=DApplication::desktop()->height();
    if(screen0.width()>(desktop_w-20) || screen0.height()>(desktop_h-20)){
         re_screen1=screen0.scaled(QSize(desktop_w-20,desktop_h-20),Qt::KeepAspectRatio,Qt::SmoothTransformation);
         m_image=QPixmap::fromImage(re_screen1);
    }else {
        m_image=image;
    }

    m_label->setPixmap(QPixmap::fromImage(re_screen0));
}

void image_show::mousePressEvent(QMouseEvent *)
{
   m_dialog->setimage(m_image);
   m_dialog->showFullScreen();
   m_dialog->setFixedSize(desktop_w,desktop_h);
   m_dialog->move(0,0);/*
   moveToCenter(m_dialog);*/

}
