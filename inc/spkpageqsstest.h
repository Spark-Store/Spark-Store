#pragma once

#include <QWidget>
#include <QSplitter>
#include <QPushButton>
#include <QRadioButton>
#include <QCheckBox>
#include <QGroupBox>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSlider>

#include "spkloading.h"

namespace SpkUi
{
  class SpkPageQssTest : public QSplitter
  {
      Q_OBJECT
    public:
      SpkPageQssTest(QWidget *parent = nullptr);
      QWidget *WidL, *WidR;
      QVBoxLayout *VLayWidgets,
                  *VLayBtn,
                  *VLayInput;
      QHBoxLayout *HLay4Slider,
                  *HLayInputBtns;
      QTextEdit *TextStylesheet;
      QPushButton *BtnApply;
      QPushButton *BtnFetch;

      QPushButton *Btn;
      QCheckBox *Chk;
      QRadioButton *Rad;
      QGroupBox *Group;
      QSlider *SlideH;
      QSlider *SlideV;
      SpkLoading *Loading;

    public slots:
      void SetStylesheet();
      void FetchStylesheet();
  };
}
