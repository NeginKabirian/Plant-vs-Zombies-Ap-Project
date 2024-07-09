#include "waitstart.h"
#include "ui_waitstart.h"

waitstart::waitstart(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::waitstart)
{
    ui->setupUi(this);
}

waitstart::~waitstart()
{
    delete ui;
}
