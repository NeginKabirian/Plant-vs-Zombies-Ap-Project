#ifndef PLANTBASE_H
#define PLANTBASE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include<QTimer>
class PlantBase : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT;
public:
    PlantBase(int,int);
    virtual ~PlantBase() = default;
    int getHealth();
    virtual void setHealth(int);
    int getFirningRate();
    int getAttackPower();
    int getSun();
protected:
    int Health;
    const int AttackPower;
};

#endif // PLANTBASE_H

