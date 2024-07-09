/*#ifndef REGULARZAMBIE_H
#define REGULARZAMBIE_H

#include "zombiebase.h"

class RegularZambie : public ZombieBase
{
public:
    //explicit RegularZambie(QObject *parent = nullptr);
    RegularZambie();
};

#endif // REGULARZAMBIE_H*/

#ifndef REGULARZAMBIE_H
#define REGULARZAMBIE_H

#include "zombiebase.h"
#include "plantbase.h"
#include<QMovie>
class RegularZambie : public ZombieBase
{
public:
    //explicit RegularZambie(QObject *parent = nullptr);
    RegularZambie(QGraphicsScene *scene, QMap<int, QPair<QPointF, PlantBase*>> &plantMap,QMap<int, QPair<QPointF, ZombieBase*>> &zombieMap,int rect,QList<QRectF> gridRects,QMap<int,QPair<QPointF, QString>>& gridcenterMap);
public slots:
    void moveForward();
    void attackZombie();
    int ChangePosToRect(QPointF point);

private:
    QGraphicsScene *scene;
    QMap<int, QPair<QPointF, PlantBase*>> &plantMap;
    QMap<int, QPair<QPointF, ZombieBase*>> &zombieMap;
    QMovie *zombieMovie;
    QTimer *moveTimer;
    QTimer *attackTimer;
    int currentRect;
    QList<QRectF> gridRects;
    QMap<int,QPair<QPointF, QString>>& gridcenterMap;
};

#endif // REGULARZAMBIE_H
