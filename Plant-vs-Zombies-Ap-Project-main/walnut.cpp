#include "walnut.h"
#include<QPropertyAnimation>
Walnut::Walnut() : PlantBase(400,0){
    setPixmap(QPixmap(":/image/walnut_transparent.png"));
    setScale(0.08);
}
void Walnut::move(QPointF point){

        QPropertyAnimation* animation = new QPropertyAnimation(this, "pos");
        animation->setDuration(1000);
        animation->setStartValue(point);
        animation->setKeyValueAt(0.7, point + QPointF(0, -3.1));
        animation->setEndValue(point);
        animation->setLoopCount(-1);
        animation->start(QAbstractAnimation::DeleteWhenStopped);

}
