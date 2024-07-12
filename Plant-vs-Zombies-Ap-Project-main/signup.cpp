#include "signup.h"
#include "ui_signup.h"
#include <QPalette>
#include <QColor>
#include <string>
signup::signup(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
    QPalette p;
    QColor c=QColor(160,32,240);
    p.setColor(QPalette::WindowText,c);
    ui->label->setPalette(p);
    ui->label_2->setPalette(p);
    ui->label_3->setPalette(p);
    ui->label_4->setPalette(p);
    ui->label_5->setPalette(p);
    ui->label_6->setPalette(p);

}

signup::~signup()
{
    delete ui;
}

void signup::checkPasswordStrength(const QString &password)
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

    // Check for at least one special character
    //if (!password.contains(QRegularExpression("[!@#$%^&*()_+\\-=\$$\$${};':\"\\\\|,.<>\\/?]"))) {
        //return false;
    //}
}

bool signup::isValidEmail(const QString &email)
{
    QString emailPattern = "^[_a-z0-9-]+(\\.[_a-z0-9-]+)*@[a-z0-9-]+(\\.[a-z0-9-]+)*(\\.[a-z]{2,})$";
    QRegularExpression regex(emailPattern, QRegularExpression::CaseInsensitiveOption);
    QRegularExpressionMatch match = regex.match(email);
    return match.hasMatch();
}

bool signup::isValidPhoneNumber(const QString &phoneNumber)
{
    QString phonePattern = "^\\+98\\d{10}$";
    QRegularExpression regex(phonePattern);
    QRegularExpressionMatch match = regex.match(phoneNumber);
    return match.hasMatch();
}

void signup::on_pushButton_clicked()
{
    //std::string email = ui->Address_lineEdit->text().toStdString();

    try{
        if(ui->Name_lineEdit->text() == "" || ui->Username_lineEdit->text() == "" || ui->Address_lineEdit->text() == "" || ui->Password_lineEdit->text() == "" || ui->PhoneNumber_lineEdit->text() == ""){
            throw(MyException("Incomplite field!!"));
        }
        checkPasswordStrength(ui->Password_lineEdit->text()); //password check
        if(!isValidEmail(ui->Address_lineEdit->text())){ //email check
            throw(MyException("InValidEmail!!"));
        }
        if(!isValidPhoneNumber(ui->PhoneNumber_lineEdit->text())){ //email check
            throw(MyException("InValidPhonNumber!!"));
        }

        qDebug()<<"a";
        QString name=ui->Name_lineEdit->text();
        QString username=ui->Username_lineEdit->text();
        QString phone=ui->PhoneNumber_lineEdit->text();
        QString address = ui->Address_lineEdit->text();
        QString password = ui->Password_lineEdit->text();
        QString s="siginup";
        QString a=",";
        //QString message=s+a+name+a+username+a+phone+a+address+a+password;
        QString message = QString("signup,%1,%2,%3,%4,%5").arg(username).arg(name).arg(phone).arg(address).arg(password);
        emit sendmessage(message);
        qDebug()<<"yy";
        //if(!unigusername){
            //throw(MyException("this username is already taken."));
        //}
        qDebug()<<"c";
    }
    catch(MyException& e){
        QMessageBox::critical(this,"ERROR",e.what());
    }

}


