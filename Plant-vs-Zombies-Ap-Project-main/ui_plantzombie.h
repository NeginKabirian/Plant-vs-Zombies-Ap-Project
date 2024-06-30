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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_plantzombie
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
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
        plantzombie->setCentralWidget(centralwidget);
        menubar = new QMenuBar(plantzombie);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 2000, 22));
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
    } // retranslateUi

};

namespace Ui {
    class plantzombie: public Ui_plantzombie {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLANTZOMBIE_H
