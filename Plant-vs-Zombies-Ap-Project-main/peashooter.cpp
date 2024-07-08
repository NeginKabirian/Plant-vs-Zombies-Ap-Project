#include "peashooter.h"

Peashooter::Peashooter() : PlantBase(200,1,15,50){
    setPixmap(QPixmap(":/image/peashooter transparent.png"));
    setScale(0.08);
    shooting = false;
    shootingTimer = new QTimer(this);
    connect(shootingTimer, &QTimer::timeout, this, &Peashooter::shootPea);
    shootingTimer->start(1000);
}
void Peashooter::startShooting() {
    if (!shooting) {
        shooting = true;
        shootingTimer->start(1000);
    }
}

void Peashooter::stopShooting() {
    if (shooting) {
        shooting = false;
        shootingTimer->stop();
    }
}
bool Peashooter::isShooting() const {
    return shooting;
}
