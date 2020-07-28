#include "mainwindow.h"

#include <DMainWindow>
#include <QDesktopWidget>
#include <DTitlebar>
#include <QHBoxLayout>
#include <QDebug>
#include <DFileServices>
#include <DApplicationHelper>
DWIDGET_USE_NAMESPACE

MainWindow::MainWindow(QWidget *parent)
    : DMainWindow(parent)
{
    w = new Widget;

    resize(w->size()); //设置窗口大小
    setCentralWidget(w);

    //添加搜索框
    DMainWindow::titlebar()->addWidget(searchEdit);
    DMainWindow::titlebar()->setIcon(QIcon::fromTheme("spark-store"));
    DMainWindow::titlebar()->setTitle("星火应用商店");
    searchEdit->setPlaceholderText("搜索或打开链接");
    searchEdit->setMaximumWidth(300);

    //添加菜单项
    QAction *setting=new QAction("设置");
    QMenu *menu=new QMenu;
    menu->addAction(setting);
    DMainWindow::titlebar()->setMenu(menu);



//    connect(DGuiApplicationHelper::instance(),&DGuiApplicationHelper::instance()->applicationPalette().highlight().color()::)


    //链接信号和槽

    //设置活动颜色和明暗模式
    connect(DGuiApplicationHelper::instance(), &DGuiApplicationHelper::themeTypeChanged, this, [=](DGuiApplicationHelper::ColorType themeType) {
        QColor main_color;
        main_color=DGuiApplicationHelper::instance()->applicationPalette().highlight().color();
        if(themeType==DGuiApplicationHelper::DarkType){
            qDebug()<<"Dark";
            w->setTheme(true,main_color);
        }else {
            qDebug()<<"White";
            w->setTheme(false,main_color);
        }
    });
    //设置菜单
    connect(setting,&QAction::triggered,w,&Widget::opensetting);
    //搜索事件
    connect(searchEdit,&DSearchEdit::editingFinished,this,[=](){
        QString searchtext=searchEdit->text();
        if(searchtext!=""){
            qDebug()<<searchEdit->text();
            w->searchApp(searchtext);
        }
        searchEdit->clearEdit();

    });



}

MainWindow::~MainWindow()
{

}

void MainWindow::openUrl(QUrl url)
{
    w->openUrl(url);

}

