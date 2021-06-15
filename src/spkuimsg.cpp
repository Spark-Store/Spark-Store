
#include "spkuimsg.h"

NotifyNotification *SpkUiMessage::_notify = nullptr; // Initialize statics
int SpkUiMessage::mTimeoutDesktop = 5000;

void SpkUiMessage::SendDesktopNotification(QString s, const char * const icon)
{
  if(_notify == nullptr)
  {
      _notify = notify_notification_new(tr("Spark\\ Store").toLocal8Bit(),
                                        s.toLocal8Bit(),
                                        icon);
      notify_notification_set_timeout(_notify, mTimeoutDesktop);
  }
  else
  {
      notify_notification_update(_notify, tr("Spark\\ Store").toLocal8Bit(),
                                 s.toLocal8Bit(),
                                 icon);
  }

  notify_notification_show(_notify, nullptr);
}

void SpkUiMessage::SendStoreNotification(QString s) // TODO: IMPLEMENT IN-APP NOTIFICATION
{
  Q_UNUSED(s);
}

void SpkUiMessage::SetDesktopNotifyTimeout(int ms)
{
  if(!_notify)
    _notify = notify_notification_new("", "", "");
  notify_notification_set_timeout(_notify, ms);
  mTimeoutDesktop = ms;
}
