#include "jalapieno.h"

Jalapieno::Jalapieno() : PlantBase(0,0,300,150) {
    setPixmap(QPixmap(":/image/jalapino_transparent.png"));
    setScale(0.08);
}
