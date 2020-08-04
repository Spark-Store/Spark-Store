#include "mainwindow.h"
#include <DApplication>
#include <DWidgetUtil>  //Dtk::Widget::moveToCenter(&w); 要调用它，就得引用DWidgetUtil
#include <QDesktopWidget>
DWIDGET_USE_NAMESPACE
int main(int argc, char *argv[])
{
    DApplication::loadDXcbPlugin();  //让bar处在标题栏中
    DApplication a(argc, argv);
    a.setAttribute(Qt::AA_UseHighDpiPixmaps);
    a.loadTranslator();
    a.setOrganizationName("spark-union");
    a.setApplicationVersion(DApplication::buildVersion("1.0-beta5.5.1"));
    a.setApplicationAcknowledgementPage("https://gitee.com/deepin-community-store/spark-store");
    a.setProductIcon(QIcon::fromTheme("spark-store"));  //设置Logo

    a.setProductName("Spark应用商店");
    a.setApplicationDescription("深度社区驱动的一款为deepin打造的第三方商店");
    a.setApplicationName("Spark应用商店"); //只有在这儿修改窗口标题才有效
    MainWindow w;
    QDesktopWidget *s=DApplication::desktop();
    int d_w=s->width();
    int d_h=s->height();
    if(d_w<=1366){
        w.setMinimumWidth(820);
        w.resize(820,640);
    }else if(d_w<=1920){
        w.setMinimumWidth(1140);
        w.resize(1140,760);
    }else {
        w.setMinimumWidth(1140);
        w.resize(1140,760);
    }
    if(d_h<=768){
        w.setMinimumHeight(640);
        w.resize(820,640);
    }else if(d_h<=1080){
        w.setMinimumHeight(760);
        w.resize(1140,760);
    }else {
        w.setMinimumHeight(760);
        w.resize(1140,760);
    }

    w.show();
    QString arg1=argv[1];
    if(arg1.left(6)=="spk://"){
        w.openUrl(QUrl(argv[1]));
    }
    //让打开时界面显示在正中
    Dtk::Widget::moveToCenter(&w);

    return a.exec();
}
