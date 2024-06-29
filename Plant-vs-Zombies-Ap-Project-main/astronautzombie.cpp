#include "astronautzombie.h"

AstronautZombie::AstronautZombie(QObject *parent)
    : ZombieBase{parent}
{}

AstronautZombie::AstronautZombie() : ZombieBase(500,1,20,1,200)
{

}
