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
#include <QToolButton>
#include <QTimer>
#include <DSettings>
#include <DBlurEffectWidget>
#include <DSpinner>
#include <DWaterProgress>
#include <QLabel>
#define LIST_MAX 99 //一次最多下载数量
#define TMP_PATH "/tmp/spark-store"

DWIDGET_USE_NAMESPACE
namespace Ui {
class Widget;
}



class Widget : public QWidget
{

    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void startRequest(QUrl url);
    void searchApp(QString);
    int nowDownload=0;
    int allDownload=0;
    int isdownload=false;
    void opensetting(); //打开设置页面
    void openUrl(QUrl);
    void setTheme(bool);

private slots:

    void httpFinished();
    void httpReadyRead();
    void updateDataReadProgress(qint64,qint64);
    void on_menu_btn_main_clicked();
    void on_menu_btn_network_clicked();
    void on_menu_btn_download_clicked();
    void on_menu_btn_chat_clicked();
    void on_menu_btn_music_clicked();
    void on_menu_btn_video_clicked();
    void on_menu_btn_photo_clicked();
    void on_menu_btn_game_clicked();
    void on_menu_btn_office_clicked();
    void on_menu_btn_read_clicked();
    void on_menu_btn_dev_clicked();
    void on_menu_btn_system_clicked();
    void on_menu_btn_other_clicked();
    void on_pushButton_download_clicked();
    void on_pushButton_return_clicked();
    void on_webView_loadStarted();
    void on_menu_btn_theme_clicked();
    void on_comboBox_server_currentIndexChanged(const QString &arg1);
    void on_pushButton_updateServer_clicked();
    void on_pushButton_updateApt_clicked();
    void on_pushButton_uninstall_clicked();
    void on_pushButton_clear_clicked();
    void on_pushButton_website_clicked();
    void on_webView_loadFinished(bool arg1);
    void on_webView_loadProgress(int progress);

    void on_pushButton_clicked();

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

private:
    void initUI();
    void initConfig();
    void loadappinfo(QUrl);
    void chooseLeftMenu(int index);
    quint64 dirFileSize(const QString &path);

private:
    QToolButton * left_list[15];
    QWidget * left_menu_bg[15];
    QUrl menuUrl[13];
    DWaterProgress *m_loadweb=new DWaterProgress;
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
    QTimer download_speed;
    QString type_name;

};

#endif // WIDGET_H
