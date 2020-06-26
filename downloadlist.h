#ifndef DOWNLOADLIST_H
#define DOWNLOADLIST_H

#include <QWidget>
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
    void choose(bool);
    bool free;
    void setFileName(QString);
    void seticon(const QPixmap);
    void closeDownload();
    int num;
    bool close=false;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


private:
    Ui::downloadlist *ui;
    static bool isInstall;

};
//bool downloadlist::isInstall=false;
#endif // DOWNLOADLIST_H
