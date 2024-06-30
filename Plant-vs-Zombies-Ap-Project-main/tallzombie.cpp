#include "tallzombie.h"

TallZombie::TallZombie(QObject *parent)
    : ZombieBase{parent}
{}

TallZombie::TallZombie() : ZombieBase(500,1,30,1,150)
{

}
