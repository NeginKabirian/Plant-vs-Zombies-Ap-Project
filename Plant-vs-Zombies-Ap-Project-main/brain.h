#ifndef BRAIN_H
#define BRAIN_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QObject>

class Brain  : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Brain();
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

#endif // BRAIN_H
