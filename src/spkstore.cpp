
#include <spkui_general.h>
#include <QPluginLoader>
#include <QDir>
#include <QApplication>
#include <QtNetwork/QNetworkProxy>
#include "dtk/spkdtkplugin.h"
#include "gitver.h"
#include "spkstore.h"
#include "spkutils.h"

SpkStore *SpkStore::Instance = nullptr;
static void InstallDefaultConfigs();

SpkStore::SpkStore(bool aCli, QString &aLogPath)
{
  mLogger = new SpkLogger(aLogPath);

  // Singleton
  Q_ASSERT(Instance == nullptr);
  Instance = this;

  // Finish all essential initialization after this.
  if(QFileInfo(QDir::homePath() + "/.config/spark-store/config").exists())
    mCfg = new QSettings(QDir::homePath() + "/.config/spark-store/config", QSettings::IniFormat);
  else
  {
    mCfg = new QSettings(":/info/default_config", QSettings::IniFormat);
#ifndef NDEBUG
    if(!qgetenv("SPARK_NO_INSTALL_CONFIG").toInt())
    {
      if(!QFile::copy(":/info/default_config", QDir::homePath() + "/.config/spark-store/config"))
        sErrPop(tr("Cannot install default config file!"));
    }
#endif
  }

  mNetMgr = new QNetworkAccessManager(this);
  mNetMgr->setProxy(QNetworkProxy(QNetworkProxy::NoProxy)); // FIXME
  mDistroName = SpkUtils::GetDistroName();
  mApiRequestUrl = "https://store.deepinos.org/api/"; // TODO: CHECK BEFORE 4.0 RELEASE
  mUserAgentStr = QString("Spark-Store/%1 Distro/%2")
      .arg(GitVer::DescribeTags())
      .arg(mDistroName);

  // Finish all essential initialization before this.
  if(aCli)
    return;

  // UI Initialization
  SpkUi::Initialize();
  mMainWindow = new SpkMainWindow;

  mMainWindow->show();
}

SpkStore::~SpkStore()
{
  delete mMainWindow;
  delete mLogger;
}

QNetworkReply *SpkStore::SendApiRequest(QString aPath, QJsonDocument aParam)
{
  QNetworkRequest request;
  request.setUrl(mApiRequestUrl + aPath);
  request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
  request.setHeader(QNetworkRequest::UserAgentHeader, mUserAgentStr);
  return mNetMgr->post(request, aParam.isEmpty() ? "{}" : aParam.toJson(QJsonDocument::Compact));
}

static void InstallDefaultConfigs()
{
  //TODO:STUB
}
