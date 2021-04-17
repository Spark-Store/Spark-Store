#ifndef APPITEM_H
#define APPITEM_H

#include <QWidget>
#include <QUrl>

namespace Ui {
class AppItem;
}

class AppItem : public QWidget
{
    Q_OBJECT

public:
    explicit AppItem(QWidget *parent = nullptr);
    ~AppItem() override;

    void setTitle(QString title);
    void setDescription(QString description);
    void setIcon(QString icon);
    void setUrl(QString url);

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    Ui::AppItem *ui;

    QString m_title;
    QString m_description;
    QString m_icon;
    QString m_url;

public slots:
    void downloadIcon(QString icon);
    void loadIcon(QPixmap pic);

signals:
    void clicked(QUrl url);
    void finished();

};

#endif // APPITEM_H
