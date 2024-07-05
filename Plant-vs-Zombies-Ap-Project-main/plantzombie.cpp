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

    ui->graphicsView->setScene(s);
    f->setScale(1);
    sunStorage = 0;brainStorge = 0;
    s->addItem(f);
    divideImageIntoGrid(6, 12);
    gridCentersMap = createGridCentersMap();


    sunspawnTimer = new QTimer(this);
    connect(sunspawnTimer, &QTimer::timeout, this, &plantzombie::spawnSun);
    sunspawnTimer->start(5000); // spawn a sun every 5 seconds
    brainspawnTimer = new QTimer(this);
    connect(brainspawnTimer, &QTimer::timeout, this, &plantzombie::spawnBrain);

    brainspawnTimer->start(5000); // spawn a sun every 5 secon
    //ui->pushButtonPA->setStyleSheet("QPushButton { background-color: rgba(0, 0, 255, 100); }");
    visibleButton();

}
void plantzombie::visibleButton(){

    if(sunStorage >= 50){
        ui->pushButtonPA->setVisible(true);
    }
    else{
       ui->pushButtonPA->setVisible(false);
    }

    if(sunStorage >= 100){
        ui->pushButtonPB->setVisible(true);
    }
    else{
        ui->pushButtonPB->setVisible(false);
    }
    if(sunStorage >= 100){
        ui->pushButtonPC->setVisible(true);
    }
    else{
        ui->pushButtonPC->setVisible(false);
    }
    if(sunStorage >= 175){
        ui->pushButtonPD->setVisible(true);
    }
    else{
        ui->pushButtonPD->setVisible(false);
    }
    if(sunStorage >= 150){
        ui->pushButtonPE->setVisible(true);
    }
    else{
        ui->pushButtonPE->setVisible(false);
    }
    if(sunStorage >= 125){
        ui->pushButtonPF->setVisible(true);
    }
    else{
        ui->pushButtonPF->setVisible(false);
    }
    if(brainStorge >= 100){
         ui->pushButtonZA->setVisible(true);
    }
    else{
        ui->pushButtonZA->setVisible(false);
    }
    if(brainStorge >= 200){
        ui->pushButtonZB->setVisible(true);
    }
    else{
        ui->pushButtonZB->setVisible(false);
    }
    if(brainStorge >= 150){
        ui->pushButtonZC->setVisible(true);
    }
    else{
        ui->pushButtonZC->setVisible(false);
    }
    if(brainStorge >= 150){
        ui->pushButtonZD->setVisible(true);
    }
    else{
        ui->pushButtonZD->setVisible(false);
    }
    if(brainStorge >= 200){
        ui->pushButtonZE->setVisible(true);
    }
    else{
        ui->pushButtonZE->setVisible(false);
    }
    if(brainStorge >= 800){
        ui->pushButtonZF->setVisible(true);
    }
    else{
        ui->pushButtonZF->setVisible(false);
    }
}
plantzombie::~plantzombie()
{
    delete ui;
}
void plantzombie::insertfieldPA(int rect , QPointF point)
{

    Peashooter* pa = new Peashooter;
    QPair<Peashooter*,int> pair(pa,rect);
    gridCentersMap[rect].second = "PA";
    pa->setPos(point);
    s->addItem(pa);
    PA.push_back(pair);
    sunStorage -= 50;
    ui->label_2->setText(QString::number(sunStorage));
    visibleButton();
    connect(pa, &Peashooter::shootPea, this, [=]() { onShootPea(pa); });
    pa->startShooting();

}
/*void plantzombie::onShootPea(Peashooter* pa) {
    QGraphicsEllipseItem* pea = new QGraphicsEllipseItem(0, 0, 15, 10);
    pea->setBrush(Qt::green);
    pea->setPos(pa->pos() + QPointF(60,+15));
    s->addItem(pea);

    moveTimer = new QTimer(this);
    int foundSecond = -1;


    for (const auto& pair : PA) {
        if (pair.first == pa) {
            foundSecond = pair.second;
            break;
        }
    }
    QString zombie;
    bool flag = false;
    int i = 0, j = 0;
    for(i = foundSecond + 1 , j = 0 ; i%12 <7  && j < 5 ; ++j ,++i){
        if(gridCentersMap[i].second == ""){  continue;}
    if(gridCentersMap[i].second[0] == 'Z' ){
            zombie = gridCentersMap[i].second;
            flag = true;
            qDebug()<<zombie;
            break;
        }
    }
    connect(moveTimer, &QTimer::timeout, [this,flag,pea,i]() {
        pea->setPos(pea->pos() + QPointF(10, 0));
        if(ChangePosToRect(pea->pos()) == i && flag == true){
            s->removeItem(pea);
        }
        else if (pea->pos().x() > 1000) {
            s->removeItem(pea);
        }
    }); //firning client message
    moveTimer->start(50);
}*/
void plantzombie::onShootPea(Peashooter* pa) {
    QGraphicsEllipseItem* pea = new QGraphicsEllipseItem(0, 0, 15, 10);
    pea->setBrush(Qt::green);
    pea->setPos(pa->pos() + QPointF(62, 17));
    s->addItem(pea);

    QTimer* moveTimer = new QTimer(this);
    connect(moveTimer, &QTimer::timeout, this, [this,pa, pea, moveTimer]() {
        pea->setPos(pea->pos() + QPointF(10, 0));

        if (pea->pos().x() > 1000) {
            s->removeItem(pea);
            delete pea;
            moveTimer->stop();
            moveTimer->deleteLater();
            return;
        }

        int foundSecond = -1;
        for (const auto& pair : PA) {
            if (pair.first == pa) {
                foundSecond = pair.second;
                break;
            }
        }

        if (foundSecond != -1) {
            int i = foundSecond + 1;
            for (int j = 0; j < 5 && (i % 12) < 7; ++j, ++i) {
                if (!gridCentersMap[i].second.isEmpty() && gridCentersMap[i].second[0] == 'Z') {
                    if (ChangePosToRect(pea->pos()) == i) {
                        QPointF currentPos = pea->pos();
                        QPointF zombiePos = gridCentersMap[i].first;
                        if (currentPos.x() >= zombiePos.x() + 10) {
                            s->removeItem(pea);
                            delete pea;
                            moveTimer->stop();
                            moveTimer->deleteLater();
                            return;
                        }
                    }
                }
            }
        }
    });

    moveTimer->start(50);
}

