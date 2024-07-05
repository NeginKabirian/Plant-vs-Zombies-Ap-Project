#ifndef PEASHOOTER_H
#define PEASHOOTER_H

#include "plantBase.h"
#include<QTimer>

class Peashooter : public PlantBase
{
      Q_OBJECT
public:
    Peashooter();
    void startShooting();
signals:
    void shootPea();

private:
    QTimer *shootingTimer;
};

#endif // PEASHOOTER_H
