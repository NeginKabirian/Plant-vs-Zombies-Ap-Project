#include "zombiebase.h"

/*ZombieBase::ZombieBase(QObject *parent)
    : QObject{parent} , MovmentDelay(0),AttackPower(0),TimeBetweenAttacks(0),brain(0)
{}*/

ZombieBase::ZombieBase(int _Health, int _AttackPower): Health(_Health),AttackPower(_AttackPower)
{

}

void ZombieBase::setHealth(int _Health)
{
    Health = _Health;
}

int ZombieBase::getHealth()
{
    return Health;
}

double ZombieBase::getAttackPower()
{
    return AttackPower;
}
