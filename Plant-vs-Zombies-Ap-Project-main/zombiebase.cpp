#include "zombiebase.h"

/*ZombieBase::ZombieBase(QObject *parent)
    : QObject{parent} , MovmentDelay(0),AttackPower(0),TimeBetweenAttacks(0),brain(0)
{}*/

ZombieBase::ZombieBase(int _Health, double _MovmentDelay, int _AttackPower, double _TimeBetweenAttacks, int _brain): Health(_Health),MovmentDelay(_MovmentDelay),AttackPower(_AttackPower),TimeBetweenAttacks(_TimeBetweenAttacks),brain(_brain)
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
