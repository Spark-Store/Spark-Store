
#pragma once

#include <QTreeWidget>

namespace SpkUi
{
  class SpkSidebarTree : public QTreeWidget
  {
      Q_OBJECT
    public:
      SpkSidebarTree(QWidget* parent = nullptr);
    protected:
      void mouseMoveEvent(QMouseEvent *) override;
      void mousePressEvent(QMouseEvent *) override;
  };
}
