#include "plantzombie.h"
#include "ui_plantzombie.h"
#define field1 ":/image/field.png"

#include <QDebug>
#include<QGraphicsPixmapItem>
#include <QGraphicsScene>
#include<QRandomGenerator>

plantzombie::plantzombie(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::plantzombie)
{
    ui->setupUi(this);
    s = new QGraphicsScene(this);
    f = new QGraphicsPixmapItem(QPixmap(field1));
    view = new QGraphicsView(s,this);
    view->setSceneRect(0, 0, 1100, 522);
    view->resize(1100,522);
    f->setScale(1.0);
    sunStorage = 0;
    s->addItem(f);

    f->setPos(0,0);
    spawnTimer = new QTimer(this);
    connect(spawnTimer, &QTimer::timeout, this, &plantzombie::spawnSun);
    spawnTimer->start(5000); // spawn a sun every 5 seconds
    view->setScene(s);
    view->show();
}

plantzombie::~plantzombie()
{
    delete ui;
}
void plantzombie::spawnSun() {
    Sun *sun = new Sun();
    sun->setScale(0.1);
    s->addItem(sun);
    sun->setPos(QRandomGenerator::global()->bounded(400)+100, QRandomGenerator::global()->bounded(350)+25);
    qDebug()<<sun->pos();
    connect(sun, &Sun::clicked, this, &plantzombie::handleSunClick);
}

void plantzombie::handleSunClick() {
    sunStorage += 25;
    qDebug()<<sunStorage;
}
