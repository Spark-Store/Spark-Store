#ifndef OUTPUTWINDOW_H
#define OUTPUTWINDOW_H

#include <QWidget>

namespace Ui {
class outputwindow;
}

class outputwindow : public QWidget
{
    Q_OBJECT

public:
    explicit outputwindow(QWidget *parent = nullptr);
    ~outputwindow();
    void setoutput(QString);
private:
    Ui::outputwindow *ui;
};

#endif // OUTPUTWINDOW_H
