#include "peashooter.h"

Peashooter::Peashooter() : PlantBase(200,1,15,50){
    setPixmap(QPixmap(":/image/peashooter transparent.png"));
    setScale(0.08);
}
