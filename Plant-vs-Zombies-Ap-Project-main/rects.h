#ifndef RECTS_H
#define RECTS_H
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

class ClickableRectItem : public QGraphicsRectItem
{
public:
    ClickableRectItem( QGraphicsItem *parent = nullptr)
        : QGraphicsRectItem(parent){}

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override
    {
        if (event->button() == Qt::LeftButton)
        {
            emit clicked();
        }
        QGraphicsRectItem::mousePressEvent(event);
    }


signals:
    void clicked();
};

#endif // RECTS_H
