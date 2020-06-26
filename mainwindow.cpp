#include "mainwindow.h"

#include <DMainWindow>

DWIDGET_USE_NAMESPACE

MainWindow::MainWindow(QWidget *parent)
    : DMainWindow(parent)
{
    w = new Widget;

    resize(w->size()); //设置窗口大小
    setMinimumSize(900,750);
    setCentralWidget(w);
}

MainWindow::~MainWindow()
{

}
