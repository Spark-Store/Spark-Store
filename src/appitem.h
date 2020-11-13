#ifndef APPITEM_H
#define APPITEM_H

#include <QWidget>

namespace Ui {
class AppItem;
}

class AppItem : public QWidget
{
    Q_OBJECT

public:
    explicit AppItem(QWidget *parent = nullptr);
    ~AppItem();

private:
    Ui::AppItem *ui;
};

#endif // APPITEM_H
