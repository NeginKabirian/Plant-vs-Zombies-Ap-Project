#include "plummine.h"

PlumMine::PlumMine(QGraphicsScene* scene): PlantBase(0,0,500,175) , scene(scene) {
    setPixmap(QPixmap(":/image/plum mine_transparent.png"));
    setScale(0.08);
}
void PlumMine::explode()
{
    QGraphicsPixmapItem* smoke = new QGraphicsPixmapItem(QPixmap(":/image/pngimg.com - smoke_PNG55243.png"));
    smoke->setScale(0.2);
    smoke->setOffset(-71 / 2, -71 / 2);
    smoke->setPos(pos() + QPointF(-200, -200));
    scene->addItem(smoke);

    QTimer::singleShot(2000, [smoke,this]() {
        smoke->scene()->removeItem(smoke);
         emit plumminefunction();
    });
    scene->removeItem(this);
}
