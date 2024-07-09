#ifndef WAITSTART_H
#define WAITSTART_H

#include <QMainWindow>

namespace Ui {
class waitstart;
}

class waitstart : public QMainWindow
{
    Q_OBJECT

public:
    explicit waitstart(QWidget *parent = nullptr);
    ~waitstart();

private:
    Ui::waitstart *ui;
};

#endif // WAITSTART_H
