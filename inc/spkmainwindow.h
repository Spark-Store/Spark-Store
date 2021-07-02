//
// Created by rigoligo on 2021/5/9.
//

#pragma once

#include "spkwindow.h"
#include <QTextEdit>
#include <QStackedWidget>
#include <QButtonGroup>
#include <QJsonObject>
#include "spkpageqsstest.h"

namespace SpkUi
{ 
  class SpkCategoryButton : public QPushButton
  {
      Q_OBJECT
    public:
      SpkCategoryButton(QWidget *parent = nullptr);
      void SetIcon(QPixmap);
      void SetText(QString);
      static constexpr int Spacing = 8;
    private:
      QHBoxLayout *mLayout;
      QLabel *mIcon, *mText;
  };
  class SpkCategorySelector : public QWidget
  {
      Q_OBJECT
    public:
      SpkCategorySelector(QWidget *parent = nullptr);

      void AddButton(QString aBtnText, int aCategoryId = 0, QPixmap *aBtnIcon = nullptr);
      void DeleteAllButtons();

    signals:
      void CategorySelected(int);

    private:
      QVBoxLayout *mBtnLayout;
      QButtonGroup *mGroup;
      QList<SpkCategoryButton*> mBtnList;
  };
  
  class SpkMainWidget : public QFrame
  {
      Q_OBJECT
    public:
      SpkMainWidget(QWidget *parent = nullptr);

      QHBoxLayout *HorizontalDivide;
      SpkCategorySelector *CategoryWidget;
      QVBoxLayout *VLayCategoryButtons,
                  *VLayMain;
      SpkTitleBar *TitleBar;

      QStackedWidget *Pager;

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
