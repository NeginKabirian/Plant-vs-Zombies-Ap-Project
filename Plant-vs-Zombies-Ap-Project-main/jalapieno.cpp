#include "jalapieno.h"
#include "qgraphicsscene.h"

Jalapieno::Jalapieno(QGraphicsScene* scene) : PlantBase(0,0,300,150) , scene(scene){
    setPixmap(QPixmap(":/image/jalapino_transparent.png"));
    setScale(0.08);

}
void Jalapieno::ignite()
{
    int row = y() / 71;

    scene->removeItem(this);
    //delete this;

    for (int i = 0; i < 1000 / 71 - 1 ; ++i) {
        QGraphicsPixmapItem* fire = new QGraphicsPixmapItem(QPixmap(":/image/firepng.parspng.com-5.png"));
        fire->setScale(0.08);
        fire->setPos((i + 2) * 71 , row * 71 + 50);
        scene->addItem(fire);

        QTimer::singleShot(500, [fire]() {
            fire->scene()->removeItem(fire);
            //delete fire;
        });
    }
    emit burnRow(row);
}
