#ifndef DOWNLOADLIST_H
#define DOWNLOADLIST_H

#include <QWidget>
#include <outputwindow.h>
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
    outputwindow output_w;
    bool reinstall=false;
    QString error;
    QString pkgName;
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


    void on_pushButton_3_clicked();

private:
    Ui::downloadlist *ui;
    static bool isInstall;
    QString speed;


};
//bool downloadlist::isInstall=false;
#endif // DOWNLOADLIST_H
