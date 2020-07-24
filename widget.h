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
#define LIST_MAX 99
#define TMP_PATH "/tmp/spark-store"

DWIDGET_USE_NAMESPACE
namespace Ui {
class Widget;
}



class Widget : public QWidget
{

    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void startRequest(QUrl url);
    void searchApp(QString);
    int nowDownload=0;
    int allDownload=0;
    int isdownload=false;
    void loadappinfo(QUrl);
    void chooseLeftMenu(int index);
    quint64 dirFileSize(const QString &path);
    QPixmap screen[5];
    QFuture<void> load;
    QTimer download_speed;
    void opensetting();

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
    void on_webView_loadFinished();
    void on_menu_btn_theme_clicked();
    void on_comboBox_server_currentIndexChanged(const QString &arg1);
    void on_pushButton_updateServer_clicked();
    void on_pushButton_updateApt_clicked();
    void on_pushButton_uninstall_clicked();
    void on_pushButton_clear_clicked();
    void on_pushButton_website_clicked();

    void on_webView_loadFinished(bool arg1);

public:
    void initUI();
    void initConfig();
    QUrl url;
    bool isBusy=false;
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
    QToolButton * left_list[15];
    QWidget * left_menu_bg[15];
    QUrl menuUrl[13];
    bool configCanSave=false;
    int nowMenu=0;
    long download_size=0;
    long size1=0;
    long size2=0;
    Dtk::Core::DSettings *jsonConfig=new Dtk::Core::DSettings;
private:
    DSpinner *m_loadweb=new DSpinner;

};

#endif // WIDGET_H
