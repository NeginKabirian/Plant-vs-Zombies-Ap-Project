#include "astronautzombie.h"

/*AstronautZombie::AstronautZombie(QObject *parent)
    : ZombieBase{parent}
{}*/

AstronautZombie::AstronautZombie() : ZombieBase(500,1,20,1,200)
{
    setPixmap(QPixmap(":/image/astronaut zombie_transparent.png"));
    setScale(0.08);
}
