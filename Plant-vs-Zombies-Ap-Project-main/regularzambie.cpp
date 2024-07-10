/*#include "regularzambie.h"
#include <QGraphicsScene>
#include <peashooter.h>
#include<two_peashooter.h>
#include<boomerang.h>
/*RegularZambie::RegularZambie(QObject *parent)
    : ZombieBase{parent}
{}//
int RegularZambie::ChangePosToRect(QPointF point)
{
    int current;
    /*if(currentRect<12){
        return current + 1;
    }
    qDebug()<<gridRects.size();
    for(int i = 0; i < gridRects.size();++i){
        if(gridRects[i].contains(point)){
             //qDebug()<<i;
            current = i;
            return current;
        }
    }
    return -1;
}

RegularZambie::RegularZambie(QGraphicsScene *scene, QMap<int, QPair<QPointF, PlantBase *> > &plantMap, QMap<int, QPair<QPointF, ZombieBase *> > &zombieMap, int rect, QList<QRectF> gridRects, QMap<int, QPair<QPointF, QString> > &gridcenterMap) : ZombieBase(500,1,25,1,100) , scene(scene), plantMap(plantMap), zombieMap(zombieMap),currentRect(rect),gridRects(gridRects),gridcenterMap(gridcenterMap)
{
    zombieMovie = new QMovie(":/image/regular zombie_transparent.png");
    setPixmap(zombieMovie->currentPixmap());
    setScale(0.08);
    connect(zombieMovie, &QMovie::frameChanged, this, [=]() {
        setPixmap(zombieMovie->currentPixmap());
    });
    zombieMovie->start();

    moveTimer = new QTimer(this);
    connect(moveTimer, &QTimer::timeout, this, &RegularZambie::moveForward);
    moveTimer->start(1000);

    attackTimer = new QTimer(this);
    connect(attackTimer, &QTimer::timeout, this, &RegularZambie::attackZombie);
}

void RegularZambie::moveForward(){
    qDebug()<<currentRect<<"rect"<<ChangePosToRect(this->pos());
    int rect = ChangePosToRect(this->pos());

        setPos(x() -41, y());
        if(currentRect != rect && rect != -1){
            zombieMap[rect].second = zombieMap[currentRect].second;
            zombieMap.remove(currentRect);
            gridcenterMap[currentRect].second = "";
            gridcenterMap[rect].second = "ZA";
            currentRect = rect;
        }

    if(dynamic_cast<PlantBase*>(plantMap[rect].second) || dynamic_cast<PlantBase*>(plantMap[rect - 1].second)){
        moveTimer->stop();
        attackTimer->start(1000);
        //qDebug()<<currentRect;
    }
    // Printing plantMap
    qDebug() << "Printing plantMap:";
    for (auto it = plantMap.constBegin(); it != plantMap.constEnd(); ++it) {
        int key = it.key();
        QPointF position = it.value().first;
        //PlantBase* plant = it.value().second;
        qDebug() << "Key:" << key << "Position:" << position << "Plant:" ;//<< plant;
    }

    // Printing zombieMap
    qDebug() << "Printing zombieMap:";
    for (auto it = zombieMap.constBegin(); it != zombieMap.constEnd(); ++it) {
        int key = it.key();
        QPointF position = it.value().first;
        ZombieBase* zombie = it.value().second;
        qDebug() << "Key:" << key << "Position:" << position ;// "Zombie:" //<< zombie;
    }

    // Printing gridcenterMap
    qDebug() << "Printing gridcenterMap:";
    for (auto it = gridcenterMap.constBegin(); it != gridcenterMap.constEnd(); ++it) {
        int key = it.key();
       // QPointF position = it.value().first;
        QString description = it.value().second;
        qDebug() << "Key:" << key  << "Description:" << description;
    }
}

void RegularZambie::attackZombie()
{
    bool stop = false;
    if(this->getHealth() < 0){
        attackTimer->stop();
        moveTimer->start(1000);
        return;
    }
    if (plantMap.contains(currentRect - 1)) {
        PlantBase* targetPlant = dynamic_cast<PlantBase*>(plantMap[currentRect - 1].second);
        if (targetPlant) {
            //qDebug() << currentRect - 1 << gridcenterMap[currentRect - 1].second << this->AttackPower << targetPlant->getHealth();
            if (targetPlant->getHealth() > 0 && !stop) {
                targetPlant->setHealth(targetPlant->getHealth() - this->AttackPower);
            }
            else{

                if(dynamic_cast<Peashooter*>(plantMap[currentRect - 1].second)){
                   Peashooter* p = dynamic_cast<Peashooter*>(plantMap[currentRect - 1].second);
                    p->stopShooting();
                }
                else if(dynamic_cast<Two_Peashooter*>(plantMap[currentRect - 1].second)){
                    Two_Peashooter* p = dynamic_cast<Two_Peashooter*>(plantMap[currentRect - 1].second);
                    p->stopShooting();
                }
                else if(dynamic_cast<Boomerang*>(plantMap[currentRect - 1].second)){
                    Boomerang* p = dynamic_cast<Boomerang*>(plantMap[currentRect - 1].second);
                    p->stopShooting();
                }
                scene->removeItem(targetPlant);
                qDebug()<<currentRect - 1;
                //qDebug() <<"hey" <<gridcenterMap[targetPlant.key()].second;
                gridcenterMap[currentRect - 1].second = "";
                plantMap.remove(currentRect - 1);
                attackTimer->stop();
                stop  = true;
            }
        }
    }

    if (!dynamic_cast<PlantBase*>(plantMap[currentRect - 1].second)) {
        attackTimer->stop();
        moveTimer->start(1000);
        stop  = true;
        return;
    }

}*/
#include "regularzambie.h"
#include <QGraphicsScene>
#include <peashooter.h>
#include <two_peashooter.h>
#include <boomerang.h>
#include<plummine.h>

