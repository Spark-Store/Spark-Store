
#include <spkui_general.h>
#include "spkstore.h"

SpkStore::SpkStore(bool aCli, QString &aLogPath)
{
  mLogger = new SpkLogger(aLogPath);

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
