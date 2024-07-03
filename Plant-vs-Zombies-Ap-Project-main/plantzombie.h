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
namespace Ui {
class plantzombie;
}

class plantzombie : public QMainWindow
{
    Q_OBJECT

public:
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

    void visibleButton();
protected:
    void divideImageIntoGrid(int rows, int columns);
    QMap<int, QPair<QPointF,QString>> createGridCentersMap();
    void mousePressEvent(QMouseEvent *event) override;

};

#endif // PLANTZOMBIE_H
