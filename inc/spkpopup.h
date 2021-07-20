
#pragma once

#include <QLabel>
#include <QWidget>
#include <QHBoxLayout>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>

class SpkMainWindow;

namespace SpkUi
{
  class SpkPopup : public QWidget
  {
      Q_OBJECT
    public:
      SpkPopup(QWidget *parent, int aMillis = 3000);

    public slots:
      void Show(QString aText);

    private:
      QPoint MoveOffset;
      QLabel *mText;
      QHBoxLayout *mBox;
      QPropertyAnimation *mAnimFadeIn, *mAnimFadeOut;
      QSequentialAnimationGroup *mAnim;
  };
}
