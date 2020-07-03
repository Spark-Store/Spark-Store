#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <DMainWindow>
#include "widget.h"
#include <QThread>
DWIDGET_USE_NAMESPACE

class MainWindow : public DMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

    Widget *w;
};

#endif // MAINWINDOW_H
