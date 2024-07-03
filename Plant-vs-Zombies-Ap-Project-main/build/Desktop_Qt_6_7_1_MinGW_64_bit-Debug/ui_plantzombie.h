/********************************************************************************
** Form generated from reading UI file 'plantzombie.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLANTZOMBIE_H
#define UI_PLANTZOMBIE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_plantzombie
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonPA;
    QPushButton *pushButtonPB;
    QPushButton *pushButtonPC;
    QPushButton *pushButtonPD;
    QPushButton *pushButtonPE;
    QPushButton *pushButtonPF;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonZA;
    QPushButton *pushButtonZB;
    QPushButton *pushButtonZC;
    QPushButton *pushButtonZD;
    QPushButton *pushButtonZE;
    QPushButton *pushButtonZF;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *plantzombie)
    {
        if (plantzombie->objectName().isEmpty())
            plantzombie->setObjectName("plantzombie");
        plantzombie->resize(2000, 800);
        centralwidget = new QWidget(plantzombie);
        centralwidget->setObjectName("centralwidget");
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(0, 150, 1100, 530));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 110, 595, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonPA = new QPushButton(layoutWidget);
        pushButtonPA->setObjectName("pushButtonPA");
        pushButtonPA->setEnabled(true);
        pushButtonPA->setAutoDefault(false);

        horizontalLayout->addWidget(pushButtonPA);

        pushButtonPB = new QPushButton(layoutWidget);
        pushButtonPB->setObjectName("pushButtonPB");

        horizontalLayout->addWidget(pushButtonPB);

        pushButtonPC = new QPushButton(layoutWidget);
        pushButtonPC->setObjectName("pushButtonPC");

        horizontalLayout->addWidget(pushButtonPC);

        pushButtonPD = new QPushButton(layoutWidget);
        pushButtonPD->setObjectName("pushButtonPD");

        horizontalLayout->addWidget(pushButtonPD);

        pushButtonPE = new QPushButton(layoutWidget);
        pushButtonPE->setObjectName("pushButtonPE");

        horizontalLayout->addWidget(pushButtonPE);

        pushButtonPF = new QPushButton(layoutWidget);
        pushButtonPF->setObjectName("pushButtonPF");

        horizontalLayout->addWidget(pushButtonPF);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(630, 110, 595, 31));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButtonZA = new QPushButton(layoutWidget1);
        pushButtonZA->setObjectName("pushButtonZA");

        horizontalLayout_2->addWidget(pushButtonZA);

        pushButtonZB = new QPushButton(layoutWidget1);
        pushButtonZB->setObjectName("pushButtonZB");

        horizontalLayout_2->addWidget(pushButtonZB);

        pushButtonZC = new QPushButton(layoutWidget1);
        pushButtonZC->setObjectName("pushButtonZC");

        horizontalLayout_2->addWidget(pushButtonZC);

        pushButtonZD = new QPushButton(layoutWidget1);
        pushButtonZD->setObjectName("pushButtonZD");

        horizontalLayout_2->addWidget(pushButtonZD);

        pushButtonZE = new QPushButton(layoutWidget1);
        pushButtonZE->setObjectName("pushButtonZE");

        horizontalLayout_2->addWidget(pushButtonZE);

        pushButtonZF = new QPushButton(layoutWidget1);
        pushButtonZF->setObjectName("pushButtonZF");

        horizontalLayout_2->addWidget(pushButtonZF);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(250, 40, 93, 29));
        plantzombie->setCentralWidget(centralwidget);
        menubar = new QMenuBar(plantzombie);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 2000, 26));
        plantzombie->setMenuBar(menubar);
        statusbar = new QStatusBar(plantzombie);
        statusbar->setObjectName("statusbar");
        plantzombie->setStatusBar(statusbar);

        retranslateUi(plantzombie);

        QMetaObject::connectSlotsByName(plantzombie);
    } // setupUi

    void retranslateUi(QMainWindow *plantzombie)
    {
        plantzombie->setWindowTitle(QCoreApplication::translate("plantzombie", "MainWindow", nullptr));
        pushButtonPA->setText(QCoreApplication::translate("plantzombie", "PushButton", nullptr));
        pushButtonPB->setText(QCoreApplication::translate("plantzombie", "PushButton", nullptr));
        pushButtonPC->setText(QCoreApplication::translate("plantzombie", "PushButton", nullptr));
        pushButtonPD->setText(QCoreApplication::translate("plantzombie", "PushButton", nullptr));
        pushButtonPE->setText(QCoreApplication::translate("plantzombie", "PushButton", nullptr));
        pushButtonPF->setText(QCoreApplication::translate("plantzombie", "PushButton", nullptr));
        pushButtonZA->setText(QCoreApplication::translate("plantzombie", "PushButton", nullptr));
        pushButtonZB->setText(QCoreApplication::translate("plantzombie", "PushButton", nullptr));
        pushButtonZC->setText(QCoreApplication::translate("plantzombie", "PushButton", nullptr));
        pushButtonZD->setText(QCoreApplication::translate("plantzombie", "PushButton", nullptr));
        pushButtonZE->setText(QCoreApplication::translate("plantzombie", "PushButton", nullptr));
        pushButtonZF->setText(QCoreApplication::translate("plantzombie", "PushButton", nullptr));
        pushButton->setText(QCoreApplication::translate("plantzombie", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class plantzombie: public Ui_plantzombie {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLANTZOMBIE_H
