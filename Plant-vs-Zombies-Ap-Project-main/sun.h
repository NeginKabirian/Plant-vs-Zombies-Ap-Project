#ifndef SUN_H
#define SUN_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
class Sun :public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Sun();
signals:
    void clicked();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    QTimer *timer;
    QTimer *disappearTimer;
private slots:
    void disappear();
};

#endif // SUN_H
