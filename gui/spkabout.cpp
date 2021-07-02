
#include "spkabout.h"

SpkAbout::SpkAbout(QWidget *parent) : SpkDialog(parent)
{
  setWindowModality(Qt::ApplicationModal);
}

void SpkAbout::Show()
{
  SpkAbout *b = new SpkAbout;

  b->GetTitleBar()->SetOperationButton(SpkTitleBar::OperationButton::Close);

  // TODO: Waiting for qygw

  b->Exec();
  delete b;
}
