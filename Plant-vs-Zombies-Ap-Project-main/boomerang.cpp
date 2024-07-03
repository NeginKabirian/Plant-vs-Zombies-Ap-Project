#include "boomerang.h"

Boomerang::Boomerang() : PlantBase(200,1,30,125) {
    setPixmap(QPixmap(":/image/boomrang_transparent.png"));
    setScale(0.23);
}
