#ifndef ASTRONAUTZOMBIE_H
#define ASTRONAUTZOMBIE_H

#include "zombiebase.h"

class AstronautZombie : public ZombieBase
{
public:
    explicit AstronautZombie(QObject *parent = nullptr);
    AstronautZombie();
private:
    const double MovmentDelaytwo = 0.5;
    const double TimeBetweenAttackstwo = 0.5;
};

#endif // ASTRONAUTZOMBIE_H
