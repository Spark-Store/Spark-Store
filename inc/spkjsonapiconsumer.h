#ifndef SPKJSONAPICONSUMER_H
#define SPKJSONAPICONSUMER_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QtNetwork/QNetworkAccessManager>

class SpkJsonApiConsumer: public QObject
{
    Q_OBJECT
  public:
    SpkJsonApiConsumer();

  private:
    QNetworkAccessManager mNet;

  public slots:
    void RequestUrl(QUrl);

  signals:
    void RequestFinish(QJsonDocument, int);
};

#endif // SPKJSONAPICONSUMER_H
