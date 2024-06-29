#ifndef CLICBRAIN_H
#define CLICBRAIN_H
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>
class BrainPixmapItem : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    BrainPixmapItem(const QPixmap &pixmap) : QGraphicsPixmapItem(pixmap) {num=0;}
    int get_num(){return num;}
protected:
    int num;


    void mousePressEvent(QGraphicsSceneMouseEvent *event) override
    {
        if (event->button() == Qt::LeftButton) {
            emit clicked();
            num+=25;
        }
        QGraphicsPixmapItem::mousePressEvent(event);
    }

signals:
    void clicked();
};
#endif // CLICBRAIN_H
