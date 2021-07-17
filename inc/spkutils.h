
#pragma once

#include <QPointer>
#include <QString>
#include <QSettings>
#include <QFile>
#include <QtNetwork/QNetworkReply>

#include "spkstore.h"
#include "spklogging.h"

#define STORE SpkStore::Instance
#define CFG (SpkStore::Instance->mCfg)

namespace SpkUtils
{
  QString GetDistroName();

  void VerifySingleRequest(QPointer<QNetworkReply> aReply);

  void DeleteReplyLater(QNetworkReply *aReply);

  bool VerifyReplyJson(QNetworkReply *aReply, QJsonValue& aRetDoc);
}
