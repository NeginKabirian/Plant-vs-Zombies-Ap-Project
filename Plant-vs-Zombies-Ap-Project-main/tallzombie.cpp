#include "tallzombie.h"

/*TallZombie::TallZombie(QObject *parent)
    : ZombieBase{parent}
{}*/

TallZombie::TallZombie() : ZombieBase(500,1,30,1,150)
{
    setPixmap(QPixmap(":/image/tall zombie_transparent.png"));
    setScale(0.1);
}
