#include <QApplication>
#include <QPushButton>
#include <spklogging.h>
#include "spkwindow.h"
#include "spkui_general.h"
#include "spkstore.h"

#include <QFile>
#include "spkmsgbox.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  QString LogPath = "";

  SpkStore store(false, LogPath);

  SpkMsgBox::StaticExec("E", "F");

  return QApplication::exec();
}
