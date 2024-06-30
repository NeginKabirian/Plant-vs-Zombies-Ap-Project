#include "brain.h"



Brain::Brain(){
    setPixmap(QPixmap(":/image/Brain.png"));

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Brain::clicked);
    timer->start(5000); // 5 seconds to disappear
    disappearTimer = new QTimer(this);
    connect(disappearTimer, &QTimer::timeout, this, &Brain::disappear);
    disappearTimer->start(2000);
}
void Brain::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    this->deleteLater();
}
void Brain::disappear() {
    this->deleteLater();
}
