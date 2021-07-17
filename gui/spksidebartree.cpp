
#include <QMouseEvent>
#include "spksidebartree.h"

SpkUi::SpkSidebarTree::SpkSidebarTree(QWidget *parent) :
  QTreeWidget(parent)
{

}

void SpkUi::SpkSidebarTree::mouseMoveEvent(QMouseEvent *e)
{
  // This is solely for forcibly  disabling the view to change selection when dragging on the view
  // and probably the only reason why this class began its existence
  if((e->buttons() & Qt::LeftButton))
    setState(NoState);
  else
    QTreeWidget::mouseMoveEvent(e);
}

void SpkUi::SpkSidebarTree::mousePressEvent(QMouseEvent *e)
{
  // Prevent anything being deselected
  if(e->modifiers().testFlag(Qt::ControlModifier) && e->buttons().testFlag(Qt::LeftButton))
  {
    auto i = itemAt(e->pos());
    if(i && i->isSelected())
      return;
  }
  QTreeWidget::mousePressEvent(e);
}
