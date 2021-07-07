
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
  if(OpRetCode.toInt() != 0)
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
        // TODO
      continue;
    }
    WRONG_CATEGORY:
    sLog("One category ignored because of invalid data");
  }
}

SpkUi::SpkMainWidget::SpkMainWidget(QWidget *parent) : QFrame(parent)
{
  setObjectName("spk_mainwidget");

  QTreeWidgetItem *item;

  Pager = new QStackedWidget(this);
  Pager->setObjectName("spk_mw_pager");
  Pager->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

  TitleBar = new SpkTitleBar(this);
  TitleBar->setObjectName("spk_mw_titlebar");
  TitleBar->SetUseIcon(false);
  TitleBar->SetTitle("");

  VLayMain = new QVBoxLayout;
  VLayMain->setObjectName("spk_mw_main_vlay");
  VLayMain->setSpacing(0);
  VLayMain->setContentsMargins(0, 0, 0, 0);
  VLayMain->addWidget(TitleBar);
  VLayMain->addWidget(Pager);

  VLaySidebar = new QVBoxLayout;
  VLaySidebar->setObjectName("spk_mw_sidebar_lay");
  VLaySidebar->setSpacing(0);
  VLaySidebar->setContentsMargins(0, 0, 0, 0);

  SideBarRestrictor = new QWidget(this);
  SideBarRestrictor->setObjectName("spk_mw_sidebar_restrictor");
  SideBarRestrictor->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
  SideBarRestrictor->setMaximumWidth(300);
  SideBarRestrictor->setMinimumWidth(300);
  SideBarRestrictor->setLayout(VLaySidebar);

  HLaySideTop = new QHBoxLayout;
  HLaySideTop->setObjectName("spk_mw_sidebar_top_lay");
  HLaySideTop->setSpacing(8);
  HLaySideTop->setContentsMargins(8, 4, 4, 4);

  StoreIcon = new QLabel(this);
  StoreIcon->setObjectName("spk_mw_icon");
  StoreIcon->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  StoreIcon->setMaximumSize({ 48, 48 });
  StoreIcon->setMinimumSize({ 48, 48 });
  StoreIcon->setPixmap(QIcon(":/icons/spark-store.svg").pixmap(StoreIcon->size()));

  SidebarMgr = new SpkSidebarSelector(this);
  SidebarMgr->setObjectName("spk_mw_sidebar_mgr");

  BtnSettings = new QPushButton(this);
  BtnSettings->setObjectName("spk_styling_plaincheckbtn");
  BtnSettings->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  BtnSettings->setCheckable(true);
  BtnSettings->setMaximumSize({ 48, 48 });
  BtnSettings->setMinimumSize({ 48, 48 });
  BtnSettings->setIconSize(QSize(24, 24));
  BtnSettings->setIcon(SpkUi::GetThemedIcon("settings"));
  BtnSettings->setProperty("spk_pageno", 0);
  SidebarMgr->BindPageSwitcherButton(BtnSettings);

  HLaySideTop->addWidget(StoreIcon);
  HLaySideTop->addStretch();
  HLaySideTop->addWidget(BtnSettings);
  VLaySidebar->addLayout(HLaySideTop);

  CategoryWidget = new QTreeWidget(this);
  CategoryWidget->setObjectName("spk_mw_category");
  CategoryWidget->setAutoFillBackground(true);
  CategoryWidget->setColumnCount(1);
  CategoryWidget->setHeaderHidden(true);
  CategoryWidget->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
  item = new QTreeWidgetItem(QStringList("Placeholder"));
  item->setData(0, Qt::UserRole + 1, 1);
  item->setData(0, Qt::UserRole + 2, 1);
  CategoryWidget->addTopLevelItem(item);
  // FIXMEIFPOSSIBLE: Fusion adds extra gradient.
  // Details: https://forum.qt.io/topic/128190/fusion-style-kept-adding-an-extra-
  // layer-of-gradient-to-my-selected-item-of-qtreewidget-even-with-qss
  if(SpkUi::OldSystemStyle)
    CategoryWidget->setStyle(SpkUi::OldSystemStyle);
  VLaySidebar->addWidget(CategoryWidget);
  SidebarMgr->BindCategoryWidget(CategoryWidget);

  HorizontalDivide = new QHBoxLayout;
  HorizontalDivide->setObjectName("spk_mw_divide_hlay");
  HorizontalDivide->setSpacing(0);
  HorizontalDivide->setContentsMargins(0, 0, 0, 0);
  HorizontalDivide->setAlignment(Qt::AlignLeft);
  if(!SpkUi::States::IsUsingDtkPlugin)
    HorizontalDivide->addSpacing(SpkWindow::BorderWidth);
  HorizontalDivide->addWidget(SideBarRestrictor);
  HorizontalDivide->addLayout(VLayMain);

  // Initialize pages
  PageQssTest = new SpkUi::SpkPageQssTest(this);
  Pager->addWidget(PageQssTest);

  setLayout(HorizontalDivide);
}
