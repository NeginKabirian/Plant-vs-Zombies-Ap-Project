#ifndef PURPLEHAIRZOMBIE_H
#define PURPLEHAIRZOMBIE_H

#include "zombiebase.h"
#include "plantbase.h"
#include<QMovie>
class PurpleHairZombie : public ZombieBase
{
public:
    //explicit PurpleHairZombie(QObject *parent = nullptr);
    PurpleHairZombie(QGraphicsScene *&scene, QMap<int, QPair<QPointF, PlantBase*>> &plantMap,QMap<int, QPair<QPointF, ZombieBase*>> &zombieMap,int rect,QList<QRectF> gridRects,QMap<int,QPair<QPointF, QString>>& gridcenterMap);
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

#endif // PURPLEHAIRZOMBIE_H
