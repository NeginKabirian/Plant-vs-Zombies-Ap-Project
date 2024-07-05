#ifndef PLANTBASE_H
#define PLANTBASE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include<QTimer>
class PlantBase : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT;
public:
    PlantBase(int,int,int,int);
    virtual ~PlantBase() = default;
    int getHealth();
    int getFirningRate();
    int getAttackPower();
    int getSun();
protected:
    int Health;
    const int FiringRate;
    const int AttackPower;
    const int sun;
};

#endif // PLANTBASE_H

