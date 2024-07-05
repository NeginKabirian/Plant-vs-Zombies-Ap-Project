#include "boomerang.h"

Boomerang::Boomerang() : PlantBase(200,1,30,125) {
    setPixmap(QPixmap(":/image/boomrang_transparent.png"));
    setScale(0.23);
    shootingTimer = new QTimer(this);
    connect(shootingTimer, &QTimer::timeout, this, &Boomerang::shootPea);
}
void Boomerang::startShooting() {
    if (!shooting) {
        shooting = true;
        shootingTimer->start(1000);
    }
}

void Boomerang::stopShooting() {
    if (shooting) {
        shooting = false;
        shootingTimer->stop();
    }
}

bool Boomerang::isShooting() const {
    return shooting;
}
