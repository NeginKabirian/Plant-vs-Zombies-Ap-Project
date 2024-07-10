/********************************************************************************
** Form generated from reading UI file 'forgetpass.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORGETPASS_H
#define UI_FORGETPASS_H

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

class Ui_forgetpass
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_6;
    QLineEdit *Username_lineEdit;
    QLineEdit *PhoneNumber_lineEdit;
    QLineEdit *Password_lineEdit;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *forgetpass)
    {
        if (forgetpass->objectName().isEmpty())
            forgetpass->setObjectName("forgetpass");
        forgetpass->resize(551, 552);
        centralwidget = new QWidget(forgetpass);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 0, 511, 521));
        label->setPixmap(QPixmap(QString::fromUtf8(":/image/Annotation 2024-07-08 141430.png")));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 50, 111, 21));
        QFont font;
        font.setFamilies({QString::fromUtf8("Georgia")});
        font.setPointSize(18);
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(254, 255, 203);"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 110, 161, 21));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(254, 255, 203);"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 170, 161, 21));
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("background-color: rgb(254, 255, 203);"));
        Username_lineEdit = new QLineEdit(centralwidget);
        Username_lineEdit->setObjectName("Username_lineEdit");
        Username_lineEdit->setGeometry(QRect(190, 50, 331, 31));
        Username_lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(144, 138, 137);"));
        PhoneNumber_lineEdit = new QLineEdit(centralwidget);
        PhoneNumber_lineEdit->setObjectName("PhoneNumber_lineEdit");
        PhoneNumber_lineEdit->setGeometry(QRect(190, 110, 331, 31));
        PhoneNumber_lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(144, 138, 137);"));
        Password_lineEdit = new QLineEdit(centralwidget);
        Password_lineEdit->setObjectName("Password_lineEdit");
        Password_lineEdit->setGeometry(QRect(190, 160, 331, 31));
        Password_lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(144, 138, 137);"));
        Password_lineEdit->setEchoMode(QLineEdit::Password);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(200, 370, 151, 51));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Georgia")});
        font1.setPointSize(26);
        pushButton->setFont(font1);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(112, 71, 52);\n"
"color: rgb(255, 255, 255);\n"
"alternate-background-color: rgb(132, 66, 0);\n"
"\n"
"background-color: rgb(144, 72, 0);"));
        forgetpass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(forgetpass);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 551, 22));
        forgetpass->setMenuBar(menubar);
        statusbar = new QStatusBar(forgetpass);
        statusbar->setObjectName("statusbar");
        forgetpass->setStatusBar(statusbar);

        retranslateUi(forgetpass);

        QMetaObject::connectSlotsByName(forgetpass);
    } // setupUi

    void retranslateUi(QMainWindow *forgetpass)
    {
        forgetpass->setWindowTitle(QCoreApplication::translate("forgetpass", "MainWindow", nullptr));
        label->setText(QString());
        label_3->setText(QCoreApplication::translate("forgetpass", "username", nullptr));
        label_4->setText(QCoreApplication::translate("forgetpass", "phone number", nullptr));
        label_6->setText(QCoreApplication::translate("forgetpass", "new password", nullptr));
        pushButton->setText(QCoreApplication::translate("forgetpass", "register", nullptr));
    } // retranslateUi

};

namespace Ui {
    class forgetpass: public Ui_forgetpass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORGETPASS_H
