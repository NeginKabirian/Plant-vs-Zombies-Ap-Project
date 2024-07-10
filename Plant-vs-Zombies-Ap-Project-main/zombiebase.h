#ifndef ZOMBIEBASE_H
#define ZOMBIEBASE_H
#include<QGraphicsPixmapItem>
#include <QObject>

class ZombieBase : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    //explicit ZombieBase(QObject *parent = nullptr);
    ZombieBase(int,int);
    virtual void setHealth(int);
    virtual int getHealth();
    virtual double getAttackPower();
    QTimer *moveTimer;
    QTimer *attackTimer;
protected:
    int Health;
    const int AttackPower;

};

#endif // ZOMBIEBASE_H