int RegularZambie::ChangePosToRect(QPointF point)
{
    int current = -1; // Initialize current to -1 to handle cases where point is not in any rect
    for (int i = 0; i < gridRects.size(); ++i) {
        if (gridRects[i].contains(point)) {
            current = i;
            return current;
        }
    }
    return current;
}

RegularZambie::RegularZambie(QGraphicsScene *scene, QMap<int, QPair<QPointF, PlantBase*>> &plantMap, QMap<int, QPair<QPointF, ZombieBase*>> &zombieMap, int rect, QList<QRectF> gridRects, QMap<int, QPair<QPointF, QString>> &gridcenterMap)
    : ZombieBase(500, 1, 25, 1, 100), scene(scene), plantMap(plantMap), zombieMap(zombieMap), currentRect(rect), gridRects(gridRects), gridcenterMap(gridcenterMap)
{
    zombieMovie = new QMovie(":/image/regular zombie_transparent.png");
    setPixmap(zombieMovie->currentPixmap());
    setScale(0.08);
    connect(zombieMovie, &QMovie::frameChanged, this, [=]() {
        setPixmap(zombieMovie->currentPixmap());
    });
    zombieMovie->start();

    moveTimer = new QTimer(this);
    connect(moveTimer, &QTimer::timeout, this, &RegularZambie::moveForward);
    moveTimer->start(1000);

    attackTimer = new QTimer(this);
    connect(attackTimer, &QTimer::timeout, this, &RegularZambie::attackZombie);
}

void RegularZambie::moveForward()
{
    qDebug() << currentRect << "rect" << ChangePosToRect(this->pos());
    int rect = ChangePosToRect(this->pos());
    setPos(x() - 41, y());
    if (currentRect != rect && rect != -1) {
            zombieMap[rect].second = zombieMap[currentRect].second;
            zombieMap.remove(currentRect);
            gridcenterMap[currentRect].second = "";
            gridcenterMap[rect].second = "ZA";
            currentRect = rect;
        }

    if ((rect != -1 && plantMap.contains(rect) && dynamic_cast<PlantBase*>(plantMap[rect].second)) ||
            (rect - 1 != -1 && plantMap.contains(rect - 1) && dynamic_cast<PlantBase*>(plantMap[rect - 1].second))) {
            if(dynamic_cast<PlumMine*>(plantMap[rect - 1].second)){
            qDebug()<<"oo";
            }
            moveTimer->stop();
            attackTimer->start(1000);
         }

    // Printing plantMap
    //qDebug() << "Printing plantMap:";
    /*for (auto it = plantMap.constBegin(); it != plantMap.constEnd(); ++it) {
        int key = it.key();
        QPointF position = it.value().first;
        qDebug() << "Key:" << key << "Position:" << position << "Plant:";
    }*/

    // Printing zombieMap
    //qDebug() << "Printing zombieMap:";

    /*for (auto it = zombieMap.constBegin(); it != zombieMap.constEnd(); ++it) {
>>>>>>> 50c3e84b67d613b3a3995012e47775f1fc0ad04f
        int key = it.key();
        QPointF position = it.value().first;
        ZombieBase* zombie = it.value().second;
        qDebug() << "Key:" << key << "Position:" << position;
    }

    // Printing gridcenterMap
    qDebug() << "Printing gridcenterMap:";
    for (auto it = gridcenterMap.constBegin(); it != gridcenterMap.constEnd(); ++it) {
        int key = it.key();
        QString description = it.value().second;
        qDebug() << "Key:" << key << "Description:" << description;
    }

    }*/

}

void RegularZambie::attackZombie()
{
    if (this->getHealth() <= 0) {
        attackTimer->stop();
        moveTimer->start(1000);
        return;
    }

    bool stop = false;

    if (plantMap.contains(currentRect - 1)) {
        PlantBase* targetPlant = dynamic_cast<PlantBase*>(plantMap[currentRect - 1].second);
        if (targetPlant) {
            if (targetPlant->getHealth() > 0 && !stop) {
                 qDebug()<<"before"<<targetPlant->getHealth();
                targetPlant->setHealth(targetPlant->getHealth() - this->AttackPower);
                qDebug()<<"after"<<targetPlant->getHealth();
            } else {
                if (dynamic_cast<Peashooter*>(targetPlant)) {
                    dynamic_cast<Peashooter*>(targetPlant)->stopShooting();
                    dynamic_cast<Peashooter*>(targetPlant)->remove = true;

                } else if (dynamic_cast<Two_Peashooter*>(targetPlant)) {
                    dynamic_cast<Two_Peashooter*>(targetPlant)->stopShooting();
                     dynamic_cast<Two_Peashooter*>(targetPlant)->remove = true;
                } else if (dynamic_cast<Boomerang*>(targetPlant)) {
                    dynamic_cast<Boomerang*>(targetPlant)->stopShooting();
                    dynamic_cast<Boomerang*>(targetPlant)->remove = true;
                }
                scene->removeItem(targetPlant);
                gridcenterMap[currentRect - 1].second = "";
                plantMap.remove(currentRect - 1);
                attackTimer->stop();
                stop = true;
            }
        }
    }

    if (!plantMap.contains(currentRect - 1) || !dynamic_cast<PlantBase*>(plantMap[currentRect - 1].second)) {
        attackTimer->stop();
        moveTimer->start(1000);
        stop = true;
        return;
    }
}



