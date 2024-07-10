#ifndef BUCKETHEADZOMBIE_H
#define BUCKETHEADZOMBIE_H

#include "zombiebase.h"
#include"plantbase.h"

class BucketHeadZombie : public ZombieBase
{
public:
    //explicit BucketHeadZombie(QObject *parent = nullptr);
    BucketHeadZombie(QGraphicsScene *scene, QMap<int, QPair<QPointF, PlantBase*>> &plantMap,QMap<int, QPair<QPointF, ZombieBase*>> &zombieMap,int rect,QList<QRectF> gridRects,QMap<int,QPair<QPointF, QString>>& gridcenterMap);
public slots:
    void moveForward();
    void attackZombie();
    int ChangePosToRect(QPointF point);
private:
    QGraphicsScene *scene;
    QMap<int, QPair<QPointF, PlantBase*>> &plantMap;
    QMap<int, QPair<QPointF, ZombieBase*>> &zombieMap;
    QMovie *zombieMovie;
    int currentRect;
    QList<QRectF> gridRects;
    QMap<int,QPair<QPointF, QString>>& gridcenterMap;
};

#endif // BUCKETHEADZOMBIE_H
