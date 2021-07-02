#pragma once

#include <QStyle>
#include <QMessageBox>
#include "spkdialog.h"

class SpkMsgBox : public SpkDialog
{
    Q_OBJECT
  public:
    SpkMsgBox(QWidget *parent = nullptr);
    static int StaticExec(QString msg, QString title, QMessageBox::Icon = QMessageBox::NoIcon,
                           QMessageBox::StandardButtons = QMessageBox::Ok, QString extra = "");
  private:
    static void AddButtons(SpkMsgBox *me, QMessageBox::StandardButtons b);
    QList<QMessageBox::StandardButton> mButtonList;
    static constexpr QSize IconSize {48, 48};
    static constexpr int Margin = 10;
};
