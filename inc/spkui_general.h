//
// Created by rigoligo on 2021/5/8.
//

#pragma once

#include <QWidget>
#include <QString>
#include <QSize>
#include <QColor>

#include "dtkplugin/spkdtkplugin.h"

namespace SpkUi
{
  enum SpkUiStyle { Light, Dark };
  enum SpkButtonStyle { Normal = 0, Recommend, Warn };

  constexpr int StackTraceArraySize = 64;
  constexpr const char * const StoreIconName = "spark-store";

  extern SpkUiStyle CurrentStyle;
  extern QString StylesheetBase, CurrentStylesheet;
  extern QColor ColorLine, ColorBack;
  extern QSize PrimaryScreenSize;
  extern SpkDtkPlugin *DtkPlugin;
  extern QStyle *OldSystemStyle;

  namespace Priv
  {
    extern bool CrashHandlerActivated;
  }

  void Initialize();
  void GuessAppropriateTheme();
  void PrepareForDeepinDesktop();
  bool CheckIsDeepinDesktop();
  QString StylesheetFromColors(QList<QColor>);

  QIcon GetThemedIcon(QString);
  QColor ColorTextOnBackground(QColor);

  void CrashSignalHandler(int);

  void SetGlobalStyle(SpkUiStyle);
};
