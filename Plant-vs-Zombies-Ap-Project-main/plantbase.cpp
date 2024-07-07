#include "PlantBase.h"

PlantBase::PlantBase(int _Health,int _FirningRate,int _AttackPower,int _sun)
    : Health(_Health), FiringRate(_FirningRate), AttackPower(_AttackPower),sun(_sun) {

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