void plantzombie::insertfieldPB(int rect , QPointF point)
{
    Two_Peashooter* pb = new Two_Peashooter;
    QPair<Two_Peashooter*,int> pair(pb,rect);
    gridCentersMap[rect].second = "PB";
    pb->setPos(point);
    s->addItem(pb);
    PB.push_back(pair);
    sunStorage -= 100;
    ui->label_2->setText(QString::number(sunStorage));
    visibleButton();
}

void plantzombie::insertfieldPC(int rect , QPointF point)
{
    Walnut* pc = new Walnut;
    QPair<Walnut*,int> pair(pc,rect);
    gridCentersMap[rect].second = "PC";
    pc->setPos(point);
    s->addItem(pc);
    PC.push_back(pair);
    sunStorage -= 100;
    ui->label_2->setText(QString::number(sunStorage));
    visibleButton();
}
void plantzombie::insertfieldPD(int rect , QPointF point)
{
    PlumMine* pd = new PlumMine;
    QPair<PlumMine*,int> pair(pd,rect);
    gridCentersMap[rect].second = "PD";
    pd->setPos(point);
    s->addItem(pd);
    PD.push_back(pair);
    sunStorage -= 175;
    ui->label_2->setText(QString::number(sunStorage));
    visibleButton();
}
void plantzombie::insertfieldPE(int rect, QPointF point)
{
    Jalapieno* pe = new Jalapieno;
    QPair<Jalapieno*,int> pair(pe,rect);
    gridCentersMap[rect].second = "PE";
    pe->setPos(point);
    s->addItem(pe);
    PE.push_back(pair);
    sunStorage -= 150;
    ui->label_2->setText(QString::number(sunStorage));
    visibleButton();
}
void plantzombie::insertfieldPF(int rect, QPointF point)
{
    Boomerang* pf = new Boomerang;
    QPair<Boomerang*,int> pair(pf,rect);
    gridCentersMap[rect].second = "PF";
    pf->setPos(point);
    s->addItem(pf);
    PF.push_back(pair);
    sunStorage -= 125;
    ui->label_2->setText(QString::number(sunStorage));
    visibleButton();
}
void plantzombie::insertfieldZA(int rect, QPointF point)
{
    RegularZambie* za = new RegularZambie;
    QPair<RegularZambie*,int> pair(za,rect);
    gridCentersMap[rect].second = "ZA";
    za->setPos(point);
    s->addItem(za);
    ZA.push_back(pair);
    brainStorge -= 100;
    ui->Brainlabel->setText(QString::number(brainStorge));
    visibleButton();
}
void plantzombie::insertfieldZB(int rect, QPointF point)
{
    BucketHeadZombie* zb = new BucketHeadZombie;
    QPair<BucketHeadZombie*,int> pair(zb,rect);
    gridCentersMap[rect].second = "ZB";
    zb->setPos(point);
    s->addItem(zb);
    ZB.push_back(pair);
    brainStorge -= 200;
    ui->Brainlabel->setText(QString::number(brainStorge));
    visibleButton();
}
void plantzombie::insertfieldZC(int rect, QPointF point)
{
    LeafHeadZombie* zc = new LeafHeadZombie;
    QPair<LeafHeadZombie*,int> pair(zc,rect);
    gridCentersMap[rect].second = "ZC";
    zc->setPos(point);
    s->addItem(zc);
    ZC.push_back(pair);
    brainStorge -= 150;
    ui->Brainlabel->setText(QString::number(brainStorge));
    visibleButton();
}
void plantzombie::insertfieldZD(int rect, QPointF point)
{
    TallZombie* zd = new TallZombie;
    QPair<TallZombie*,int> pair(zd,rect);
    gridCentersMap[rect].second = "ZD";
    zd->setPos(point);
    s->addItem(zd);
    ZD.push_back(pair);
    brainStorge -= 150;
    ui->Brainlabel->setText(QString::number(brainStorge));
    visibleButton();
}
void plantzombie::insertfieldZE(int rect, QPointF point)
{
    AstronautZombie* ze = new AstronautZombie;
    QPair<AstronautZombie*,int> pair(ze,rect);
    gridCentersMap[rect].second = "ZE";
    ze->setPos(point);
    s->addItem(ze);
    ZE.push_back(pair);
    brainStorge -= 200;
    ui->Brainlabel->setText(QString::number(brainStorge));
    visibleButton();
}
void plantzombie::insertfieldZF(int rect, QPointF point)
{
    PurpleHairZombie* zf = new PurpleHairZombie;
    QPair<PurpleHairZombie*,int> pair(zf,rect);
    gridCentersMap[rect].second = "ZF";
    zf->setPos(point);
    s->addItem(zf);
    ZF.push_back(pair);
    brainStorge -= 800;
    ui->Brainlabel->setText(QString::number(brainStorge));
    visibleButton();
}

