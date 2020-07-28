#include "big_image.h"
#include <QHBoxLayout>
big_image::big_image(DBlurEffectWidget *parent) : DBlurEffectWidget(parent)
{
//    m_image->setParent(this);
    QHBoxLayout *layout=new QHBoxLayout;
    setLayout(layout);
    layout->addWidget(m_image);
    layout->setMargin(0);
    m_image->setAlignment(Qt::AlignCenter);
    m_image->setMaximumSize(1024,768);
    setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint);//设置图片对话框总在最前

}

void big_image::mousePressEvent(QMouseEvent *)
{
    hide();
    m_image->clear();
}

void big_image::setimage(QPixmap image)
{
    m_image->setPixmap(image);
}

void big_image::focusOutEvent(QFocusEvent *)
{
    hide();
    m_image->clear();
}
