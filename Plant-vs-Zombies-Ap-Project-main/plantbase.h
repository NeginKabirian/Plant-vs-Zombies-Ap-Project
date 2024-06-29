#ifndef PLANTBASE_H
#define PLANTBASE_H

#include <QObject>
#include <QGraphicsPixmapItem>

class PlantBase : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT;
public:
    PlantBase(int,int,int,int);
    virtual ~PlantBase() = default;
    int getHealth();
    const int getFirningRate();
    const int getAttackPower();
    const int getSun();
protected:
    int Health;
    const int FiringRate;
    const int AttackPower;
    const int sun;
};

#endif // PLANTBASE_H

