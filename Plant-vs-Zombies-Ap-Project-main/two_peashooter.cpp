#include "two_peashooter.h"

Two_Peashooter::Two_Peashooter() : PlantBase(200,1,40,50){
    setPixmap(QPixmap(":/image/two_peashooter_transparent.png"));
    setScale(0.08);
    shootingTimer = new QTimer(this);
    connect(shootingTimer, &QTimer::timeout, this, &Two_Peashooter::shootPea);
}

void Two_Peashooter::startShooting() {
    if (!shooting) {
        shooting = true;
        shootingTimer->start(1000);
    }
}
void Two_Peashooter::stopShooting() {
    if (shooting) {
        shooting = false;
        shootingTimer->stop();
    }
}

bool Two_Peashooter::isShooting() const {
    return shooting;
}
