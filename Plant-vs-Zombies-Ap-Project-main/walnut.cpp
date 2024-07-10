#include "walnut.h"
#include<QPropertyAnimation>
Walnut::Walnut() : PlantBase(400,0,0,100){
    setPixmap(QPixmap(":/image/walnut_transparent.png"));
    setScale(0.08);
}
void Walnut::move(bool check){
    /*if(check){
        QPropertyAnimation* animation = new QPropertyAnimation(this, "pos");
        animation->setDuration(1000);
        animation->setStartValue(pos());
        animation->setKeyValueAt(0.7, pos() + QPointF(0, -2.2));
        animation->setEndValue(pos());
        animation->setLoopCount(-1);
        animation->start(QAbstractAnimation::DeleteWhenStopped);
    }*/
}
