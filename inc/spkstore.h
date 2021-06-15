//
// Created by rigoligo on 2021/5/12.
//

#ifndef _SPKSTORE_H_
#define _SPKSTORE_H_

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
    SpkStore *Instance;
    SpkStore(bool aCli, QString &aLogPath);
    ~SpkStore();


  private:
    SpkLogger *mLogger;
    SpkMainWindow *mMainWindow;

};

#endif //_SPKSTORE_H_
