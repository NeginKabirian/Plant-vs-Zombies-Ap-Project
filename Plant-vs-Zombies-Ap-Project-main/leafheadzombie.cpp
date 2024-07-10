#include "leafheadzombie.h"
#include <QMovie>
#include <QGraphicsScene>
#include <peashooter.h>
#include <two_peashooter.h>
#include <boomerang.h>
#include<plummine.h>
/*LeafHeadZombie::LeafHeadZombie(QObject *parent)
    : ZombieBase{parent}
{}*/

int LeafHeadZombie::ChangePosToRect(QPointF point)
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

LeafHeadZombie::LeafHeadZombie(QGraphicsScene *&scene, QMap<int, QPair<QPointF, PlantBase*>> &plantMap, QMap<int, QPair<QPointF, ZombieBase*>> &zombieMap, int rect, QList<QRectF> gridRects, QMap<int, QPair<QPointF, QString>> &gridcenterMap)
    : ZombieBase(800,25), scene(scene), plantMap(plantMap), zombieMap(zombieMap), currentRect(rect), gridRects(gridRects), gridcenterMap(gridcenterMap)
{
    zombieMovie = new QMovie(":/image/leaf hair zombie_transparent.png");
    setPixmap(zombieMovie->currentPixmap());
    setScale(0.08);
    connect(zombieMovie, &QMovie::frameChanged, this, [=]() {
        setPixmap(zombieMovie->currentPixmap());
    });
    zombieMovie->start();

    moveTimer = new QTimer(this);
    connect(moveTimer, &QTimer::timeout, this, &LeafHeadZombie::moveForward);
    moveTimer->start(1000);

    attackTimer = new QTimer(this);
    connect(attackTimer, &QTimer::timeout, this, &LeafHeadZombie::attackZombie);
}
void LeafHeadZombie::moveForward()
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
    }*/
}

void LeafHeadZombie::attackZombie()
{
    if (this->getHealth() <= 0) {
        int targetRect = ChangePosToRect(this->pos());
        attackTimer->stop();
        scene->removeItem(this);
        //moveTimer->start(1000);
        if(zombieMap.contains(targetRect) && zombieMap[targetRect].second)
            gridcenterMap[targetRect].second = "";
        zombieMap.remove(targetRect);
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
