#ifndef PEASHOOTER_H
#define PEASHOOTER_H

#include "plantBase.h"
#include<QTimer>

class Peashooter : public PlantBase
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
public:
    Peashooter();
    void startShooting();
    void stopShooting();
    bool isShooting() const;
signals:
    void shootPea();

private:
    QTimer *shootingTimer;
    bool shooting;
};

#endif // PEASHOOTER_H
