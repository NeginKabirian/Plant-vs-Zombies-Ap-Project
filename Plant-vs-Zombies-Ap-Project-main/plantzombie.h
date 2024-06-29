#ifndef PLANTZOMBIE_H
#define PLANTZOMBIE_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QSizePolicy>
#include<QTimer>
#include<sun.h>
#include <iostream>
#include <random>
#include <QGraphicsSceneMouseEvent>
#include <clicbrain.h>
#include <QLabel>
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

protected:
    //void add_brain();
    void add_number_brain();
    void add_brain();

private:
    Ui::plantzombie *ui;
    QTimer *spawnTimer;
    QGraphicsScene *s;
    int sunStorage;
    QGraphicsView *view;
    QGraphicsPixmapItem *f ;
    QGraphicsPixmapItem *brainItem ;
    BrainPixmapItem *brainshow ;
    QTimer *timer;
    int number_brain;
    QLabel *label1;
};

#endif // PLANTZOMBIE_H
