#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <DMainWindow>
#include "widget.h"
#include <QThread>
#include <DSearchEdit>
DWIDGET_USE_NAMESPACE

class MainWindow : public DMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
//    DSearchEdit *searchEdit=new DSearchEdit;
private:

    Widget *w;
};

#endif // MAINWINDOW_H
