#include "mainwindow.h"
#include <DApplication>
#include <DWidgetUtil>  //Dtk::Widget::moveToCenter(&w); 要调用它，就得引用DWidgetUtil

DWIDGET_USE_NAMESPACE
int main(int argc, char *argv[])
{
    DApplication::loadDXcbPlugin();  //让bar处在标题栏中
    DApplication a(argc, argv);
    a.setAttribute(Qt::AA_UseHighDpiPixmaps);
    a.loadTranslator();
    a.setOrganizationName("community");
    a.setApplicationVersion(DApplication::buildVersion("1.0-beta3.2"));
    a.setApplicationAcknowledgementPage("https://gitee.com/deepin-community-store/deepin-community-store");
    a.setProductIcon(QIcon::fromTheme("spark-store"));  //设置Logo
    a.setProductName("星火应用商店");
    a.setApplicationName("星火应用商店"); //只有在这儿修改窗口标题才有效

    MainWindow w;
    w.show();

    //让打开时界面显示在正中
    Dtk::Widget::moveToCenter(&w);


    return a.exec();
}
