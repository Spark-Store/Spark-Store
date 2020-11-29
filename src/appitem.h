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
    ~AppItem();

    void setTitle(QString title);
    void setDescription(QString description);
    void setIcon(QString icon);
    void setUrl(QString url);

protected:
    void mousePressEvent(QMouseEvent *event) override;

signals:
    void clicked(QUrl url);

public slots:
    void downloadIcon(QString icon);
    void loadIcon(QPixmap pic);

private:
    Ui::AppItem *ui;

    QString m_title;
    QString m_description;
    QString m_icon;
    QString m_pkgname;
    QString m_url;
};

#endif // APPITEM_H
