#ifndef DOWNLOADLIST_H
#define DOWNLOADLIST_H

#include <QWidget>
#include <QTextBrowser>
#include <QMenu>
#include <QAction>

#include <QDialog>

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

    int num;
    bool free;
    static bool isInstall;
    bool reinstall;
    QString speed;
    QString out;
    QString pkgName;
    bool close;

    void setValue(qint64);
    void setMax(qint64);
    void setName(QString);
    QString getName();
    void readyInstall();

    void setFileName(QString);
    void seticon(const QPixmap);
    void closeDownload();
    void setSpeed(QString);

    void install(int);

private:
    Ui::downloadlist *ui;

    QMenu *menu_install;
    QAction *action_dpkg;
    QAction *action_deepin;
    QAction *action_gdebi;

    QDialog *output_w;
    QTextBrowser *textbrowser;

private slots:
    void on_pushButton_install_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

};

#endif // DOWNLOADLIST_H