int plantzombie::ChangePosToRect(QPointF point)
{
    for(int i = 0; i < gridRects.size();++i){
        if(gridRects[i].contains(point)){
            currentGridIndex = i;
            return currentGridIndex;
        }
    }
    return -1;
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
    visibleButton();
    ui->label_2->setText(QString::number(sunStorage));
    }
void plantzombie::spawnBrain()
{
    Brain *brain = new Brain();
    brain->setScale(0.25);
    s->addItem(brain);
    brain->setPos(QRandomGenerator::global()->bounded(400)+600, QRandomGenerator::global()->bounded(350)+25);
    connect(brain, &Brain::clicked, this, &plantzombie::handleBrainClick);
}

void plantzombie::handleBrainClick()
{
    brainStorge += 25;
    ui->Brainlabel->setText(QString::number(brainStorge));
    visibleButton();
}

void plantzombie::divideImageIntoGrid(int rows, int columns)
{
    qreal widthStep = 932/ columns;
    qreal heightStep = 426/ rows;
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < columns; ++col) {
            //qreal x = col * widthStep+118;
            //qreal y = row * heightStep+40;
            QRectF rect(118+ col * widthStep, 40 + row * heightStep, widthStep, heightStep);
            //QGraphicsRectItem *b=new QGraphicsRectItem(rect);
            //QPen p(Qt::black);
           // b->setPen(p);
            //s->addItem(b);
            gridRects.push_back(rect);
         }
}
}

