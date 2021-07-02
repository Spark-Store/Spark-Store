
#pragma once

#include <QWidget>
#include <QtPlugin>
#include "spkdtkplugin.h"

class SpkDtkPluginImpl : public QObject, SpkDtkPlugin
{
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "org.spark-store.client.dtkplugin")
  Q_INTERFACES(SpkDtkPlugin)

  public:
    void addWindow(QWidget* w, QObject* parent) override;
};
