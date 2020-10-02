#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QUrl>
#include <QFile>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <downloadlist.h>
#include <QJsonObject>
#include <QProcess>
#include <QFuture>
#include <QFutureWatcher>
#include <QToolButton>
#include <QTimer>
#include <DSettings>
#include <DBlurEffectWidget>
#include <DSpinner>
#include <DWaterProgress>
#include <QLabel>
#include <DTitlebar>
#include <DSearchEdit>
#include <progressload.h>
#define LIST_MAX 99 //一次最多下载数量
#define TMP_PATH "/tmp/spark-store"

DWIDGET_USE_NAMESPACE
namespace Ui {
class Widget;
}



class Widget : public DBlurEffectWidget
{

    Q_OBJECT
public:
    explicit Widget(DBlurEffectWidget *parent = nullptr);
    ~Widget();
    void startRequest(QUrl url);
    void searchApp(QString);
    int nowDownload=0;
    int allDownload=0;
    int isdownload=false;
    void opensetting(); //打开设置页面
    void openUrl(QUrl);
    void setTheme(bool,QColor);
    DTitlebar* getTitlebar();

    static void sendNotification(const QString &message, const int msTimeout = 5000, const QString &icon = "spark-store");
    static void sendNotification(const char *message, const int msTimeout = 5000, const QString &icon = "spark-store");

private slots:

    void httpFinished();
    void httpReadyRead();
    void updateDataReadProgress(qint64,qint64);
    void on_pushButton_download_clicked();
    void on_pushButton_return_clicked();
    void on_comboBox_server_currentIndexChanged(const QString &arg1);
    void on_pushButton_updateServer_clicked();
    void on_pushButton_updateApt_clicked();
    void on_pushButton_uninstall_clicked();
    void on_pushButton_clear_clicked();
    void on_pushButton_website_clicked();
    void on_pushButton_clicked();
    void on_btn_openDir_clicked();
    void on_stackedWidget_currentChanged(int arg1);
    void on_webEngineView_urlChanged(const QUrl &arg1);
    void on_webEngineView_loadStarted();
    void on_webEngineView_loadProgress(int progress);
    void on_webEngineView_loadFinished(bool arg1);
    void on_pushButton_refresh_clicked();
    void on_pushButton_translate_clicked();

public:

    QUrl url;

    downloadlist download_list[LIST_MAX];
    Ui::Widget *ui;
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QList<QUrl> urList;
    QFile *file;
    QString appName;
    QString urladdress;
    QString pkgName;
    QString appweb;
    bool themeIsDark;



private:
    void initUI();
    void initConfig();
    int loadappinfo(QUrl);
    void chooseLeftMenu(int index);
    void setfoot(int);
    void updatefoot();
    void updateUI();

    quint64 dirFileSize(const QString &path);

private:
    QPushButton * left_list[15];
    QUrl menuUrl[13];
    ProgressLoad *m_loadweb;
    QLabel *m_loaderror=new QLabel;
    QString serverUrl;
    bool configCanSave=false;
    bool isBusy=false;
    int nowMenu=0; //定位当前菜单
    long download_size=0;
    long size1=0;
    long size2=0;
    QPixmap screen[5];
    QFuture<void> load;
    QFutureWatcher<void> watchScreenshotLoad;
    QTimer download_speed;
    QString type_name;
    QColor main_color;
    int foot;
    DSearchEdit *searchEdit=new DSearchEdit;
    DTitlebar *titlebar;

};

#endif // WIDGET_H
