#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <DMainWindow>
#include "widget.h"

DWIDGET_USE_NAMESPACE

class MainWindow : public DMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Widget *w;
};

#endif // MAINWINDOW_H
