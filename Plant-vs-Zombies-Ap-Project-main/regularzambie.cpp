#include "regularzambie.h"
#include <QGraphicsScene>
#include <peashooter.h>
#include<two_peashooter.h>
#include<boomerang.h>
/*RegularZambie::RegularZambie(QObject *parent)
    : ZombieBase{parent}
{}//*/
int RegularZambie::ChangePosToRect(QPointF point)
{
    int current;
    /*if(currentRect<12){
        return current + 1;
    }*/
    qDebug()<<gridRects.size();
    for(int i = 0; i < gridRects.size();++i){
        if(gridRects[i].contains(point)){
             qDebug()<<i;
            current = i;
            return current + 13;
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
        setPos(x() + 71, y());
        moveTimer->stop();
        attackTimer->start(1000);
        //qDebug()<<currentRect;
    }
}

void RegularZambie::attackZombie()
{
    bool stop = false;
    setPos(x() - 71, y());
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

    setPos(x() + 71, y());
}



