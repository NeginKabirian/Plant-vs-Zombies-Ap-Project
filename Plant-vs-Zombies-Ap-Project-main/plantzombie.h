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
    QMap<QPair<ClickableRectItem*,int>,QPair<QPointF,int>> rectmap;



};

#endif // PLANTZOMBIE_H
