#include <DApplication>
#include <DWidgetUtil>  //Dtk::Widget::moveToCenter(&w); 要调用它，就得引用DWidgetUtil
#include <QDesktopWidget>
#include <widget.h>
#include <QTranslator>
#include <DAboutDialog>
DWIDGET_USE_NAMESPACE
int main(int argc, char *argv[])
{
    DApplication::loadDXcbPlugin();  //让bar处在标题栏中
    DApplication a(argc, argv);
    DAboutDialog dialog;
    a.setAttribute(Qt::AA_UseHighDpiPixmaps);
    a.loadTranslator();//载入翻译
    a.setAboutDialog(&dialog);
    dialog.setLicense(QObject::tr("We publish this program under GPL V3"));
    dialog.setVersion(DApplication::buildVersion("Version 2.0+2"));
    dialog.setAcknowledgementVisible(true);
    dialog.setAcknowledgementLink(QObject::tr("https://gitee.com/deepin-community-store/spark-store"));
    a.setApplicationAcknowledgementPage(QObject::tr("https://gitee.com/deepin-community-store/spark-store"));
    dialog.setProductIcon(QIcon::fromTheme("spark-store"));  //设置Logo
    dialog.setProductName(QLabel::tr("Spark Store"));
    //dialog.setDescription(QLabel::tr("An appstore powered by deepin community\n We born for change"));
    dialog.setDescription(QObject::tr(
        "<span style=' font-size:10pt;font-weight:60;'>An appstore powered by deepin community</span><br/>"
        "<a href='https://www.spark-app.store/'>https://www.spark-app.store</a><br/>"
        "<span style=' font-size:12pt;'>Spark developers</span>"
                              )
                          );
    dialog.setProductName(QLabel::tr("Spark Store"));
    dialog.setCompanyLogo(QPixmap(":/Logo-Spark.png"));
    dialog.setWebsiteName(QObject::tr("The Spark Project"));
    dialog.setWebsiteLink("https://gitee.com/deepin-community-store");

    Widget w;
    QDesktopWidget *s=DApplication::desktop();
    int d_w=s->width();
    int d_h=s->height();
    if(d_w<=1366){
        w.setMinimumWidth(925);
        w.resize(925,650);
    }else if(d_w<=1920){
        w.setMinimumWidth(1180);
        w.resize(1180,760);
    }else {
        w.setMinimumWidth(1180);
        w.resize(1180,760);
    }
    if(d_h<=768){
        w.setMinimumHeight(650);
        w.resize(925,650);
    }else if(d_h<=1080){
        w.setMinimumHeight(760);
        w.resize(1180,760);
    }else {
        w.setMinimumHeight(760);
        w.resize(1180,760);
    }
//    w.resize(925,650);

    w.show();
    QString arg1=argv[1];
    if(arg1.left(6)=="spk://"){
        w.openUrl(QUrl(argv[1]));
    }
    //让打开时界面显示在正中
    Dtk::Widget::moveToCenter(&w);

    return a.exec();
}
