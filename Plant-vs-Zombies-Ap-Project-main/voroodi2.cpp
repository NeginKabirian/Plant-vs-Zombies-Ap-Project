#include "voroodi2.h"
#include "ui_voroodi2.h"

voroodi2::voroodi2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::voroodi2)
{
    ui->setupUi(this);
}

voroodi2::~voroodi2()
{
    delete ui;
}

void voroodi2::on_pushButton_clicked()
{
    emit startgame();
}


void voroodi2::on_pushButton_2_clicked()
{
    emit SHistory();
}

