#include "purplehairzombie.h"

/*PurpleHairZombie::PurpleHairZombie(QObject *parent)
    : ZombieBase{parent}
{}*/

PurpleHairZombie::PurpleHairZombie() :ZombieBase(400,1,75,0.5,800)
{
    setPixmap(QPixmap(":/image/purple hair zombie_transparent.png"));
    setScale(0.1);
}
