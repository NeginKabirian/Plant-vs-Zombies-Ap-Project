#ifndef ZOMBIEPLANET_H
#define ZOMBIEPLANET_H

#include <QDialog>
#include <QApplication>
#include <QLabel>
namespace Ui {
class zombieplanet;
}

class zombieplanet : public QDialog
{
    Q_OBJECT

public:
    explicit zombieplanet(QWidget *parent = nullptr);
    ~zombieplanet();

private:
    Ui::zombieplanet *ui;
};

#endif // ZOMBIEPLANET_H
