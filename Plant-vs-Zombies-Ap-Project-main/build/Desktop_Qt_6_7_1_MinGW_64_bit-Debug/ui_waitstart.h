/********************************************************************************
** Form generated from reading UI file 'waitstart.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAITSTART_H
#define UI_WAITSTART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_waitstart
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *waitstart)
    {
        if (waitstart->objectName().isEmpty())
            waitstart->setObjectName("waitstart");
        waitstart->resize(1096, 1172);
        centralwidget = new QWidget(waitstart);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 1101, 1071));
        label->setPixmap(QPixmap(QString::fromUtf8(":/image/photo_2024-07-08_18-42-30.jpg")));
        waitstart->setCentralWidget(centralwidget);
        menubar = new QMenuBar(waitstart);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1096, 22));
        waitstart->setMenuBar(menubar);
        statusbar = new QStatusBar(waitstart);
        statusbar->setObjectName("statusbar");
        waitstart->setStatusBar(statusbar);

        retranslateUi(waitstart);

        QMetaObject::connectSlotsByName(waitstart);
    } // setupUi

    void retranslateUi(QMainWindow *waitstart)
    {
        waitstart->setWindowTitle(QCoreApplication::translate("waitstart", "MainWindow", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class waitstart: public Ui_waitstart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAITSTART_H
