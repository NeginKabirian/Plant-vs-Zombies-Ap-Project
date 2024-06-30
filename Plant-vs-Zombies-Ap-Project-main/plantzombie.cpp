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
    //int width=922;
    //int Height=416;
    //int rectWidth = width / 12;
    //int rectHeight = Height / 6;
    // (int row = 0; row < 12; ++row) {
            //for (int col = 0; col < 6; ++col){
                //int x = (col * rectWidth)+118;
                //int y = (row * rectHeight)+46;
                //QString r="rectItem"+QString::number(col)+QString::number(row);
            //}
    //}
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

