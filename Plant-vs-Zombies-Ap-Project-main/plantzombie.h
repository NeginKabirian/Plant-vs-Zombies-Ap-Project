#ifndef PLANTZOMBIE_H
#define PLANTZOMBIE_H

#include <QMainWindow>

namespace Ui {
class plantzombie;
}

class plantzombie : public QMainWindow
{
    Q_OBJECT

public:
    explicit plantzombie(QWidget *parent = nullptr);
    ~plantzombie();

private:
    Ui::plantzombie *ui;
};

#endif // PLANTZOMBIE_H
