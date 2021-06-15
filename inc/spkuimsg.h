//
// Created by rigoligo on 2021/5/9.
//

#ifndef _SPKUIMSG_H_
#define _SPKUIMSG_H_

#pragma push_macro("signals")
#undef signals
#include <libnotify/notify.h>
#define signals DUMMY
#pragma pop_macro("signals")

#include <QString>
#include <QObject>
#include "spkui_general.h"

class SpkUiMessage : public QObject
{
    Q_OBJECT
  public:
    static void SendDesktopNotification(QString aMsg,
                                        const char * const aIcon = SpkUi::StoreIconName);
    static void SendStoreNotification(QString);
    static void SetDesktopNotifyTimeout(int ms);

  private:
    static NotifyNotification *_notify;
    static int mTimeoutDesktop;

  signals:

};

#endif //_SPKUIMSG_H_
