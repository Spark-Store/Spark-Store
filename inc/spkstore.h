//
// Created by rigoligo on 2021/5/12.
//

#pragma once

#include <QMap>
#include <QString>
#include "spklogging.h"
#include "spkmainwindow.h"

/**
 * @brief SpkStore class is the core of the store client side program, it is constructed first and
 *        handling all processing after the launch. All client side data should be held by it,
 *        including preferences class, category names, request URLs, downloads status, packaging
 *        backend interfaces and so on.
 */
class SpkStore : public QObject
{
    Q_OBJECT
  public:
    static SpkStore *Instance;
    SpkStore(bool aCli, QString &aLogPath);
    ~SpkStore();

    SpkMainWindow* GetRootWindow() { return mMainWindow; };

  private:
    SpkLogger *mLogger;
    SpkMainWindow *mMainWindow = nullptr;

};
