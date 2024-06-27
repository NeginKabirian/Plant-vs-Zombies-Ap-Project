#include "zombieplanet.h"
#include "ui_zombieplanet.h"
#define field1 ":/image/field.png"
#include <QDebug>
#include<QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QSizePolicy>
zombieplanet::zombieplanet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::zombieplanet)
{
    ui->setupUi(this);

       QGraphicsScene *s = new QGraphicsScene(this);
       QGraphicsPixmapItem *f = new QGraphicsPixmapItem(QPixmap(field1));
       QGraphicsView *view = new QGraphicsView(s,this);
       view->resize(1100,522);
       f->setScale(1.0);
       s->addItem(f);
       view->setScene(s);
       f->setPos(0,0);
       view->show();

}

zombieplanet::~zombieplanet()
{
    delete ui;
}
