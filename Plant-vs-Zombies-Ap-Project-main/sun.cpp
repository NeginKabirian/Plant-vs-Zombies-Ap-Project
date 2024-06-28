#include "sun.h"
#include <QGraphicsSceneMouseEvent>
Sun::Sun() {
    setPixmap(QPixmap(":/image/sun.png"));

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Sun::clicked);
    timer->start(5000); // 5 seconds to disappear
    disappearTimer = new QTimer(this);
    connect(disappearTimer, &QTimer::timeout, this, &Sun::disappear);
    disappearTimer->start(2000);
}
void Sun::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    emit clicked();
    delete this; // remove the sun
}
void Sun::disappear() {
    delete this;
}
