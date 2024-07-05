#ifndef WALNUT_H
#define WALNUT_H

#include "plantbase.h"

class Walnut : public PlantBase
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
public:
    Walnut();
    void move(bool check);
};

#endif // WALNUT_H
