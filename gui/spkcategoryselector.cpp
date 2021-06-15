
#include "spkmainwindow.h"

namespace SpkUi
{
  SpkCategorySelector::SpkCategorySelector(QWidget *parent) : QWidget(parent)
  {
    mBtnLayout = new QVBoxLayout(this);
    mGroup = new QButtonGroup(this);
  }

  void SpkCategorySelector::AddButton(QString aBtnText, int aCategoryId, QPixmap *aBtnIcon)
  {
    auto btn = new SpkCategoryButton(this);
    btn->SetText(aBtnText);
    if(aBtnIcon)
      btn->SetIcon(*aBtnIcon);
    mBtnList.append(btn);
    mGroup->addButton(btn, aCategoryId ? aCategoryId : -1);
    mBtnLayout->addWidget(btn);
  }

  void SpkCategorySelector::DeleteAllButtons() // TODO: UNTESTED
  {
    foreach (auto i, mBtnList)
    {
      mBtnLayout->removeWidget(i);
      mGroup->removeButton(i);
      i->deleteLater();
    }
    mBtnList.clear();
  }

  SpkCategoryButton::SpkCategoryButton(QWidget *parent) : QPushButton(parent)
  {
    mIcon = new QLabel(this);
    mIcon->setObjectName("spk_categorybtn_label");
    mText = new QLabel(this);
    mText->setObjectName("spk_categorybtn_text");
    mLayout = new QHBoxLayout;
    mLayout->setObjectName("spk_categorybtn_lay");
    mLayout->addSpacing(Spacing);
    mLayout->addWidget(mIcon);
    mLayout->addSpacing(Spacing);
    mLayout->addStretch();
    mLayout->addWidget(mText);
    mLayout->addStretch();
    mLayout->addSpacing(Spacing);
    setLayout(mLayout);
  }

  void SpkCategoryButton::SetIcon(QPixmap aImage)
  {
    mIcon->setPixmap(aImage);
  }

  void SpkCategoryButton::SetText(QString aText)
  {
    mText->setText(aText);
  }
}
