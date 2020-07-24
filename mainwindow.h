#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <DMainWindow>
#include "widget.h"
#include <QThread>
#include <DSearchEdit>
#include <DBlurEffectWidget>
#include <DTitlebar>
DWIDGET_USE_NAMESPACE

class MainWindow : public DMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    DSearchEdit *searchEdit=new DSearchEdit;
    DTitlebar *titlebar=new DTitlebar;
private:

    Widget *w;
};

#endif // MAINWINDOW_H
