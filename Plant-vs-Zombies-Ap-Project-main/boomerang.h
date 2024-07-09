#ifndef BOOMERANG_H
#define BOOMERANG_H

#include "plantbase.h"

class Boomerang : public PlantBase
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
public:
    Boomerang();
    void startShooting();
    void stopShooting();
    bool isShooting() const;
    bool remove = false;
signals:
    void shootPea();

private:
    QTimer *shootingTimer;
    bool shooting;
};

#endif // BOOMERANG_H
