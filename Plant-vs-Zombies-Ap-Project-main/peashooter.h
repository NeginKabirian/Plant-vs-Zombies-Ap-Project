/*#ifndef PEASHOOTER_H
#define PEASHOOTER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>
#include <QDebug>

class PeaShooter : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)

public:
    PeaShooter();

private slots:
    void returnToOriginalPosition();

private:
    QPropertyAnimation* shakeAnimation;
};

#endif // PEASHOOTER_H*/
