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
  constexpr int StackTraceArraySize = 64;
  constexpr const char * const StoreIconName = "spark-store";

  extern QString StylesheetLight, StylesheetDark, *CurrentStylesheet;
  extern QColor ColorLine, ColorBack;
  extern QSize PrimaryScreenSize;
  extern SpkDtkPlugin *DtkPlugin;
  enum SpkUiStyle { Light, Dark };
  enum SpkButtonStyle { Normal = 0, Recommend, Warn };

  namespace Priv
  {
    extern bool CrashHandlerActivated;
  }

  void Initialize();
  void GuessAppropriateTheme();
  void PrepareForDeepinDesktop();
  bool CheckIsDeepinDesktop();

  void CrashSignalHandler(int);

  void SetGlobalStyle(SpkUiStyle);
};
