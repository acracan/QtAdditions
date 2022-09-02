#include "dak/QtAdditions/QWidgetListItem.h"

#include <mutex>
#include <QPainter>
#include <QDebug>

namespace dak::QtAdditions
{
    using namespace std;

    QWidgetListItem::QWidgetListItem(QWidget* parent)
        : QWidget(parent)
    {
        setAutoFillBackground(false);
    }

    QWidgetListItem::~QWidgetListItem()
    {
    }

    void QWidgetListItem::select(bool sel)
    {
        _selected = sel;
        update();
    }

    QWidgetListItem* QWidgetListItem::clone() const
    {
        return new QWidgetListItem;
    }

    void QWidgetListItem::enterEvent(QEnterEvent *event)
    {
        QWidget::enterEvent(event);
        _hovered = true;
        update();
    }

    void QWidgetListItem::leaveEvent(QEvent* event)
    {
        QWidget::leaveEvent(event);
        _hovered = false;
        update();
    }

    void QWidgetListItem::paintEvent(QPaintEvent *e)
    {
        QPainter painter(this);

        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        if (_selected) {
            brush.setColor(palette().color(QPalette::Highlight));
        }
        else {
            brush.setColor(palette().color(QPalette::Window));
        }
        painter.fillRect(0, 0, width(), height(), brush);

        QWidget::paintEvent(e);

        if (_hovered) {

            QPen pen(palette().color(QPalette::Highlight).lighter(210));
            pen.setWidth(0);
            painter.setPen(pen);
            painter.drawRect(1, 1, width()-2, height()-2);
        }
    }
}

