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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_serverzp
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *serverzp)
    {
        if (serverzp->objectName().isEmpty())
            serverzp->setObjectName(QString::fromUtf8("serverzp"));
        serverzp->resize(800, 600);
        menubar = new QMenuBar(serverzp);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        serverzp->setMenuBar(menubar);
        centralwidget = new QWidget(serverzp);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        serverzp->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(serverzp);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        serverzp->setStatusBar(statusbar);

        retranslateUi(serverzp);

        QMetaObject::connectSlotsByName(serverzp);
    } // setupUi

    void retranslateUi(QMainWindow *serverzp)
    {
        serverzp->setWindowTitle(QCoreApplication::translate("serverzp", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class serverzp: public Ui_serverzp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERZP_H
