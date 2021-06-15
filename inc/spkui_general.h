//
// Created by rigoligo on 2021/5/8.
//

#ifndef _SPKUI_GENERAL_H_
#define _SPKUI_GENERAL_H_

#include <QString>
#include <QSize>
#include <QColor>

namespace SpkUi
{
  constexpr int StackTraceArraySize = 64;
  constexpr const char * const StoreIconName = "spark-store";

  extern QString StylesheetLight, StylesheetDark, *CurrentStylesheet;
  extern QColor ColorLine, ColorBack;
  extern QSize PrimaryScreenSize;
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

#endif //_SPKUI_GENERAL_H_
