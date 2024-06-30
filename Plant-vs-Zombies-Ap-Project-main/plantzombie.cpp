#include "plantzombie.h"
#include "ui_plantzombie.h"
#define field1 ":/image/field.png"
#define brain1 ":/image/Brain.png"
#include <QDebug>
#include<QGraphicsPixmapItem>
#include <QGraphicsScene>
#include<QRandomGenerator>
#include <QGraphicsView>
#include <QRectF>
plantzombie::plantzombie(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::plantzombie)
{
    ui->setupUi(this);
    s = new QGraphicsScene(this);
    f = new QGraphicsPixmapItem(QPixmap(field1));
    //ui->graphicsView->setScene(s);
    ui->graphicsView->setScene(s);
    //view = new QGraphicsView(s,this);
    //view->setSceneRect(-130, -130, 1350, 662);
    //view->resize(1350,700);
    f->setScale(1.0);
    //view->setRenderHint(QPainter::Antialiasing);
    sunStorage = 0;
    s->addItem(f);
    divideImageIntoGrid(6, 12);
    gridCentersMap = createGridCentersMap();


    sunspawnTimer = new QTimer(this);
    connect(sunspawnTimer, &QTimer::timeout, this, &plantzombie::spawnSun);
    sunspawnTimer->start(5000); // spawn a sun every 5 seconds
    brainspawnTimer = new QTimer(this);
    connect(brainspawnTimer, &QTimer::timeout, this, &plantzombie::spawnBrain);

    brainspawnTimer->start(5000); // spawn a ghazal every 5 seconds

    brainspawnTimer->start(5000); // spawn a sun every 5 seconds



    //view->setScene(s);
    //view->show();

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
    connect(sun, &Sun::clicked, this, &plantzombie::handleSunClick);
}

void plantzombie::handleSunClick() {
    sunStorage += 25;
}

void plantzombie::spawnBrain()
{
    Brain *brain = new Brain();
    brain->setScale(0.25);
    s->addItem(brain);
    brain->setPos(QRandomGenerator::global()->bounded(400)+600, QRandomGenerator::global()->bounded(350)+25);
    qDebug()<<brain->pos();
    connect(brain, &Brain::clicked, this, &plantzombie::handleBrainClick);
}

void plantzombie::handleBrainClick()
{
    brainStorge +=25;
}

//void plantzombie::onCircleButtonClicked()
//{
    //isDrawingCircle = true;
//}

void plantzombie::divideImageIntoGrid(int rows, int columns)
{
    qreal widthStep = 932/ columns;
    qreal heightStep = 426/ rows;
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < columns; ++col) {
            qreal x = col * widthStep+118;
            qreal y = row * heightStep+40;
            QRectF rect(x, y, widthStep, heightStep);
            //QGraphicsRectItem *b=new QGraphicsRectItem(rect);
            //QPen p(Qt::black);
           // b->setPen(p);
            //s->addItem(b);
            gridRects.append(rect);
         }
}
}

QMap<int, QPair<QPointF,int>> plantzombie::createGridCentersMap()
{
    QMap<int, QPair<QPointF,int>> centersMap;
    for (int i = 0; i < gridRects.size(); ++i) {
         QPointF center = gridRects[i].center();


         QPair<QPointF,int> p(center,0);
         centersMap.insert(i, p);

    }
    return centersMap;
}

void plantzombie::mousePressEvent(QMouseEvent *event)
{
    QPointF viewPos=event->pos();
    QPointF clickedPos =ui->graphicsView->mapToScene(viewPos.toPoint());

            // یافتن مربع متناظر با کلیک
            for (int i = 0; i < gridRects.size(); ++i) {
                if (gridRects[i].contains(clickedPos)) {
                    i=i-24;
                    currentGridIndex = i;

                    break;
                }
            }

            // نمایش دایره یا مستطیل وسط مربع
            if (event->button() == Qt::LeftButton) {
                //if(isDrawingCircle == true){

                //}

            } else if (event->button() == Qt::RightButton) {

            }
}


void plantzombie::on_pushButton_clicked()
{
    //onCircleButtonClicked();
}

