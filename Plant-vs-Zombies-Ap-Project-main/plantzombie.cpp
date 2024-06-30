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
    f->setScale(1);
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

    //brainspawnTimer->start(5000); // spawn a ghazal every 5 seconds

    brainspawnTimer->start(5000); // spawn a sun every 5 seconds



    //view->setScene(s);
    //view->show();

}

plantzombie::~plantzombie()
{
    delete ui;
}

void plantzombie::insertfieldPA(int rect , QPointF point)
{
    Peashooter* pa = new Peashooter;
    QPair<Peashooter*,int> pair(pa,rect);
    pa->setPos(point);
    s->addItem(pa);
    PA.push_back(pair);
}

void plantzombie::insertfieldPB(int rect , QPointF point)
{
    Two_Peashooter* pb = new Two_Peashooter;
    QPair<Two_Peashooter*,int> pair(pb,rect);
    pb->setPos(point);
    s->addItem(pb);
    PB.push_back(pair);
}

void plantzombie::insertfieldPC(int rect , QPointF point)
{
    Walnut* pc = new Walnut;
    QPair<Walnut*,int> pair(pc,rect);
    pc->setPos(point);
    s->addItem(pc);
    PC.push_back(pair);
}
void plantzombie::insertfieldPD(int rect , QPointF point)
{
    PlumMine* pd = new PlumMine;
    QPair<PlumMine*,int> pair(pd,rect);
    pd->setPos(point);
    s->addItem(pd);
    PD.push_back(pair);
}
void plantzombie::insertfieldPE(int rect, QPointF point)
{
    Jalapieno* pe = new Jalapieno;
    QPair<Jalapieno*,int> pair(pe,rect);
    pe->setPos(point);
    s->addItem(pe);
    PE.push_back(pair);
}
void plantzombie::insertfieldPF(int rect, QPointF point)
{
    Boomerang* pf = new Boomerang;
    QPair<Boomerang*,int> pair(pf,rect);
    pf->setPos(point);
    s->addItem(pf);
    PF.push_back(pair);
}
void plantzombie::insertfieldZA(int rect, QPointF point)
{
    RegularZambie* za = new RegularZambie;
    QPair<RegularZambie*,int> pair(za,rect);
    za->setPos(point);
    s->addItem(za);
    ZA.push_back(pair);
}
void plantzombie::insertfieldZB(int rect, QPointF point)
{
    BucketHeadZombie* zb = new BucketHeadZombie;
    QPair<BucketHeadZombie*,int> pair(zb,rect);
    zb->setPos(point);
    s->addItem(zb);
    ZB.push_back(pair);
}
void plantzombie::insertfieldZC(int rect, QPointF point)
{
    LeafHeadZombie* zc = new LeafHeadZombie;
    QPair<LeafHeadZombie*,int> pair(zc,rect);
    zc->setPos(point);
    s->addItem(zc);
    ZC.push_back(pair);
}
void plantzombie::insertfieldZD(int rect, QPointF point)
{
    TallZombie* zd = new TallZombie;
    QPair<TallZombie*,int> pair(zd,rect);
    zd->setPos(point);
    s->addItem(zd);
    ZD.push_back(pair);
}
void plantzombie::insertfieldZE(int rect, QPointF point)
{
    AstronautZombie* ze = new AstronautZombie;
    QPair<AstronautZombie*,int> pair(ze,rect);
    ze->setPos(point);
    s->addItem(ze);
    ZE.push_back(pair);
}
void plantzombie::insertfieldZF(int rect, QPointF point)
{
    PurpleHairZombie* zf = new PurpleHairZombie;
    QPair<PurpleHairZombie*,int> pair(zf,rect);
    zf->setPos(point);
    s->addItem(zf);
    ZF.push_back(pair);
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

