#include "PlantBase.h"

PlantBase::PlantBase(int _Health,int _AttackPower)
    : Health(_Health), AttackPower(_AttackPower) {

}

int PlantBase::getHealth()
{
    return Health;
}

void PlantBase::setHealth(int _Health)
{
    Health = _Health;
}

int PlantBase::getAttackPower()
{
    return AttackPower;
}



