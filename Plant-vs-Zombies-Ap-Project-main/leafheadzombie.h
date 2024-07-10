#ifndef LEAFHEADZOMBIE_H
#define LEAFHEADZOMBIE_H

#include "zombiebase.h"
#include "plantbase.h"
#include<QMovie>
class LeafHeadZombie : public ZombieBase
{
public:
    //explicit LeafHeadZombie(QObject *parent = nullptr);
    LeafHeadZombie(QGraphicsScene *&scene, QMap<int, QPair<QPointF, PlantBase*>> &plantMap, QMap<int, QPair<QPointF, ZombieBase*>> &zombieMap, int rect, QList<QRectF> gridRects, QMap<int, QPair<QPointF, QString>> &gridcenterMap);
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

#endif // LEAFHEADZOMBIE_H
