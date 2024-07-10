#ifndef ASTRONAUTZOMBIE_H
#define ASTRONAUTZOMBIE_H

#include "zombiebase.h"
#include"plantbase.h"
class AstronautZombie : public ZombieBase
{
public:
    //explicit AstronautZombie(QObject *parent = nullptr);
    AstronautZombie(QGraphicsScene *&scene, QMap<int, QPair<QPointF, PlantBase*>> &plantMap,QMap<int, QPair<QPointF, ZombieBase*>> &zombieMap,int rect,QList<QRectF> gridRects,QMap<int,QPair<QPointF, QString>>& gridcenterMap);
private:
    const double MovmentDelaytwo = 0.5;
    const double TimeBetweenAttackstwo = 0.5;
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

#endif // ASTRONAUTZOMBIE_H
