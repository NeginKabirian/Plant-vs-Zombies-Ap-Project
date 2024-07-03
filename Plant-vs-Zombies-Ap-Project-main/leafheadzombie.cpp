#include "leafheadzombie.h"

/*LeafHeadZombie::LeafHeadZombie(QObject *parent)
    : ZombieBase{parent}
{}*/

LeafHeadZombie::LeafHeadZombie() :ZombieBase(800,1,25,1,150){
    setPixmap(QPixmap(":/image/leaf hair zombie_transparent.png"));
    setScale(0.08);
}

