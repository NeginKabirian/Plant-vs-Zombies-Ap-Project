#ifndef PLUMMINE_H
#define PLUMMINE_H

#include "plantbase.h"
#include <QTimer>
#include <QGraphicsScene>
class PlumMine : public PlantBase
{
     Q_OBJECT
public:
    PlumMine(QGraphicsScene*&);
public slots:
    void explode();
signals:
    void plumminefunction();
private:
    QGraphicsScene*& scene;
};

#endif // PLUMMINE_H
