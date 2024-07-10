#ifndef PLANTZOMBIE_H
#define PLANTZOMBIE_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QSizePolicy>
#include<QTimer>
#include<sun.h>
#include <QGraphicsSceneMouseEvent>
#include<brain.h>
#include <QLabel>
#include<peashooter.h>
#include<two_peashooter.h>
#include<walnut.h>
#include<plummine.h>
#include<jalapieno.h>
#include<boomerang.h>
#include<regularzambie.h>
#include<bucketheadzombie.h>
#include<leafheadzombie.h>
#include<tallzombie.h>
#include<astronautzombie.h>
#include<purplehairzombie.h>
#include <rects.h>
#include <QMap>
#include <QPointF>
#include <QPair>
#include<QPushButton>
#include <QMouseEvent>
#include <QAtomicInt>
#include<plantbase.h>
#include<QPropertyAnimation>
#include <QDebug>
#include<QGraphicsPixmapItem>
#include <QGraphicsScene>
#include<QRandomGenerator>
#include <QGraphicsView>
#include <QRectF>
namespace Ui {
class plantzombie;
}

class plantzombie : public QMainWindow
{
    Q_OBJECT

public:
    bool Zombie=true;
    bool plant=true;
    explicit plantzombie(QWidget *parent = nullptr);
    ~plantzombie();
    void insertfieldPA(int rect = -1 ,QPointF point = QPointF(0,0)); //12
    void insertfieldPB(int rect = -1,QPointF point = QPointF(0,0));
    void insertfieldPC(int rect = -1,QPointF point = QPointF(0,0));
    void insertfieldPD(int rect = -1,QPointF point = QPointF(0,0));
    void insertfieldPE(int rect = -1,QPointF point = QPointF(0,0));
    void insertfieldPF(int rect = -1,QPointF point = QPointF(0,0));
    void insertfieldZA(int rect = -1,QPointF point = QPointF(0,0));
    void insertfieldZB(int rect = -1,QPointF point = QPointF(0,0));
    void insertfieldZC(int rect = -1,QPointF point = QPointF(0,0));
    void insertfieldZD(int rect = -1,QPointF point = QPointF(0,0));
    void insertfieldZE(int rect = -1,QPointF point = QPointF(0,0));
    void insertfieldZF(int rect = -1,QPointF point = QPointF(0,0));
    void visibleButton();
    //void visibleButton();
    int ChangePosToRect(QPointF);
private slots:
    void spawnSun();
    void handleSunClick();
    void spawnBrain();
    void handleBrainClick();
    //void onCircleButtonClicked();
    void onButtonPAClicked();
    void onButtonPBClicked();
    void onButtonPCClicked();
    void onButtonPDClicked();
    void onButtonPEClicked();
    void onButtonPFClicked();
    void onButtonZAClicked();
    void onButtonZBClicked();
    void onButtonZCClicked();
    void onButtonZDClicked();
    void onButtonZEClicked();
    void onButtonZFClicked();

    void on_pushButtonPA_clicked();

    void on_pushButtonPB_clicked();

    void on_pushButtonPC_clicked();

    void on_pushButtonPD_clicked();

    void on_pushButtonPE_clicked();

    void on_pushButtonPF_clicked();

    void on_pushButtonZA_clicked();

    void on_pushButtonZB_clicked();

    void on_pushButtonZC_clicked();

    void on_pushButtonZD_clicked();

    void on_pushButtonZE_clicked();

    void on_pushButtonZF_clicked();
    //slot for plant
    void onShootPea(PlantBase* , QPointF);
    void burnRow(int rect , PlantBase*);
    void plumminefunction(int rect , PlantBase*);
    void plantattack(PlantBase* , int);

private:
    Ui::plantzombie *ui;
    QTimer *sunspawnTimer;
    QTimer *brainspawnTimer;
    QGraphicsScene *s;
    //int sunStorage;
    QGraphicsPixmapItem *f ;
    std::atomic<int> sunStorage;
    int brainStorge;

    QLabel *label1;
    QMap<int, QPair<QPointF,QString>> gridCentersMap;
    QMap<int, QPair<QPointF,PlantBase*>> plantMap;
    QMap<int, QPair<QPointF,ZombieBase*>> zombieMap;
    QList<QRectF> gridRects;
    int currentGridIndex = -1;
    bool isDrawingPA = false;
    bool isDrawingPB = false;
    bool isDrawingPC = false;
    bool isDrawingPD = false;
    bool isDrawingPE = false;
    bool isDrawingPF = false;
    bool isDrawingZA = false;
    bool isDrawingZB = false;
    bool isDrawingZC = false;
    bool isDrawingZD = false;
    bool isDrawingZE = false;
    bool isDrawingZF = false;
    //vector pair<class obj,number rect> rect = -1 default
    //delete vector
    QVector<QPair<Peashooter*,int>>PA;
    QVector<QPair<Two_Peashooter*,int>>PB;
    QVector<QPair<Walnut*,int>>PC;
    QVector<QPair<PlumMine*,int>>PD;
    QVector<QPair<Jalapieno*,int>>PE;
    QVector<QPair<Boomerang*,int>>PF;

    QVector<QPair<RegularZambie*,int>>ZA;
    QVector<QPair<BucketHeadZombie*,int>>ZB;
    QVector<QPair<LeafHeadZombie*,int>>ZC;
    QVector<QPair<TallZombie*,int>>ZD;
    QVector<QPair<AstronautZombie*,int>>ZE;
    QVector<QPair<PurpleHairZombie*,int>>ZF;
    QTimer* moveTimer;
    bool isZombieInFront(int);
protected:
    void divideImageIntoGrid(int rows, int columns);
    QMap<int, QPair<QPointF,QString>> createGridCentersMap();
    void mousePressEvent(QMouseEvent *event) override;
signals:
    void SInsertPA(int rect,int x,int y);
    void SInsertPB(int rect,int x,int y);
    void SInsertPC(int rect,int x,int y);
    void SInsertPD(int rect,int x,int y);
    void SInsertPE(int rect,int x,int y);
    void SInsertPF(int rect,int x,int y);
    void SInsertZA(int rect,int x,int y);
    void SInsertZB(int rect,int x,int y);
    void SInsertZC(int rect,int x,int y);
    void SInsertZD(int rect,int x,int y);
    void SInsertZE(int rect,int x,int y);
    void SInsertZF(int rect,int x,int y);
};

#endif // PLANTZOMBIE_H
