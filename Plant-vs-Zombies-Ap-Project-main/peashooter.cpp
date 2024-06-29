/*#include "peashooter.h"
#include <QPixmap>
#include <QTimer>

PeaShooter::PeaShooter() : QObject(), QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/image/peashooter transparent.png"));
    setScale(0.1);
    shakeAnimation = new QPropertyAnimation(this, "pos");
    shakeAnimation->setDuration(1000); // مدت زمان انیمیشن (مثلا 1000 میلی‌ثانیه برای انیمیشن کامل)
    shakeAnimation->setLoopCount(-1); // یک بار
    shakeAnimation->setStartValue(pos());
    shakeAnimation->setKeyValueAt(0.1, pos() + QPointF(3, 0)); // مکان اولیه تکون
    shakeAnimation->setKeyValueAt(0.2, pos() - QPointF(3, 0)); // مکان دومیه تکون
    shakeAnimation->setEndValue(pos()); // مکان اولیه
    connect(shakeAnimation, &QPropertyAnimation::finished, this, &PeaShooter::returnToOriginalPosition);
    shakeAnimation->start();
}

void PeaShooter::returnToOriginalPosition()
{
    setPos(QPointF(130, 50)); // تنظیم مکان اولیه PeaShooter
}*/
