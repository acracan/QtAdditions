#pragma once

#ifndef QT_ADDITIONS_QWIDGET_LIST_ITEM_H
#define QT_ADDITIONS_QWIDGET_LIST_ITEM_H

#include <QWidget>

namespace dak::QtAdditions
{
   /////////////////////////////////////////////////////////////////////////
   //
   // Complex widget kept in a list widget.

   struct QWidgetListItem : QWidget
   {
      // Create an item.
      QWidgetListItem(QWidget* parent = nullptr);
      ~QWidgetListItem();

      // Selection.
      bool isSelected() const { return _selected; }
      void select(bool sel);

      // Item cloning for drag-and-drop.
      virtual QWidgetListItem* clone() const;

   protected:
      // Used to draw highlights.
      void enterEvent(QEnterEvent* event) override;
      void leaveEvent(QEvent* event) override;
      void paintEvent(QPaintEvent *e) override;

      bool _selected = false;
      bool _hovered = false;

      Q_OBJECT;
   };
}

#endif
