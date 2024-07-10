#include "plantzombie.h"
#include "ui_plantzombie.h"
#define field1 ":/image/field.png"
#define brain1 ":/image/Brain.png"


plantzombie::plantzombie(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::plantzombie)
{
    ui->setupUi(this);
    s = new QGraphicsScene(this);
    f = new QGraphicsPixmapItem(QPixmap(field1));

    ui->graphicsView->setScene(s);
    f->setScale(1);
    sunStorage =1000;brainStorge = 1000;
    s->addItem(f);
    divideImageIntoGrid(6, 12);
    gridCentersMap = createGridCentersMap();


    sunspawnTimer = new QTimer(this);
    connect(sunspawnTimer, &QTimer::timeout, this, &plantzombie::spawnSun);
    sunspawnTimer->start(5000); // spawn a sun every 5 seconds

    brainspawnTimer = new QTimer(this);
    connect(brainspawnTimer, &QTimer::timeout, this, &plantzombie::spawnBrain);
    brainspawnTimer->start(5000); // spawn a sun every 5 secon



    visibleButton();
    /*if(Zombie==true){
        ui->labe->setText("zombie");
    }else if(plant==true){
       ui->->setText("plant");
    }*/
}
void plantzombie::visibleButton(){
    ui->pushButtonPA->setVisible(false);ui->pushButtonPB->setVisible(false);ui->pushButtonPC->setVisible(false);
    ui->pushButtonPD->setVisible(false);ui->pushButtonPE->setVisible(false);ui->pushButtonPF->setVisible(false);
    ui->pushButtonZA->setVisible(false);ui->pushButtonZB->setVisible(false);ui->pushButtonZC->setVisible(false);
    ui->pushButtonZD->setVisible(false);ui->pushButtonZE->setVisible(false);ui->pushButtonZF->setVisible(false);
    ui->Brainlabel->setVisible(false);
    ui->brainlabel->setVisible(false);
    ui->label->setVisible(false);
    ui->label_2->setVisible(false);
    if(plant == true){
        ui->label->setVisible(true);
        ui->label_2->setVisible(true);
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
    }
    /*else*/ if(Zombie==true){
        ui->Brainlabel->setVisible(true);
        ui->brainlabel->setVisible(true);
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
}
plantzombie::~plantzombie()
{
    delete ui;
}
bool plantzombie::isZombieInFront(int rect)
{
    int rowStart = (rect / 12) * 12;
    int rowEnd = rowStart + 12;

    for (int i = rect + 1; i < rowEnd; ++i) {
        if (gridCentersMap[i].second == "ZA" && dynamic_cast<ZombieBase*>(zombieMap[i].second)) {
            return true;
        }
    }
    return false;
}

void plantzombie::insertfieldPA(int rect, QPointF point)
{
    Peashooter* pb = new Peashooter;
    QPair<Peashooter*, int> pair(pb, rect);
    gridCentersMap[rect].second = "PB";
    gridCentersMap[rect].first = point;
    plantMap[rect].second = pb;    //p
    plantMap[rect].first = point; //p
    pb->setPos(point);
    s->addItem(pb);
    if (plant == true) {
        sunStorage -= 50;
        visibleButton();
        ui->label_2->setText(QString::number(sunStorage));
        int x = point.x();
        int y = point.y();
        emit SInsertPB(rect, x, y);
    }
    connect(pb, &Peashooter::shootPea, this, [=]() { onShootPea(pb, point); });
    pb->startShooting();
    QTimer* checkTimer = new QTimer(this);
    connect(checkTimer, &QTimer::timeout, this, [=]() {
        if (isZombieInFront(rect)) {
            if (!pb->isShooting()) {
                connect(pb, &Peashooter::shootPea, this, [=]() { onShootPea(pb, point);
                });
                pb->startShooting();
            }
        } else {
            if (pb->isShooting()) {
                disconnect(pb, &Peashooter::shootPea, this, nullptr);
                pb->stopShooting();
            }
        }
    });
    checkTimer->start(1000);
}

void plantzombie::onShootPea(PlantBase* pa, QPointF point) {

    QGraphicsItem *pea(pa);
    bool boomrang = false;
    if (dynamic_cast<Peashooter*>(pa)) {
        QGraphicsEllipseItem* ellipseItem = new QGraphicsEllipseItem(0, 0, 15, 10);
        ellipseItem->setBrush(Qt::green);
        pea = ellipseItem;
        if(dynamic_cast<Peashooter*>(pa)->remove){
            return;
        }
        else{
            s->addItem(pea);
        }
    } else if (dynamic_cast<Two_Peashooter*>(pa)) {
        QGraphicsEllipseItem* ellipseItem = new QGraphicsEllipseItem(0, 0, 20, 15);
        ellipseItem->setBrush(QColor(0, 100, 0));
        pea = ellipseItem;
        if(dynamic_cast<Two_Peashooter*>(pa)->remove){
            return;
        }
        else{
            s->addItem(pea);
        }
    } else {
        QPolygonF triangle;
        triangle << QPointF(-5, -10) << QPointF(5, -10) << QPointF(0, 10);

        QGraphicsPolygonItem* polygonItem = new QGraphicsPolygonItem(triangle);

        QPen pen(Qt::black);
        pen.setWidth(3);
        polygonItem->setPen(pen);

        QBrush brush(Qt::green);
        polygonItem->setBrush(brush);

        polygonItem->setRotation(-85);
        pea = polygonItem;
        if(dynamic_cast<Boomerang*>(pa)->remove){
            qDebug()<<"boomrang";
            return;
        }
        else{
            s->addItem(pea);
        }
        boomrang = true;
    }

    if (pea == nullptr) return;
    QPropertyAnimation* animation = new QPropertyAnimation(pa, "pos");
    animation->setDuration(1000);
    animation->setStartValue(point);
    animation->setKeyValueAt(0.7, point + QPointF(0, -2.2));
    animation->setEndValue(point);
    animation->setLoopCount(-1);
    animation->start(QAbstractAnimation::DeleteWhenStopped);

    pea->setPos(pa->pos() + QPointF(62, 17));


    QTimer* moveTimer = new QTimer(this);
    connect(moveTimer, &QTimer::timeout, this, [this, pa, pea, moveTimer, boomrang]() {
        pea->setPos(pea->pos() + QPointF(8.8, 0.2));
        if (pea->pos().x() > 1000) {
            s->removeItem(pea);
            delete pea;
            moveTimer->stop();
            moveTimer->deleteLater();
            return;
        }
        int rect = -1;
        for (auto it = plantMap.constBegin(); it != plantMap.constEnd(); ++it) {
            if (it.value().second == pa) {
                rect = it.key();
                break;
            }
        }
        if (isZombieInFront(rect) && boomrang) {
            if (rect != -1) {
                for (int i = 1; i < 12 - rect % 12; ++i) {
                    int targetRect = rect + i;
                    if (zombieMap.contains(targetRect) && zombieMap[targetRect].second && dynamic_cast<ZombieBase*>(zombieMap[targetRect].second)) {
                        if (ChangePosToRect(pea->pos()) == targetRect) {
                            QPointF currentPos = pea->pos();
                            QPointF zombiePos = zombieMap[targetRect].first;
                            int end= (((rect/12)+1)*12)-1;
                            if(gridRects[end].contains(pea->pos())){
                                s->removeItem(pea);
                                delete pea;
                                moveTimer->stop();
                                moveTimer->deleteLater();
                                return;
                            }
                            if (currentPos.x() >= zombiePos.x() +100){
                                plantattack(pa, rect);
                            }
                        }
                    }
                }
            }
        }
        if (boomrang) {
            moveTimer->start(50);
            return;
        }
        if (rect != -1) {
            for (int i = 1; i < 12 - rect % 12; ++i) {
                int targetRect = rect + i;
                if (zombieMap.contains(targetRect) && zombieMap[targetRect].second && dynamic_cast<ZombieBase*>(zombieMap[targetRect].second)) {
                    if (ChangePosToRect(pea->pos()) == targetRect) {
                        QPointF currentPos = pea->pos();
                        QPointF zombiePos = zombieMap[targetRect].first;
                        plantattack(pa, targetRect); //i zombie rect
                        if (currentPos.x() >= zombiePos.x() + 7) {
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
    gridCentersMap[rect].first = point;
    plantMap[rect].second = pb;    //p
    plantMap[rect].first = point; //p
    pb->setPos(point);
    s->addItem(pb);
    if(plant==true){
        sunStorage -= 100;
        visibleButton();
        ui->label_2->setText(QString::number(sunStorage));
        int x=point.x();
        int y=point.y();
        emit SInsertPB(rect,x,y);
    }
    connect(pb, &Two_Peashooter::shootPea, this, [=]() { onShootPea(pb , point); });
    pb->startShooting();
    QTimer* checkTimer = new QTimer(this);
    connect(checkTimer, &QTimer::timeout, this, [=]() {
        if (isZombieInFront(rect)) {
            if (!pb->isShooting()) {
                connect(pb, &Two_Peashooter::shootPea, this, [=]() { onShootPea(pb, point); });
                pb->startShooting();
            }
        } else {
            if (pb->isShooting()) {
                //disconnect(pb, &Two_Peashooter::shootPea, this, nullptr);
                pb->stopShooting();
            }
        }
    });
    checkTimer->start(500);
}

void plantzombie::insertfieldPC(int rect , QPointF point)
{
    Walnut* pc = new Walnut;
    pc->move(point);
    QPair<Walnut*,int> pair(pc,rect);
    gridCentersMap[rect].second = "PC";
    gridCentersMap[rect].first = point;
    plantMap[rect].second = pc;    //p
    plantMap[rect].first = point; //p
    pc->setPos(point);
    s->addItem(pc);
    if(plant==true){
        sunStorage -= 100;
        visibleButton();
        ui->label_2->setText(QString::number(sunStorage));
        int x=point.x();
        int y=point.y();
        emit SInsertPC(rect,x,y);
    }
}
void plantzombie::insertfieldPD(int rect , QPointF point)
{
    PlumMine* pd = new PlumMine(s);
    QPair<PlumMine*,int> pair(pd,rect);
    gridCentersMap[rect].second = "PD";
    gridCentersMap[rect].first = point;
    plantMap[rect].second = pd;    //p
    plantMap[rect].first = point; //p
    pd->setPos(point);
    s->addItem(pd);

    if(plant==true){
        sunStorage -= 175;
        visibleButton();
        ui->label_2->setText(QString::number(sunStorage));
        int x=point.x();
        int y=point.y();
        emit SInsertPD(rect,x,y);
    }
    QTimer::singleShot(1000,pd,SLOT(explode()));
    connect(pd, &PlumMine::plumminefunction, this, [=]() {
        plumminefunction(rect, pd);
    });
}
void plantzombie::plumminefunction(int rect , PlantBase* pd){
    plantattack(pd,rect);
    plantMap.remove(rect);
    gridCentersMap[rect].second = "";
    //qDebug()<<"rect"<<rect;
    pd->deleteLater();
}

void plantzombie::plantattack(PlantBase *p , int rect) //server
{
    try {
        if (auto peashooter = dynamic_cast<Peashooter*>(p)) {
            try {
                if (zombieMap.contains(rect) && zombieMap[rect].second->getHealth() > 0) {
                    zombieMap[rect].second->setHealth(zombieMap[rect].second->getHealth() - p->getAttackPower());
                } else if (zombieMap.contains(rect) && zombieMap[rect].second->getHealth() <= 0) {
                    s->removeItem(zombieMap[rect].second);
                    gridCentersMap[rect].second = "";
                    zombieMap.remove(rect);
                }
            } catch (const std::exception &e) {
                qDebug() << "Exception in Peashooter: " << e.what();
            }
        } else if (auto twoPeashooter = dynamic_cast<Two_Peashooter*>(p)) {
            try {
                if (zombieMap.contains(rect) && zombieMap[rect].second->getHealth() > 0) {
                    zombieMap[rect].second->setHealth(zombieMap[rect].second->getHealth() - p->getAttackPower());
                } else if (zombieMap.contains(rect) && zombieMap[rect].second->getHealth() <= 0) {
                    s->removeItem(zombieMap[rect].second);
                    gridCentersMap[rect].second = "";
                    zombieMap.remove(rect);
                }
            } catch (const std::exception &e) {
                qDebug() << "Exception in Two_Peashooter: " << e.what();
            }
        } else if (auto boomerang = dynamic_cast<Boomerang*>(p)) {
            try {

                for (int i = 1; i < 12 - rect % 12; ++i) {
                    int targetRect = rect + i;
                    if (zombieMap.contains(targetRect) && zombieMap[targetRect].second && zombieMap[targetRect].second->getHealth() > 0 ) {
                            qDebug()<<"i"<<i<<targetRect;
                            zombieMap[targetRect].second->setHealth(zombieMap[targetRect].second->getHealth() - p->getAttackPower());
                    }
                    if (zombieMap.contains(targetRect)&& zombieMap[targetRect].second && zombieMap[targetRect].second->getHealth() <= 0) {
                        s->removeItem(zombieMap[targetRect].second);
                        gridCentersMap[targetRect].second = "";
                        zombieMap.remove(targetRect);
                    }
                    break;
                }
            } catch (const std::exception &e) {
                qDebug() << "Exception in Boomerang: " << e.what();
            }
        } else if (auto plumMine = dynamic_cast<PlumMine*>(p)) {
            try {
                QPointF plantPosition = gridCentersMap[rect].first;
                qDebug() << "plantPosition" << gridCentersMap[rect].first;
                for (auto it = zombieMap.constBegin(); it != zombieMap.constEnd(); ++it) {
                    if(it->second){
                        QPointF zombiePosition = gridCentersMap[it.key()].first;
                        qDebug() << "zombiePosition" << zombiePosition;
                        int dx = abs(plantPosition.x() - zombiePosition.x());
                        int dy = abs(plantPosition.y() - zombiePosition.y());
                        qDebug() << "dx" << dx << "dy" << dy;
                        if (dx <= 2 * 71 && dy <= 2 * 71) {
                            int key = it.key();
                            zombieMap[key].second->setHealth(zombieMap[key].second->getHealth() - p->getAttackPower());
                            if (zombieMap[key].second && zombieMap[key].second->getHealth() > 0) {
                                qDebug() << "before" << zombieMap[key].second->getHealth();
                            } else if( zombieMap[key].second && zombieMap[key].second->getHealth()<=0){
                                s->removeItem(zombieMap[key].second);
                                gridCentersMap[key].second = "";
                                zombieMap.remove(key);
                                qDebug() << "plum";
                            }
                        }
                    }

                }
            } catch (const std::exception &e) {
                qDebug() << "Exception in PlumMine: " << e.what();
            }
        } else if (auto jalapieno = dynamic_cast<Jalapieno*>(p)) {
            try {
                int row = rect / 12;
                int newrect = row * 12;
                qDebug()<<newrect;
                for (int i = newrect; i < newrect + 12; ++i) {
                    if (zombieMap.contains(i)) {
                        if (zombieMap[i].second && zombieMap[i].second->getHealth() > 0) {
                            zombieMap[i].second->setHealth(zombieMap[i].second->getHealth() - p->getAttackPower());
                        }
                        if (zombieMap[i].second && zombieMap[i].second->getHealth() <= 0) {
                            s->removeItem(zombieMap[i].second);
                            gridCentersMap[i].second = "";
                            zombieMap.remove(i);
                        }
                    }
                }
            } catch (const std::exception &e) {
                qDebug() << "Exception in Jalapieno: " << e.what();
            }
        }
    } catch (const std::exception &e) {
        qDebug() << "General exception: " << e.what();
    } catch (...) {
        qDebug() << "Unknown general exception";
    }
}

void plantzombie::insertfieldPE(int rect, QPointF point)
{
    Jalapieno* pe = new Jalapieno(s);
    QPair<Jalapieno*,int> pair(pe,rect);
    gridCentersMap[rect].second = "PE";
    gridCentersMap[rect].first = point;
    plantMap[rect].second = pe;    //p
    plantMap[rect].first = point; //p
    pe->setPos(point);
    s->addItem(pe);
    if(plant==true){
        sunStorage -= 150;
        visibleButton();
        ui->label_2->setText(QString::number(sunStorage));
        int x=point.x();
        int y=point.y();
        emit SInsertPE(rect,x,y);
    }
    QTimer::singleShot(1000, pe, SLOT(ignite()));
    connect(pe, &Jalapieno::burnRow, this, [=](){
        burnRow(rect ,pe);
    });
}

void plantzombie::burnRow(int rect , PlantBase* pe)
{
    plantattack(pe,rect);
    plantMap.remove(rect);
    gridCentersMap[rect].second = "";
}
void plantzombie::insertfieldPF(int rect, QPointF point)
{
    Boomerang* pf = new Boomerang;
    QPair<Boomerang*,int> pair(pf,rect);
    gridCentersMap[rect].second = "PF";
    gridCentersMap[rect].first = point;
    plantMap[rect].second = pf;    //p
    plantMap[rect].first = point; //p
    pf->setPos(point);
    s->addItem(pf);
    if(plant==true){
        sunStorage -= 125;
        visibleButton();
        ui->label_2->setText(QString::number(sunStorage));
        int x=point.x();
        int y=point.y();
        emit SInsertPF(rect,x,y);
    }
    QTimer* checkTimer = new QTimer(this);
    connect(checkTimer, &QTimer::timeout, this, [=]() {
        if (isZombieInFront(rect)) {
            if (!pf->isShooting()) {
                connect(pf, &Boomerang::shootPea, this, [=]() { onShootPea(pf, point); });
                pf->startShooting();
            }
        } else {
            if (pf->isShooting()) {
                disconnect(pf, &Boomerang::shootPea, this, nullptr);
                pf->stopShooting();
            }
        }
    });
    checkTimer->start(500);
}
void plantzombie::insertfieldZA(int rect, QPointF point)
{
    //RegularZambie* za = new RegularZambie;
    RegularZambie* za = new RegularZambie(s, plantMap, zombieMap,rect,gridRects,gridCentersMap);
    QPair<RegularZambie*,int> pair(za,rect);
    qDebug()<<"rect"<<rect;
    gridCentersMap[rect].second = "ZA";
    gridCentersMap[rect].first = point;
    zombieMap[rect].second = za;    //z
    zombieMap[rect].first = point; //z
    za->setPos(point);
    s->addItem(za);
    if(Zombie==true){
        brainStorge -= 100;
        visibleButton();
        ui->Brainlabel->setText(QString::number(brainStorge));
        int x=point.x();
        int y=point.y();
        emit SInsertZA(rect,x,y);
    }

}
void plantzombie::insertfieldZB(int rect, QPointF point)
{
    BucketHeadZombie* zb = new BucketHeadZombie(s, plantMap, zombieMap,rect,gridRects,gridCentersMap);
    QPair<BucketHeadZombie*,int> pair(zb,rect);
    gridCentersMap[rect].second = "ZB";
    gridCentersMap[rect].first = point;
    zombieMap[rect].second = zb;    //z
    zombieMap[rect].first = point; //z
    zb->setPos(point);
    s->addItem(zb);
    if(Zombie==true){
        brainStorge -= 200;
        visibleButton();
        ui->Brainlabel->setText(QString::number(brainStorge));
        int x=point.x();
        int y=point.y();
        emit SInsertZB(rect,x,y);
    }
}
void plantzombie::insertfieldZC(int rect, QPointF point)
{
    LeafHeadZombie* zc = new LeafHeadZombie(s, plantMap, zombieMap,rect,gridRects,gridCentersMap);
    QPair<LeafHeadZombie*,int> pair(zc,rect);
    gridCentersMap[rect].second = "ZC";
    gridCentersMap[rect].first = point;
    zombieMap[rect].second = zc;    //z
    zombieMap[rect].first = point; //z
    zc->setPos(point);
    s->addItem(zc);
    if(Zombie==true){
        brainStorge -= 150;
        visibleButton();
        ui->Brainlabel->setText(QString::number(brainStorge));
        int x=point.x();
        int y=point.y();
        emit SInsertZC(rect,x,y);
    }
}
void plantzombie::insertfieldZD(int rect, QPointF point)
{
    TallZombie* zd = new TallZombie(s, plantMap, zombieMap,rect,gridRects,gridCentersMap);
    QPair<TallZombie*,int> pair(zd,rect);
    gridCentersMap[rect].second = "ZD";
    gridCentersMap[rect].first = point;
    zombieMap[rect].second = zd;    //z
    zombieMap[rect].first = point; //z
    zd->setPos(point);
    s->addItem(zd);
    if(Zombie==true){
        brainStorge -= 150;
        visibleButton();
        ui->Brainlabel->setText(QString::number(brainStorge));
        int x=point.x();
        int y=point.y();
        emit SInsertZD(rect,x,y);
    }
}
void plantzombie::insertfieldZE(int rect, QPointF point)
{
    AstronautZombie* ze = new AstronautZombie(s, plantMap, zombieMap,rect,gridRects,gridCentersMap);
    QPair<AstronautZombie*,int> pair(ze,rect);
    gridCentersMap[rect].second = "ZE";
    gridCentersMap[rect].first = point;
    zombieMap[rect].second = ze;    //z
    zombieMap[rect].first = point; //z
    ze->setPos(point);
    s->addItem(ze);
    if(Zombie==true){
        brainStorge -= 200;
        visibleButton();
        ui->Brainlabel->setText(QString::number(brainStorge));
        int x=point.x();
        int y=point.y();
        emit SInsertZE(rect,x,y);
    }
}
void plantzombie::insertfieldZF(int rect, QPointF point)
{
    PurpleHairZombie* zf = new PurpleHairZombie(s, plantMap, zombieMap,rect,gridRects,gridCentersMap);
    QPair<PurpleHairZombie*,int> pair(zf,rect);
    gridCentersMap[rect].second = "ZF";
    gridCentersMap[rect].first = point;
    zombieMap[rect].second = zf;    //z
    zombieMap[rect].first = point; //z
    zf->setPos(point);
    s->addItem(zf);
    if(Zombie==true){
        brainStorge -= 800;
        visibleButton();
        ui->Brainlabel->setText(QString::number(brainStorge));
        int x=point.x();
        int y=point.y();
        emit SInsertZF(rect,x,y);
    }
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
    if(plant==true){

        Sun *sun = new Sun();
        sun->setScale(0.1);
        s->addItem(sun);
        sun->setPos(QRandomGenerator::global()->bounded(400)+100, QRandomGenerator::global()->bounded(350)+25);
        connect(sun, &Sun::clicked, this, &plantzombie::handleSunClick);
    }
}

void plantzombie::handleSunClick() {
    sunStorage += 25;
    visibleButton();
    ui->label_2->setText(QString::number(sunStorage));
    }
void plantzombie::spawnBrain()
{
    if(Zombie==true){
        Brain *brain = new Brain();
        brain->setScale(0.25);
        s->addItem(brain);
        brain->setPos(QRandomGenerator::global()->bounded(400)+600, QRandomGenerator::global()->bounded(350)+25);
        connect(brain, &Brain::clicked, this, &plantzombie::handleBrainClick);
    }
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
    QPointF viewPos = event->pos();
    int a = viewPos.y();
    viewPos.setY(a - 150);

    currentGridIndex = -1;
    for (int i = 0; i < gridRects.size(); ++i) {
        if (gridRects[i].contains(viewPos)) {
            currentGridIndex = i;
            break;
        }
    }

    if (currentGridIndex == -1) {
        return;
    }

    QPointF pointpixmap;
    pointpixmap.setX(gridRects[currentGridIndex].topLeft().x() - 1);
    pointpixmap.setY(gridRects[currentGridIndex].topLeft().y() + 1);

    if (event->button() == Qt::LeftButton) {
        QString str = gridCentersMap.find(currentGridIndex)->second;
        if (isDrawingPA) {
            if ((currentGridIndex + 1) % 12 < 7 && (currentGridIndex + 1) % 12 != 0 && str == "") {
                insertfieldPA(currentGridIndex, pointpixmap);
                isDrawingPA = false;
                gridCentersMap.find(currentGridIndex)->second = "PA";
            }
        } else if (isDrawingPB) {
            if ((currentGridIndex + 1) % 12 < 7 && (currentGridIndex + 1) % 12 != 0 && str == "") {
                insertfieldPB(currentGridIndex, pointpixmap);
                isDrawingPB = false;
                gridCentersMap.find(currentGridIndex)->second = "PB";
            }
        } else if (isDrawingPC) {
            if ((currentGridIndex + 1) % 12 < 7 && (currentGridIndex + 1) % 12 != 0 && str == "") {
                insertfieldPC(currentGridIndex, pointpixmap);
                isDrawingPC = false;
                gridCentersMap.find(currentGridIndex)->second = "PC";
            }
        } else if (isDrawingPD) {
            if ((currentGridIndex + 1) % 12 < 7 && (currentGridIndex + 1) % 12 != 0 && str == "") {
                insertfieldPD(currentGridIndex, pointpixmap);
                isDrawingPD = false;
                gridCentersMap.find(currentGridIndex)->second = "PD";
            }
        } else if (isDrawingPE) {
            if ((currentGridIndex + 1) % 12 < 7 && (currentGridIndex + 1) % 12 != 0 && str == "") {
                insertfieldPE(currentGridIndex, pointpixmap);
                isDrawingPE = false;
                gridCentersMap.find(currentGridIndex)->second = "PE";
            }
        } else if (isDrawingPF) {
            if ((currentGridIndex + 1) % 12 < 7 && (currentGridIndex + 1) % 12 != 0 && str == "") {
                insertfieldPF(currentGridIndex, pointpixmap);
                isDrawingPF = false;
                gridCentersMap.find(currentGridIndex)->second = "PF";
            }
        } else if (isDrawingZA) {
            if ((currentGridIndex + 1) % 12 == 0 && str == "") {
                insertfieldZA(currentGridIndex, pointpixmap);
                isDrawingZA = false;
                gridCentersMap.find(currentGridIndex)->second = "ZA";
            }
        } else if (isDrawingZB) {
            if ((currentGridIndex + 1) % 12 == 0 && str == "") {
                insertfieldZB(currentGridIndex, pointpixmap);
                isDrawingZB = false;
                gridCentersMap.find(currentGridIndex)->second = "ZB";
            }
        } else if (isDrawingZC) {
            if ((currentGridIndex + 1) % 12 == 0 && str == "") {
                insertfieldZC(currentGridIndex, pointpixmap);
                isDrawingZC = false;
                gridCentersMap.find(currentGridIndex)->second = "ZC";
            }
        } else if (isDrawingZD) {
            if ((currentGridIndex + 1) % 12 == 0 && str == "") {
                insertfieldZD(currentGridIndex, pointpixmap);
                isDrawingZD = false;
                gridCentersMap.find(currentGridIndex)->second = "ZD";
            }
        } else if (isDrawingZE) {
            if ((currentGridIndex + 1) % 12 == 0 && str == "") {
                insertfieldZE(currentGridIndex, pointpixmap);
                isDrawingZE = false;
                gridCentersMap.find(currentGridIndex)->second = "ZE";
            }
        } else if (isDrawingZF) {
            if ((currentGridIndex + 1) % 12 == 0 && str == "") {
                insertfieldZF(currentGridIndex, pointpixmap);
                isDrawingZF = false;
                gridCentersMap.find(currentGridIndex)->second = "ZF";
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

