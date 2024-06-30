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

#include <rects.h>
#include <QMap>
#include <QPointF>
#include <QPair>

#include <QMouseEvent>
namespace Ui {
class plantzombie;
}

class plantzombie : public QMainWindow
{
    Q_OBJECT

public:
    explicit plantzombie(QWidget *parent = nullptr);
    ~plantzombie();
private slots:
    void spawnSun();
    void handleSunClick();
    void spawnBrain();
    void handleBrainClick();
    //void onCircleButtonClicked();

    void on_pushButton_clicked();

private:
    Ui::plantzombie *ui;
    QTimer *sunspawnTimer;
    QTimer *brainspawnTimer;
    QGraphicsScene *s;
    int sunStorage;
    //QGraphicsView *view;
    QGraphicsPixmapItem *f ;

    int brainStorge;

    QLabel *label1;
    QMap<int, QPair<QPointF,int>> gridCentersMap;
    QList<QRectF> gridRects;
    int currentGridIndex = -1;
    //bool isDrawingCircle = false;// مث اینجا ساخت بول به نام گیاه و زامبی ها
protected:
    void divideImageIntoGrid(int rows, int columns);
    QMap<int, QPair<QPointF,int>> createGridCentersMap();
    void mousePressEvent(QMouseEvent *event) override;

};

#endif // PLANTZOMBIE_H
