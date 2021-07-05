
#include <spkui_general.h>
#include "dtk/spkdtkplugin.h"
#include <QPluginLoader>
#include <QDir>
#include <QApplication>
#include "spkstore.h"

SpkStore *SpkStore::Instance = nullptr;

SpkStore::SpkStore(bool aCli, QString &aLogPath)
{
  mLogger = new SpkLogger(aLogPath);

  // Singleton
  Q_ASSERT(Instance == nullptr);
  Instance = this;

  // Finish all essential initialization after this.

  mNetMgr = new QNetworkAccessManager(this);

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
