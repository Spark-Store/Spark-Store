#include <DGuiApplicationHelper>
#include <DPlatformWindowHandle>
#include "spkdtkplugin_impl.h"

using Dtk::Widget::DPlatformWindowHandle;

void SpkDtkPluginImpl::addWindow(QWidget *w, QObject *parent)
{
  DPlatformWindowHandle *h = new DPlatformWindowHandle(w, parent);
  Q_UNUSED(h);
}
