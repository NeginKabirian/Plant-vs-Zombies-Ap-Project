#ifndef SIGNUP_H
#define SIGNUP_H

#include <QMainWindow>
#include "QMessageBox"
#include "myexception.h"
#include<QJsonDocument>
#include<QJsonObject>
#include<QFile>
#include<QCryptographicHash>
#include <QJsonObject>
#include <QJsonDocument>
#include <QCoreApplication>
#include <QTcpSocket>
#include <QJsonObject>
#include <QJsonDocument>
#include <QTextStream>
namespace Ui {
class signup;
}

class signup : public QMainWindow
{
    Q_OBJECT

public:
    bool unigusername=false;
    explicit signup(QWidget *parent = nullptr);
    ~signup();
    void checkPasswordStrength(const QString& password);
    bool isValidEmail(const QString& email);
    bool isValidPhoneNumber(const QString& phoneNumber);

private slots:
    void on_pushButton_clicked();

private:
    Ui::signup *ui;
signals:
    void sendmessage(QString message);
};

#endif // SIGNUP_H
