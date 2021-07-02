
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

  Q_ASSERT(Instance == nullptr);
  Instance = this;

  if(aCli)
    return;

  SpkUi::Initialize();
  mMainWindow = new SpkMainWindow;

  mMainWindow->show();
}

SpkStore::~SpkStore()
{
  delete mMainWindow;
  delete mLogger;
}
