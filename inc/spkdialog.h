#ifndef SPKDIALOG_H
#define SPKDIALOG_H

#include <QList>
#include <QButtonGroup>
#include "spkui_general.h"
#include "spktitlebar.h"
#include "spkwindow.h"

class SpkDialog : public SpkWindow
{
    Q_OBJECT
  public:
    SpkDialog(QWidget *parent = nullptr);
    ~SpkDialog();
    void AddButton(QString text, SpkUi::SpkButtonStyle style = SpkUi::SpkButtonStyle::Normal);
    void AddWidget(QWidget*);
    void AddSpacing(int);
    int  Exec();

  private slots:
    void ButtonPressed(int);
    void ForceClose();

  signals:
    void ExitEventLoop(int);
    void CloseWindow();

  private:
    QWidget *mDialogWidget;
    QVBoxLayout *mMainVLay, *mWidgetsVLay;
    QHBoxLayout *mBtnLay;
    QButtonGroup *mBtnGroup;
    QList<QWidget*> mWidgetsList, mParentsList;
};

#endif // SPKDIALOG_H