QMap<int, QPair<QPointF,QString>> plantzombie::createGridCentersMap()
{
    QMap<int, QPair<QPointF,QString>> centersMap;
    for (int i = 0; i < gridRects.size(); ++i) {
         QPointF center = gridRects[i].center();


         QPair<QPointF,QString> p(center,"");
         centersMap.insert(i, p);

    }
    return centersMap;
}

void plantzombie::mousePressEvent(QMouseEvent *event)
{
    QPointF viewPos=event->pos();
    //QPointF clickedPos =ui->graphicsView->mapToScene(viewPos.toPoint());
    int a=viewPos.y();
    viewPos.setY(a-150);
    for (int i = 0; i < gridRects.size(); ++i) {
        if (gridRects[i].contains(viewPos)) {
            currentGridIndex = i;

            break;
        }
    }

    if (event->button() == Qt::LeftButton) {
        QString str = gridCentersMap.find(currentGridIndex)->second;
        if(isDrawingPA == true){
            if((currentGridIndex+1)%12<7&&(currentGridIndex+1)%12!=0 && str == ""){
                insertfieldPA(currentGridIndex,gridRects[currentGridIndex].topLeft());
                isDrawingPA = false;
                gridCentersMap.find(currentGridIndex)->second="PA";
            }

        }else if(isDrawingPB == true){
            if((currentGridIndex+1)%12<7 && (currentGridIndex+1)%12!=0&&str == ""){
                insertfieldPB(currentGridIndex,gridRects[currentGridIndex].topLeft());
                isDrawingPB = false;
                gridCentersMap.find(currentGridIndex)->second="PB";
            }

        }else if(isDrawingPC == true){
            if((currentGridIndex+1)%12<7 && (currentGridIndex+1)%12!=0 && str == ""){
                insertfieldPC(currentGridIndex,gridRects[currentGridIndex].topLeft());
                isDrawingPC = false;
                gridCentersMap.find(currentGridIndex)->second="PC";
            }

        }else if(isDrawingPD == true){
            if((currentGridIndex+1)%12<7&&(currentGridIndex+1)%12!=0 && str == ""){
                insertfieldPD(currentGridIndex,gridRects[currentGridIndex].topLeft());
                isDrawingPD = false;
                gridCentersMap.find(currentGridIndex)->second="PD";
            }

        }else if(isDrawingPE == true){
            if((currentGridIndex+1)%12<7&&(currentGridIndex+1)%12!=0 && str == ""){
                insertfieldPE(currentGridIndex,gridRects[currentGridIndex].topLeft());
                isDrawingPE = false;
                gridCentersMap.find(currentGridIndex)->second="PE";
            }

        }else if(isDrawingPF == true){
            if((currentGridIndex+1)%12<7&&(currentGridIndex+1)%12!=0 && str == ""){
                insertfieldPF(currentGridIndex,gridRects[currentGridIndex].topLeft());
                isDrawingPF = false;
                gridCentersMap.find(currentGridIndex)->second="PF";
            }

        }else if(isDrawingZA == true){
            if((currentGridIndex+1)%12==0 && str == ""){
                insertfieldZA(currentGridIndex,gridRects[currentGridIndex].topLeft());
                isDrawingZA = false;
                gridCentersMap.find(currentGridIndex)->second="ZA";
            }
        }else if(isDrawingZB == true){
            if((currentGridIndex+1)%12==0 && str == ""){
                insertfieldZB(currentGridIndex,gridRects[currentGridIndex].topLeft());
                isDrawingZB = false;
                gridCentersMap.find(currentGridIndex)->second="ZB";
            }
        }else if(isDrawingZC == true){
            if((currentGridIndex+1)%12==0 && str == ""){
                insertfieldZC(currentGridIndex,gridRects[currentGridIndex].topLeft());
                isDrawingZC = false;
                gridCentersMap.find(currentGridIndex)->second="ZC";
            }
        }else if(isDrawingZD == true){
            if((currentGridIndex+1)%12==0 && str == ""){
                insertfieldZD(currentGridIndex,gridRects[currentGridIndex].topLeft());
                isDrawingZD = false;
                gridCentersMap.find(currentGridIndex)->second="ZD";
            }
        }else if(isDrawingZE == true){
            if((currentGridIndex+1)%12==0 && str == ""){
                insertfieldZE(currentGridIndex,gridRects[currentGridIndex].topLeft());
                isDrawingZE = false;
                gridCentersMap.find(currentGridIndex)->second="ZE";
            }
        }else if(isDrawingZF == true){
            if((currentGridIndex+1)%12==0 && str == ""){
                insertfieldZF(currentGridIndex,gridRects[currentGridIndex].topLeft());
                isDrawingZF = false;
                gridCentersMap.find(currentGridIndex)->second="ZF";
            }
        }






    } else if (event->button() == Qt::RightButton) {

    }
}



