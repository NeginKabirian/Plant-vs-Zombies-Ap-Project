#ifndef JALAPIENO_H
#define JALAPIENO_H

#include "plantbase.h"
#include<QTimer>
class Jalapieno : public PlantBase
{
     Q_OBJECT
public:
    Jalapieno(QGraphicsScene* scene);
signals:
   void burnRow(int row);

public slots:
    void ignite();

private:
    QGraphicsScene* scene;
    QTimer* fireTimer;
};

#endif // JALAPIENO_H
