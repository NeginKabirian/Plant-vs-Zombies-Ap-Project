#ifndef ZOMBIEBASE_H
#define ZOMBIEBASE_H
#include<QGraphicsPixmapItem>
#include <QObject>

class ZombieBase : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit ZombieBase(QObject *parent = nullptr);
    ZombieBase(int,int,int,int,int);
protected:
    int Health;
    const double MovmentDelay;
    const int AttackPower;
    const double TimeBetweenAttacks;
    const int brain;

signals:
};

#endif // ZOMBIEBASE_H
