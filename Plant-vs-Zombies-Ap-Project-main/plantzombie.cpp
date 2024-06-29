#include "plantzombie.h"
#include "ui_plantzombie.h"
#define field1 ":/image/field.png"
#define brain1 ":/image/Brain.png"
#include <QDebug>
#include<QGraphicsPixmapItem>
#include <QGraphicsScene>
#include<QRandomGenerator>
#include <QRectF>
plantzombie::plantzombie(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::plantzombie)
{
    ui->setupUi(this);
    s = new QGraphicsScene(this);
    f = new QGraphicsPixmapItem(QPixmap(field1));
    view = new QGraphicsView(s,this);
    view->setSceneRect(-130, -130, 1350, 662);
    view->resize(1350,700);
    f->setScale(1.0);
    view->setRenderHint(QPainter::Antialiasing);
    sunStorage = 0;

    s->addItem(f);
    QRectF boundingRect=f->boundingRect();
    qreal tlx=boundingRect.topLeft().x();
    qreal tly=boundingRect.topLeft().y();
    qreal trx=boundingRect.topRight().x();
    qreal trry=boundingRect.topRight().y();
    qreal blx=boundingRect.bottomLeft().x();
    qreal bly=boundingRect.bottomLeft().y();
    qreal brx=boundingRect.bottomRight().x();
    qreal bry=boundingRect.bottomRight().y();
    qDebug()<<tlx<<tly;
    qDebug()<<trx<<trry;
    qDebug()<<blx<<bly;
    qDebug()<<brx<<bry;
    QGraphicsRectItem *n=new QGraphicsRectItem(0,0,1,1);
    s->addItem(n);
    n->setPos(1040,462);

    sunspawnTimer = new QTimer(this);
    connect(sunspawnTimer, &QTimer::timeout, this, &plantzombie::spawnSun);
    sunspawnTimer->start(5000); // spawn a sun every 5 seconds
    brainspawnTimer = new QTimer(this);
    connect(brainspawnTimer, &QTimer::timeout, this, &plantzombie::spawnBrain);
    brainspawnTimer->start(5000); // spawn a sun every 5 seconds


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
    //qDebug()<<sun->pos();
    connect(sun, &Sun::clicked, this, &plantzombie::handleSunClick);
    //qDebug()<<"shoo"<<peashooter->pos();
}

void plantzombie::handleSunClick() {
    sunStorage += 25;
    //qDebug()<<sunStorage;

}

void plantzombie::spawnBrain()
{
    Brain *brain = new Brain();
    brain->setScale(0.25);
    s->addItem(brain);
    brain->setPos(QRandomGenerator::global()->bounded(400)+600, QRandomGenerator::global()->bounded(350)+25);
    qDebug()<<brain->pos();
    connect(brain, &Brain::clicked, this, &plantzombie::handleBrainClick);
    //qDebug()<<"shoo"<<peashooter->pos();
}

void plantzombie::handleBrainClick()
{
    brainStorge +=25;
}

