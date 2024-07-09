#include "mainwindow2.h"
#include "ui_mainwindow2.h"

MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this);
    plantzombie *game = new plantzombie();
   // ui->setupUi(game);
    client = new Client(game);
    client->connectToServer("127.0.0.1", 12345);
}

MainWindow2::~MainWindow2()
{
    delete ui;
}

void MainWindow2::on_pushButton_2_clicked()
{
    this->close();
    client->Login->show();
}


void MainWindow2::on_pushButton_clicked()
{
    this->close();
    client->Signup->show();
}

