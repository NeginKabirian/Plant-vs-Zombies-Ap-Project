#include "peashooter.h"

Peashooter::Peashooter() : PlantBase(200,1,15,50){
    setPixmap(QPixmap(":/image/peashooter transparent.png"));
    setScale(0.08);
    shootingTimer = new QTimer(this);
    connect(shootingTimer, &QTimer::timeout, this, &Peashooter::shootPea);
}

void Peashooter::startShooting() {
    shootingTimer->start(1000);
}

