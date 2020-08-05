#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <DMainWindow>
#include "widget.h"
#include <QThread>
#include <DSearchEdit>
#include <DBlurEffectWidget>
#include <DTitlebar>
DWIDGET_USE_NAMESPACE

class MainWindow : public DBlurEffectWidget
{
    Q_OBJECT


public:
    MainWindow(DBlurEffectWidget *parent = nullptr);
    ~MainWindow();
    DSearchEdit *searchEdit=new DSearchEdit;
    DTitlebar *titlebar;
    void openUrl(QUrl);

private:

    Widget *w;
};

#endif // MAINWINDOW_H
