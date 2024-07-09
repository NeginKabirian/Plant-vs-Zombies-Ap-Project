#ifndef TWO_PEASHOOTER_H
#define TWO_PEASHOOTER_H

#include "plantbase.h"
#include<QTimer>
class Two_Peashooter : public PlantBase
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
public:
    Two_Peashooter();
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

#endif // TWO_PEASHOOTER_H
