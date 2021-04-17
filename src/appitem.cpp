#include "appitem.h"
#include "ui_appitem.h"
#include <QtConcurrent>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QEventLoop>
#include <QPainter>
#include <QGraphicsDropShadowEffect>

AppItem::AppItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AppItem)
{
    ui->setupUi(this);

    // auto shadow = new QGraphicsDropShadowEffect();
    // shadow->setXOffset(0);
    // shadow->setYOffset(1);
    // shadow->setBlurRadius(2);
    // shadow->setColor(QColor::fromRgba(qRgba(0, 0, 0, 180)));
    // ui->container->setGraphicsEffect(shadow);
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
    QString elidedText = ui->lbl_desc->fontMetrics().elidedText(
                description, Qt::ElideRight,
                ui->lbl_desc->width(), Qt::TextShowMnemonic);
    ui->lbl_desc->setText(elidedText);
    ui->lbl_desc->setAlignment(Qt::AlignTop);
}

void AppItem::setIcon(QString icon)
{
    m_icon = icon;
    if(!icon.isEmpty())
    {
        downloadIcon(icon);
    }
}

void AppItem::setUrl(QString url)
{
    m_url = url;
}

void AppItem::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event)

    emit clicked(QUrl(m_url));
}

/**
 * @brief 下载图标
 * @param icon
 */
void AppItem::downloadIcon(QString icon)
{
    QtConcurrent::run([=]()
    {
        auto reqManager = new QNetworkAccessManager();

        QUrl url(icon);
        QNetworkReply *reply = reqManager->get(QNetworkRequest(url));
        QEventLoop loop;
        connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
        connect(reply, &QNetworkReply::finished, this, [=] () { emit finished(); });
        loop.exec();
        reqManager->deleteLater();

        QPixmap pixmap;
        pixmap.loadFromData(reply->readAll());
        pixmap = pixmap.scaled(78, 78, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        if (reply->error() == QNetworkReply::NoError)
        {
            QMetaObject::invokeMethod(this, "loadIcon", Qt::QueuedConnection, Q_ARG(QPixmap, pixmap));
        }
        else
        {
            qDebug() << reply->errorString();
        }
    });
}

void AppItem::loadIcon(QPixmap pic)
{
    ui->lbl_icon->setPixmap(pic);
}
