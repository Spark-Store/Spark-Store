
#include <QGuiApplication>
#include <QScreen>
#include <QJsonArray>
#include "spkmainwindow.h"
#include "spklogging.h"
#include "spkuimsg.h"

SpkMainWindow::SpkMainWindow(QWidget *parent) : SpkWindow(parent)
{
  ui = new SpkUi::SpkMainWidget(parent);

  SetUseTitleBar(false);
  SetCentralWidget(ui);
  SetTitleBar(ui->TitleBar, false);

  auto size = QGuiApplication::primaryScreen()->size() * 0.25;
  resize(QGuiApplication::primaryScreen()->size() * 0.5);
  move(size.width(), size.height());
}

void SpkMainWindow::PopulateCategories(QJsonObject aCategoryData)
{
  auto w = ui->CategoryWidget;
  if(!aCategoryData.contains("code"))
  {
    SpkUiMessage::SendStoreNotification(tr("Failed to load categories; return code lost."));
    return;
  }
  auto OpRetCode = aCategoryData.value("code");
  if(!OpRetCode.isDouble())
  {
    SpkUiMessage::SendStoreNotification(tr("Failed to load categories; invalid return code."));
    return;
  }
  if(OpRetCode.toDouble() != 0)
  {
    SpkUiMessage::SendStoreNotification(tr("Failed to load categories; operation failed: %1.")
                                        .arg(OpRetCode.toDouble()));
    return;
  }

  if(!aCategoryData.contains("data"))
  {
    SpkUiMessage::SendStoreNotification(tr("Failed to load categories; data lost."));
    return;
  }
  auto OpData = aCategoryData.value("data");
  if(!OpRetCode.isArray())
  {
    SpkUiMessage::SendStoreNotification(tr("Failed to load categories; invalid data."));
    return;
  }

  auto OpDataArr = OpData.toArray();
  foreach(auto i, OpDataArr)
  {
    if(i.isObject())
    {
      auto j = i.toObject();
      double typeId;
      QString typeName;
      if(j.contains("type_id") && j.value("type_id").isDouble())
        typeId = j.value("type_id").toDouble();
      else goto WRONG_CATEGORY;
      if(j.contains("type_name") && j.value("type_name").isString())
        typeName = j.value("type_name").toString();
      else goto WRONG_CATEGORY;
      w->AddButton(tr(typeName.toLocal8Bit()), typeId /* TODO: ICONS */);
      continue;
    }
    WRONG_CATEGORY:
    sLog("One category ignored because of invalid data");
  }
}

SpkUi::SpkMainWidget::SpkMainWidget(QWidget *parent) : QFrame(parent)
{
  setObjectName("spk_mainwidget");

  VLayCategoryButtons = new QVBoxLayout;
  VLayCategoryButtons->setObjectName("spk_mw_category_vlay");
  VLayCategoryButtons->addWidget(new QPushButton);

  Pager = new QStackedWidget(this);
  Pager->setObjectName("spk_mw_pager");
  Pager->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

  TitleBar = new SpkTitleBar(this);
  TitleBar->setObjectName("spk_mw_titlebar");
  TitleBar->SetTitle("Title");

  VLayMain = new QVBoxLayout;
  VLayMain->setObjectName("spk_mw_main_vlay");
  VLayMain->setSpacing(0);
  VLayMain->setContentsMargins(0, 0, 0, 0);
  VLayMain->addWidget(TitleBar);
  VLayMain->addWidget(Pager);

  CategoryWidget = new SpkCategorySelector(this);
  CategoryWidget->setObjectName("spk_mw_category");
  CategoryWidget->setLayout(VLayCategoryButtons);
  CategoryWidget->setAutoFillBackground(true);
  CategoryWidget->setMaximumWidth(300);
  CategoryWidget->setMinimumWidth(300);
  CategoryWidget->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);

  HorizontalDivide = new QHBoxLayout;
  HorizontalDivide->setObjectName("spk_mw_divide_hlay");
  HorizontalDivide->setSpacing(0);
  HorizontalDivide->setContentsMargins(0, 0, 0, 0);
  HorizontalDivide->setAlignment(Qt::AlignLeft);
  HorizontalDivide->addWidget(CategoryWidget);
  HorizontalDivide->addLayout(VLayMain);

  // Initialize pages
  PageQssTest = new SpkUi::SpkPageQssTest(this);
  Pager->addWidget(PageQssTest);

  setLayout(HorizontalDivide);
}
