/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_signup
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *Name_lineEdit;
    QLabel *label_2;
    QLineEdit *Username_lineEdit;
    QLineEdit *PhoneNumber_lineEdit;
    QLineEdit *Address_lineEdit;
    QLineEdit *Password_lineEdit;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *signup)
    {
        if (signup->objectName().isEmpty())
            signup->setObjectName("signup");
        signup->resize(1075, 576);
        centralwidget = new QWidget(signup);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 30, 1051, 501));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label->setPixmap(QPixmap(QString::fromUtf8(":/image/Annotation 2024-07-07 175523.png")));
        Name_lineEdit = new QLineEdit(centralwidget);
        Name_lineEdit->setObjectName("Name_lineEdit");
        Name_lineEdit->setGeometry(QRect(390, 160, 331, 31));
        Name_lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(144, 138, 137);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(210, 160, 91, 21));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Georgia")});
        font1.setPointSize(18);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(244, 255, 188);\n"
"background-color: rgb(254, 255, 203);"));
        Username_lineEdit = new QLineEdit(centralwidget);
        Username_lineEdit->setObjectName("Username_lineEdit");
        Username_lineEdit->setGeometry(QRect(390, 200, 331, 31));
        Username_lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(144, 138, 137);"));
        PhoneNumber_lineEdit = new QLineEdit(centralwidget);
        PhoneNumber_lineEdit->setObjectName("PhoneNumber_lineEdit");
        PhoneNumber_lineEdit->setGeometry(QRect(390, 240, 331, 31));
        PhoneNumber_lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(144, 138, 137);"));
        Address_lineEdit = new QLineEdit(centralwidget);
        Address_lineEdit->setObjectName("Address_lineEdit");
        Address_lineEdit->setGeometry(QRect(390, 281, 331, 31));
        Address_lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(144, 138, 137);"));
        Password_lineEdit = new QLineEdit(centralwidget);
        Password_lineEdit->setObjectName("Password_lineEdit");
        Password_lineEdit->setGeometry(QRect(390, 321, 331, 31));
        Password_lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(144, 138, 137);"));
        Password_lineEdit->setEchoMode(QLineEdit::Password);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(210, 210, 111, 21));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(254, 255, 203);"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(210, 250, 161, 21));
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(254, 255, 203);"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(210, 290, 91, 21));
        label_5->setFont(font1);
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgb(254, 255, 203);"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(210, 325, 101, 21));
        label_6->setFont(font1);
        label_6->setStyleSheet(QString::fromUtf8("background-color: rgb(254, 255, 203);"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(460, 460, 151, 51));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Georgia")});
        font2.setPointSize(26);
        pushButton->setFont(font2);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(112, 71, 52);\n"
"color: rgb(255, 255, 255);\n"
"alternate-background-color: rgb(132, 66, 0);\n"
"\n"
"background-color: rgb(144, 72, 0);"));
        signup->setCentralWidget(centralwidget);
        menubar = new QMenuBar(signup);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1075, 22));
        signup->setMenuBar(menubar);
        statusbar = new QStatusBar(signup);
        statusbar->setObjectName("statusbar");
        signup->setStatusBar(statusbar);

        retranslateUi(signup);

        QMetaObject::connectSlotsByName(signup);
    } // setupUi

    void retranslateUi(QMainWindow *signup)
    {
        signup->setWindowTitle(QCoreApplication::translate("signup", "MainWindow", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("signup", "Name", nullptr));
        label_3->setText(QCoreApplication::translate("signup", "username", nullptr));
        label_4->setText(QCoreApplication::translate("signup", "phone number", nullptr));
        label_5->setText(QCoreApplication::translate("signup", "address", nullptr));
        label_6->setText(QCoreApplication::translate("signup", "password", nullptr));
        pushButton->setText(QCoreApplication::translate("signup", "sign up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class signup: public Ui_signup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
