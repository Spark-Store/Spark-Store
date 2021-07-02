
#pragma once

#include <QWidget>

class SpkDtkPlugin
{
  public:
    virtual ~SpkDtkPlugin() = default;

    virtual void addWindow(QWidget* w, QObject* parent) = 0;
};
QT_BEGIN_NAMESPACE
Q_DECLARE_INTERFACE(SpkDtkPlugin, "org.spark-store.client.dtkplugin")
QT_END_NAMESPACE
