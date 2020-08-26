#include "progressload.h"

ProgressLoad::ProgressLoad(QWidget *parent) : QWidget(parent)
{
    m_progess=new QWidget(this);
    m_progess->move(0,0);
    m_progess->show();
    timer=new QTimer;
    value=0;
    timer->setInterval(10);
    timer->start();
    connect(timer,&QTimer::timeout,[=](){
        m_progess->setFixedWidth(width()/100*value);
        m_progess->setFixedHeight(height());
    });
}

void ProgressLoad::setValue(int v)
{
    value=v;
    m_progess->setFixedWidth(width()/100*value);
}

void ProgressLoad::setTheme(bool dark, QColor color)
{
    if(dark){
        m_progess->setStyleSheet("background-color:282828");
    }else {
        m_progess->setStyleSheet("background-color:FFFFFF");
    }
    setStyleSheet("background-color:"+color.name());
}
