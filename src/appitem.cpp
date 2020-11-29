#include "appitem.h"
#include "ui_appitem.h"
#include <QtConcurrent>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QEventLoop>

AppItem::AppItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AppItem)
{
    ui->setupUi(this);
}

AppItem::~AppItem()
{
    delete ui;
}

void AppItem::setTitle(QString title)
{
    m_title = title;
    ui->lbl_title->setText(title);
}

void AppItem::setDescription(QString description)
{
    m_description = description;
    ui->lbl_desc->setText(description);
}

void AppItem::setIcon(QString icon)
{
    m_icon = icon;
    downloadIcon(icon);
}

void AppItem::setUrl(QString url)
{
    m_url = url;
}

void AppItem::mousePressEvent(QMouseEvent *event)
{
    emit clicked(QUrl(m_url));
}

/**
 * @brief 下载图标
 * @param icon
 */
void AppItem::downloadIcon(QString icon)
{
    QtConcurrent::run([=](){
        auto reqManager = new QNetworkAccessManager();
        QUrl url(icon);
        QNetworkReply *reply = reqManager->get(QNetworkRequest(url));
        QEventLoop loop;
        connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
        loop.exec();
        reqManager->deleteLater();
        QPixmap pixmap;
        pixmap.loadFromData(reply->readAll());
        if (reply->error() == QNetworkReply::NoError) {
            QMetaObject::invokeMethod(this, "loadIcon", Qt::QueuedConnection,
                                      Q_ARG(QPixmap, pixmap));
        }
    });
}

void AppItem::loadIcon(QPixmap pic)
{
    qDebug() << pic;
    ui->lbl_icon->setPixmap(pic);
}
