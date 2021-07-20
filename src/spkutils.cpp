
#include <arpa/inet.h>
#include <QDebug>
#include "spkutils.h"

void SpkUtils::VerifySingleRequest(QPointer<QNetworkReply> aReply)
{
  if(aReply.isNull())
    return;
  aReply->disconnect(SIGNAL(finished()));
  aReply->abort();
  aReply->deleteLater();
}

QString SpkUtils::GetDistroName()
{
  QSettings osRelease("/etc/os-release", QSettings::IniFormat);
  return osRelease.value("PRETTY_NAME", "Unknown Distro").toString() + "-" +
         osRelease.value("BUILD_ID", "Unknown Build").toString();
}

bool SpkUtils::VerifyReplyJson(QNetworkReply *aReply, QJsonValue &aRetDoc)
{
  QJsonParseError err;
  QByteArray rawjson = aReply->readAll();
  qDebug() << "Received:" << rawjson;
  QJsonDocument ret = QJsonDocument::fromJson(rawjson, &err);
  QJsonObject replyObject;
  if(err.error != QJsonParseError::NoError)
  {
    sNotify(QObject::tr("Failed to parse server reply! Error %1.").arg(err.error));
    sErr(QObject::tr("VerifyReplyJson: returned JSON of request to %1 is unreadable.")
         .arg(aReply->url().toString()));
    return false;
  }
  if(!ret.isObject())
  {
    sNotify(QObject::tr("Server sent back an invalid response."));
    sErr(QObject::tr("VerifyReplyJson: returned JSON of request to %1 is not an Object.")
         .arg(aReply->url().toString()));
    return false;
  }
  replyObject = ret.object();
  if(!replyObject.contains("code"))
  {
    sWarn(QObject::tr("VerifyReplyJson: reply of request to %1 doesn't have a code.")
          .arg(aReply->url().toString()));
  }
  else
  {
    auto OpRetCode = replyObject.value("code");
    if(!OpRetCode.isDouble())
    {
      sWarn(QObject::tr("VerifyReplyJson: Reply of request to %1 has a non-numeric code.")
            .arg(aReply->url().toString()));
    }
    else if(OpRetCode.toInt() != 0)
    {
      sNotify(QObject::tr("Server sent back an failure message; code: %1.")
              .arg(OpRetCode.toInt()));
      sErr(QObject::tr("VerifyReplyJson: Request to %1 failed with code %2.")
           .arg(aReply->url().toString()).arg(OpRetCode.toInt()));
      return false;
    }
  }
  if(!replyObject.contains("data"))
  {
    sNotify(QObject::tr("Server did not reply with any data."));
    sErr(QObject::tr("VerifyReplyJson: Reply of request to %1 didn't include any data.")
         .arg(aReply->url().toString()));
    return false;
  }
  aRetDoc = replyObject.value("data");
  return true;
}

void SpkUtils::DeleteReplyLater(QNetworkReply *aReply)
{
  QObject::connect(aReply, &QNetworkReply::finished, aReply, &QObject::deleteLater);
}
