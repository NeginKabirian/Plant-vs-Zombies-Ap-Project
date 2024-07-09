#include "forgetpass.h"
#include "ui_forgetpass.h"
#include <QMessageBox>
#include <QRegularExpression>
forgetpass::forgetpass(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::forgetpass)
{
    ui->setupUi(this);
}

forgetpass::~forgetpass()
{
    delete ui;
}

void forgetpass::checkPasswordStrength(const QString &password)
{
    // Check minimum length
    if (password.length() < 8) {
        throw(MyException("Password Error!!password must be at least 8 char"));
    }

    // Check for at least one uppercase letter
    if (password.toLower() == password) {
        throw(MyException("Password Error!!password must be at least one uppercase letter"));
    }

    // Check for at least one lowercase letter
    if (password.toUpper() == password) {
        throw(MyException("Password Error!!password must be at least one lowercase letter"));
    }

    // Check for at least one digit
    if (!password.contains(QRegularExpression("\\d"))) {
        throw(MyException("Password Error!!password must be at least one digit"));
    }


}

void forgetpass::on_pushButton_clicked()
{
    try{
        checkPasswordStrength(ui->Password_lineEdit->text());
        QString username=ui->Username_lineEdit->text();
        QString password=ui->Password_lineEdit->text();
        QString phone =ui->PhoneNumber_lineEdit->text();
        QString message = QString("forgetpassword,%1,%2,%3").arg(username).arg(phone).arg(password);
        emit messageforgetpass(message);
        ui->Password_lineEdit->clear();
        ui->PhoneNumber_lineEdit->clear();
        ui->Username_lineEdit->clear();
    }
    catch(MyException& e){
        QMessageBox::critical(this,"ERROR",e.what());
    }

}

