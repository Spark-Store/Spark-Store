#include "image_show.h"
#include <QHBoxLayout>
#include <QDebug>
#include <QPainter>
#include <DDialog>
#include <DBlurEffectWidget>
#include <DWidgetUtil>
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
    QPainter painter(&screen0);
    QImage re_screen1;
    QImage re_screen0=screen0.scaled(QSize(400,300),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    //防止图片尺寸过大导致窗口覆盖整个屏幕
    if(screen0.width()>1024 || screen0.height()>768){
        re_screen1=screen0.scaled(QSize(1024,768),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    }else {
        re_screen1=screen0;

    }

    m_image=QPixmap::fromImage(re_screen1);
    m_label->setPixmap(QPixmap::fromImage(re_screen0));
}

void image_show::mousePressEvent(QMouseEvent *)
{
   m_dialog->setimage(m_image);
   m_dialog->show();
   moveToCenter(m_dialog);

}
