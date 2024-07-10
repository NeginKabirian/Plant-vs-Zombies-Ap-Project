/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

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

class Ui_login
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *Username_lineEdit;
    QLabel *label_6;
    QLineEdit *Password_lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName("login");
        login->resize(1098, 553);
        centralwidget = new QWidget(login);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 10, 1051, 501));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label->setPixmap(QPixmap(QString::fromUtf8(":/image/Annotation 2024-07-07 175523.png")));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(300, 190, 111, 21));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Georgia")});
        font1.setPointSize(18);
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(254, 255, 203);"));
        Username_lineEdit = new QLineEdit(centralwidget);
        Username_lineEdit->setObjectName("Username_lineEdit");
        Username_lineEdit->setGeometry(QRect(440, 180, 331, 31));
        Username_lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(144, 138, 137);"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(300, 240, 101, 21));
        label_6->setFont(font1);
        label_6->setStyleSheet(QString::fromUtf8("background-color: rgb(254, 255, 203);"));
        Password_lineEdit = new QLineEdit(centralwidget);
        Password_lineEdit->setObjectName("Password_lineEdit");
        Password_lineEdit->setGeometry(QRect(440, 240, 331, 31));
        Password_lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(144, 138, 137);"));
        Password_lineEdit->setEchoMode(QLineEdit::Password);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(350, 440, 201, 51));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Georgia")});
        font2.setPointSize(26);
        pushButton->setFont(font2);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(112, 71, 52);\n"
"color: rgb(255, 255, 255);\n"
"alternate-background-color: rgb(132, 66, 0);\n"
"\n"
"background-color: rgb(144, 72, 0);"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(580, 440, 201, 51));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Georgia")});
        font3.setPointSize(20);
        pushButton_2->setFont(font3);
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(112, 71, 52);\n"
"color: rgb(255, 255, 255);\n"
"alternate-background-color: rgb(132, 66, 0);\n"
"\n"
"background-color: rgb(144, 72, 0);"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(650, 380, 121, 31));
        pushButton_3->setFont(font3);
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(112, 71, 52);\n"
"background-color: rgb(162, 255, 119);\n"
"color: rgb(255, 255, 255);\n"
"alternate-background-color: rgb(132, 66, 0);\n"
"\n"
"background-color: rgb(144, 72, 0);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(290, 380, 351, 31));
        QFont font4;
        font4.setPointSize(18);
        label_2->setFont(font4);
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(142, 255, 101);"));
        login->setCentralWidget(centralwidget);
        menubar = new QMenuBar(login);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1098, 22));
        login->setMenuBar(menubar);
        statusbar = new QStatusBar(login);
        statusbar->setObjectName("statusbar");
        login->setStatusBar(statusbar);

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QMainWindow *login)
    {
        login->setWindowTitle(QCoreApplication::translate("login", "MainWindow", nullptr));
        label->setText(QString());
        label_3->setText(QCoreApplication::translate("login", "username", nullptr));
        label_6->setText(QCoreApplication::translate("login", "password", nullptr));
        pushButton->setText(QCoreApplication::translate("login", "log in", nullptr));
        pushButton_2->setText(QCoreApplication::translate("login", "forget password", nullptr));
        pushButton_3->setText(QCoreApplication::translate("login", "sign up", nullptr));
        label_2->setText(QCoreApplication::translate("login", "Don't have an Action Acvount?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