void plantzombie::onButtonPAClicked()
{
    isDrawingPA = true;
}

void plantzombie::onButtonPBClicked()
{
    isDrawingPB = true;
}


void plantzombie::onButtonPCClicked()
{
    isDrawingPC= true;
}

void plantzombie::onButtonPDClicked()
{
    isDrawingPD = true;
}

void plantzombie::onButtonPEClicked()
{
    isDrawingPE = true;
}

void plantzombie::onButtonPFClicked()
{
    isDrawingPF = true;
}

void plantzombie::onButtonZAClicked()
{
    isDrawingZA = true;
}

void plantzombie::onButtonZBClicked()
{
    isDrawingZB = true;
}

void plantzombie::onButtonZCClicked()
{
    isDrawingZC = true;
}

void plantzombie::onButtonZDClicked()
{
    isDrawingZD = true;
}

void plantzombie::onButtonZEClicked()
{
    isDrawingZE = true;
}

void plantzombie::onButtonZFClicked()
{
    isDrawingZF = true;
}
void plantzombie::on_pushButtonPA_clicked()
{
    onButtonPAClicked();
}


void plantzombie::on_pushButtonPB_clicked()
{
    onButtonPBClicked();
}


void plantzombie::on_pushButtonPC_clicked()
{
    onButtonPCClicked();
}


void plantzombie::on_pushButtonPD_clicked()
{
    onButtonPDClicked();
}


void plantzombie::on_pushButtonPE_clicked()
{
    onButtonPEClicked();
}


void plantzombie::on_pushButtonPF_clicked()
{
    onButtonPFClicked();
}


void plantzombie::on_pushButtonZA_clicked()
{
    onButtonZAClicked();
}


void plantzombie::on_pushButtonZB_clicked()
{
    onButtonZBClicked();
}


void plantzombie::on_pushButtonZC_clicked()
{
    onButtonZCClicked();
}


void plantzombie::on_pushButtonZD_clicked()
{
    onButtonZDClicked();
}


void plantzombie::on_pushButtonZE_clicked()
{
    onButtonZEClicked();
}


void plantzombie::on_pushButtonZF_clicked()
{
    onButtonZFClicked();
}

