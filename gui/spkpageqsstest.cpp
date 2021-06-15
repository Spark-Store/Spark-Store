
#include <QApplication>
#include "spkpageqsstest.h"
#include "spkui_general.h"

SpkUi::SpkPageQssTest::SpkPageQssTest(QWidget *parent) : QSplitter(parent)
{
  setObjectName("spk_pg_qsstest");

  TextStylesheet = new QTextEdit(this);
  TextStylesheet->setObjectName("spk_pg_qsstest_qsstext");
  TextStylesheet->setPlainText(*SpkUi::CurrentStylesheet);

  BtnApply = new QPushButton(this);
  BtnApply->setObjectName("spk_pg_qsstest_btnapply");
  BtnApply->setText("Apply");
  connect(BtnApply, &QPushButton::pressed, this, &SpkPageQssTest::SetStylesheet);

  BtnFetch = new QPushButton(this);
  BtnFetch->setObjectName("spk_pg_qsstest_btnfetch");
  BtnFetch->setText("Fetch Stylesheet");
  connect(BtnFetch, &QPushButton::pressed, this, &SpkPageQssTest::FetchStylesheet);

  HLayInputBtns = new QHBoxLayout;
  HLayInputBtns->setObjectName("spk_pg_qsstest_hlay_inputbtns");
  HLayInputBtns->addWidget(BtnFetch);
  HLayInputBtns->addWidget(BtnApply);

  Btn = new QPushButton(this);
  Btn->setObjectName("spk_pg_qsstest_button");
  Btn->setText("TestButton");

  Chk = new QCheckBox(this);
  Chk->setObjectName("spk_pg_qsstest_checkbox");
  Chk->setText("CheckBox");

  Rad = new QRadioButton(this);
  Rad->setObjectName("spk_pg_qsstest_radiobtn");
  Rad->setText("RadioButton");

  SlideV = new QSlider(this);
  SlideV->setObjectName("spk_pg_qsstest_slider_v");
  SlideV->setOrientation(Qt::Vertical);
  SlideV->setMaximum(1000);
  SlideV->setMinimum(0);

  SlideH = new QSlider(this);
  SlideH->setObjectName("spk_pg_qsstest_slider_h");
  SlideH->setOrientation(Qt::Horizontal);
  SlideH->setMaximum(1000);
  SlideH->setMinimum(0);

  VLayBtn = new QVBoxLayout;
  VLayBtn->setObjectName("spk_pg_qsstest_vlay_btn");
  VLayBtn->addWidget(Btn);
  VLayBtn->addWidget(Chk);
  VLayBtn->addWidget(Rad);

  Group = new QGroupBox(this);
  Group->setObjectName("spk_pg_qsstest_groupbox");
  Group->setTitle("GroupBox");
  Group->setLayout(VLayBtn);

  VLayInput = new QVBoxLayout;
  VLayInput->setObjectName("spk_pg_qsstest_inputlay");
  VLayInput->addWidget(TextStylesheet);
  VLayInput->addLayout(HLayInputBtns);

  VLayWidgets = new QVBoxLayout;
  VLayWidgets->setObjectName("spk_pg_qsstest_widgetlay");
  VLayWidgets->addWidget(Group);
  VLayWidgets->addWidget(SlideH);

  HLay4Slider = new QHBoxLayout;
  HLay4Slider->setObjectName("spk_pg_qsstest_hlay_for_slider");
  HLay4Slider->addLayout(VLayWidgets);
  HLay4Slider->addWidget(SlideV);

  WidL = new QWidget(this);
  WidL->setObjectName("spk_pg_qsstest_widleft");
  WidL->setLayout(HLay4Slider);

  WidR = new QWidget(this);
  WidR->setObjectName("spk_pg_qsstest_widright");
  WidR->setLayout(VLayInput);

  addWidget(WidL);
  addWidget(WidR);
}

void SpkUi::SpkPageQssTest::SetStylesheet()
{
  qApp->setStyleSheet(TextStylesheet->toPlainText());
}

void SpkUi::SpkPageQssTest::FetchStylesheet()
{
  TextStylesheet->setPlainText(*SpkUi::CurrentStylesheet);
}
