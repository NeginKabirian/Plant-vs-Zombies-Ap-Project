#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    QString username=ui->Username_lineEdit->text();
    usernamee=username;
    QString password=ui->Password_lineEdit->text();
    QString message = QString("login,%1,%2").arg(username).arg(password);
    emit sendmessagelogin(message);
}


void login::on_pushButton_2_clicked()
{
    ui->Password_lineEdit->clear();
    ui->Username_lineEdit->clear();
    emit uiforgetpass();
}


void login::on_pushButton_3_clicked()
{
    emit uisignup();
}

