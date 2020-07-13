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

#define LIST_MAX 99
#define TMP_PATH "/tmp/spark-store"

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
    int nowDownload=0;
    int allDownload=0;
    int isdownload=false;
    void loadappinfo(QUrl);
    void chooseLeftMenu(int index);
    quint64 dirFileSize(const QString &path);
    QPixmap screen[5];
    QFuture<void> load;
    QTimer download_speed;

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

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_webView_loadStarted();

    void on_webView_loadFinished();

    void on_menu_btn_theme_clicked();

    void on_menu_btn_settings_clicked();

    void on_comboBox_server_currentIndexChanged(const QString &arg1);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

public:
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
    QToolButton * left_list[15];
    QWidget * left_menu_bg[15];
    QUrl menuUrl[13];
    bool configCanSeve=false;
    int nowMenu=0;
    long download_size=0;
    long size1=0;
    long size2=0;


};

#endif // WIDGET_H
