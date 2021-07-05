//
// Created by rigoligo on 2021/5/9.
//

#pragma once

#include "spkwindow.h"
#include <QTextEdit>
#include <QStackedWidget>
#include <QButtonGroup>
#include <QJsonObject>
#include <QTreeWidget>
#include "spkpageqsstest.h"

namespace SpkUi
{
  class SpkSidebarSelector : public QObject
  {
      Q_OBJECT
    private:
      QPushButton *mLastCheckedBtn;
      QTreeWidgetItem *mLastSelectedItem;
      QTreeWidget *mCategoryWidget;

    public:
      SpkSidebarSelector(QObject *parent = nullptr) : QObject(parent)
      {
        mLastCheckedBtn = nullptr;
        mLastSelectedItem = nullptr;
      }
      // Tree item can either represent a page or a category, data of special roles
      // help identify them; Buttons instead can only represent a page
      constexpr static int RoleItemIsCategory = Qt::UserRole + 1;
      constexpr static int RoleItemCategoryPageId= Qt::UserRole + 2;
      void BindPageSwitcherButton(QAbstractButton* w)
      {
        connect(w, &QAbstractButton::pressed,
                this, &SpkSidebarSelector::ButtonPressed);
      }
      void BindCategoryWidget(QTreeWidget* w)
      {
        mCategoryWidget = w;
        connect(w, &QTreeWidget::itemPressed, this,
                &SpkSidebarSelector::TreeItemSelected);
      }

    private slots:
      // We assume the objects in interest all have the correct properties
      void ButtonPressed()
      {
        auto b = qobject_cast<QPushButton*>(sender());
        if(mLastCheckedBtn)
        {
          if(mLastCheckedBtn != b)
          {
            mLastCheckedBtn->setChecked(false);
            mLastCheckedBtn = nullptr;
          }
          else
            // QUESTIONABLE:
            // Apparently for checkable buttons, Qt flip their checked property AFTER
            // this slot function. So to prevent a checkable button being unchecked,
            // we set it to unchecked here. Qt will flip it back to checked later.
            b->setChecked(false);
        }
        else if(mLastSelectedItem)
        {
          mLastSelectedItem->setSelected(false);
          mLastSelectedItem = nullptr;
        }
        mLastCheckedBtn = b;
        emit SwitchToPage(b->property("spk_pageno").toInt());
      }
      void TreeItemSelected(QTreeWidgetItem *item, int column)
      {
        if(mLastCheckedBtn)
        {
          mLastCheckedBtn->setChecked(false);
          mLastCheckedBtn = nullptr;
        }
        mLastSelectedItem = item;
        if(item->data(column, RoleItemIsCategory).toBool())
          emit SwitchToCategory(item->data(column, RoleItemCategoryPageId).toInt());
        else
          emit SwitchToPage(item->data(column, RoleItemCategoryPageId).toInt());
      }

    signals:
      void SwitchToCategory(int aCategoryId);
      void SwitchToPage(int aPageId);
  };

  class SpkMainWidget : public QFrame
  {
      Q_OBJECT

    public:
      SpkMainWidget(QWidget *parent = nullptr);

      QHBoxLayout *HorizontalDivide;
      QVBoxLayout *VLayMain;
      SpkTitleBar *TitleBar;

      QStackedWidget *Pager;

      // Category widget is for switching pages
      QWidget *SideBarRestrictor;
      QVBoxLayout *VLaySidebar;
      QHBoxLayout *HLaySideTop;
      QLabel *StoreIcon;
      QPushButton *BtnSettings, *BtnFeedback, *BtnLogs;
      QTreeWidget *CategoryWidget;
      QMap<int, QTreeWidgetItem> *CategoryItemMap;
      SpkSidebarSelector *SidebarMgr;

      //Pages
      SpkPageQssTest *PageQssTest;
  };
}

class SpkMainWindow : public SpkWindow
{
    Q_OBJECT
  private:
    SpkUi::SpkMainWidget *ui;

  public:
    SpkMainWindow(QWidget *parent = nullptr);
    
    void PopulateCategories(QJsonObject);
};
