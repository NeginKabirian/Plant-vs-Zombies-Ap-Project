/********************************************************************************
** Form generated from reading UI file 'serverzp.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERZP_H
#define UI_SERVERZP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_serverzp
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLabel *label_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *serverzp)
    {
        if (serverzp->objectName().isEmpty())
            serverzp->setObjectName(QString::fromUtf8("serverzp"));
        serverzp->resize(426, 297);
        centralwidget = new QWidget(serverzp);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(158, 70, 161, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 70, 49, 16));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 170, 49, 16));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 210, 49, 16));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(90, 160, 231, 91));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        serverzp->setCentralWidget(centralwidget);
        menubar = new QMenuBar(serverzp);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 426, 22));
        serverzp->setMenuBar(menubar);
        statusbar = new QStatusBar(serverzp);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        serverzp->setStatusBar(statusbar);

        retranslateUi(serverzp);

        QMetaObject::connectSlotsByName(serverzp);
    } // setupUi

    void retranslateUi(QMainWindow *serverzp)
    {
        serverzp->setWindowTitle(QCoreApplication::translate("serverzp", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("serverzp", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("serverzp", "    ip", nullptr));
        label_5->setText(QCoreApplication::translate("serverzp", "timer1", nullptr));
        label_6->setText(QCoreApplication::translate("serverzp", "timer2", nullptr));
        label_3->setText(QCoreApplication::translate("serverzp", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("serverzp", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class serverzp: public Ui_serverzp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERZP_H
