#include "bucketheadzombie.h"

/*BucketHeadZombie::BucketHeadZombie(QObject *parent)
    : ZombieBase{parent}
{}*/

BucketHeadZombie::BucketHeadZombie() : ZombieBase(1950,2,50,1,200){
    setPixmap(QPixmap(":/image/Bucket head zombie_trasparent.png"));
    setScale(0.1);
}

