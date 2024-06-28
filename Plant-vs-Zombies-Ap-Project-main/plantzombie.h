#ifndef PLANTZOMBIE_H
#define PLANTZOMBIE_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QSizePolicy>
#include<QTimer>
#include<sun.h>
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

private:
    Ui::plantzombie *ui;
    QTimer *spawnTimer;
    QGraphicsScene *s;
    int sunStorage;
    QGraphicsView *view;
    QGraphicsPixmapItem *f ;
};

#endif // PLANTZOMBIE_H
