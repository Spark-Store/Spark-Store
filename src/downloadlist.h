#ifndef DOWNLOADLIST_H
#define DOWNLOADLIST_H

#include <QWidget>
#include <DDialog>
#include <QTextBrowser>
#include <QMenu>
#include <QAction>
DWIDGET_USE_NAMESPACE
namespace Ui {
class downloadlist;
}

class downloadlist : public QWidget
{
    Q_OBJECT

public:
    explicit downloadlist(QWidget *parent = nullptr);
    ~downloadlist();
    void setValue(long long);
    void setMax(long long);
    void setName(QString);
    QString getName();
    void readyInstall();
    bool free;
    void setFileName(QString);
    void seticon(const QPixmap);
    void closeDownload();
    void setSpeed(QString);
    int num;
    bool close=false;
    QString out;
    DDialog output_w;
    QTextBrowser *textbrowser=new QTextBrowser;
    bool reinstall=false;
    QString pkgName;
    QMenu *menu_install=new QMenu;
    QAction *action_gdebi=new QAction;
    QAction *action_dpkg=new QAction;
    QAction *action_deepin=new QAction;
    void install(int);
private slots:
    void on_pushButton_install_clicked();
//    void on_pushButton_maninst_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::downloadlist *ui;
    static bool isInstall;
    QString speed;


};
//bool downloadlist::isInstall=false;
#endif // DOWNLOADLIST_H
