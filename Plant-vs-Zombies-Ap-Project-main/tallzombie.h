#ifndef TALLZOMBIE_H
#define TALLZOMBIE_H

#include "zombiebase.h"
#include "plantbase.h"
#include<QMovie>
#include <QPropertyAnimation>
class TallZombie : public ZombieBase
{
public:
    //explicit TallZombie(QObject *parent = nullptr);
    TallZombie(QGraphicsScene *&scene, QMap<int, QPair<QPointF, PlantBase*>> &plantMap,QMap<int, QPair<QPointF, ZombieBase*>> &zombieMap,int rect,QList<QRectF> gridRects,QMap<int,QPair<QPointF, QString>>& gridcenterMap);
    Q_PROPERTY(QPointF pos READ pos WRITE setPos);
public slots:
    void moveForward();
    void attackZombie();
    int ChangePosToRect(QPointF point);

private:
    QGraphicsScene *&scene;
    QMap<int, QPair<QPointF, PlantBase*>> &plantMap;
    QMap<int, QPair<QPointF, ZombieBase*>> &zombieMap;
    QMovie *zombieMovie;
    int currentRect;
    QList<QRectF> gridRects;
    QMap<int,QPair<QPointF, QString>>& gridcenterMap;
};

#endif // TALLZOMBIE_H
