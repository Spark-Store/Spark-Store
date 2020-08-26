#include "progressload.h"

ProgressLoad::ProgressLoad(QWidget *parent) : QWidget(parent)
{
    m_progess=new QWidget;
    m_progess->setStyleSheet("background-color:#999999");
    m_progess->move(0,0);
    timer=new QTimer;
    value=0;
    timer->setInterval(100);
    timer->start();
    connect(timer,&QTimer::timeout,[=](){
        m_progess->setFixedWidth(width()/100*value);
    });
}

void ProgressLoad::setValue(int v)
{
    value=v;
    m_progess->setFixedWidth(width()/100*value);
}
