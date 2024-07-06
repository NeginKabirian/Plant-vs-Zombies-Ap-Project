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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
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
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonZA;
    QPushButton *pushButtonZB;
    QPushButton *pushButtonZC;
    QPushButton *pushButtonZD;
    QPushButton *pushButtonZE;
    QPushButton *pushButtonZF;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonPA;
    QPushButton *pushButtonPB;
    QPushButton *pushButtonPC;
    QPushButton *pushButtonPD;
    QPushButton *pushButtonPE;
    QPushButton *pushButtonPF;
    QLabel *label;
    QLabel *label_2;
    QLabel *brainlabel;
    QLabel *Brainlabel;
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
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(681, 30, 601, 111));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButtonZA = new QPushButton(layoutWidget_2);
        pushButtonZA->setObjectName("pushButtonZA");
        sizePolicy.setHeightForWidth(pushButtonZA->sizePolicy().hasHeightForWidth());
        pushButtonZA->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/regular zombie.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonZA->setIcon(icon);
        pushButtonZA->setIconSize(QSize(65, 65));

        horizontalLayout_2->addWidget(pushButtonZA);

        pushButtonZB = new QPushButton(layoutWidget_2);
        pushButtonZB->setObjectName("pushButtonZB");
        sizePolicy.setHeightForWidth(pushButtonZB->sizePolicy().hasHeightForWidth());
        pushButtonZB->setSizePolicy(sizePolicy);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/Bucket head zombie.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonZB->setIcon(icon1);
        pushButtonZB->setIconSize(QSize(65, 65));

        horizontalLayout_2->addWidget(pushButtonZB);

        pushButtonZC = new QPushButton(layoutWidget_2);
        pushButtonZC->setObjectName("pushButtonZC");
        sizePolicy.setHeightForWidth(pushButtonZC->sizePolicy().hasHeightForWidth());
        pushButtonZC->setSizePolicy(sizePolicy);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/leaf hair zombie.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonZC->setIcon(icon2);
        pushButtonZC->setIconSize(QSize(65, 65));

        horizontalLayout_2->addWidget(pushButtonZC);

        pushButtonZD = new QPushButton(layoutWidget_2);
        pushButtonZD->setObjectName("pushButtonZD");
        sizePolicy.setHeightForWidth(pushButtonZD->sizePolicy().hasHeightForWidth());
        pushButtonZD->setSizePolicy(sizePolicy);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/tall zombie.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonZD->setIcon(icon3);
        pushButtonZD->setIconSize(QSize(65, 65));

        horizontalLayout_2->addWidget(pushButtonZD);

        pushButtonZE = new QPushButton(layoutWidget_2);
        pushButtonZE->setObjectName("pushButtonZE");
        sizePolicy.setHeightForWidth(pushButtonZE->sizePolicy().hasHeightForWidth());
        pushButtonZE->setSizePolicy(sizePolicy);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/image/astronaut zombie.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonZE->setIcon(icon4);
        pushButtonZE->setIconSize(QSize(65, 65));

        horizontalLayout_2->addWidget(pushButtonZE);

        pushButtonZF = new QPushButton(layoutWidget_2);
        pushButtonZF->setObjectName("pushButtonZF");
        sizePolicy.setHeightForWidth(pushButtonZF->sizePolicy().hasHeightForWidth());
        pushButtonZF->setSizePolicy(sizePolicy);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/image/purple hair zombie_transparent.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonZF->setIcon(icon5);
        pushButtonZF->setIconSize(QSize(65, 65));

        horizontalLayout_2->addWidget(pushButtonZF);

        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 30, 669, 111));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonPA = new QPushButton(layoutWidget);
        pushButtonPA->setObjectName("pushButtonPA");
        pushButtonPA->setEnabled(true);
        sizePolicy.setHeightForWidth(pushButtonPA->sizePolicy().hasHeightForWidth());
        pushButtonPA->setSizePolicy(sizePolicy);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/image/pea shooter.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonPA->setIcon(icon6);
        pushButtonPA->setIconSize(QSize(65, 65));
#if QT_CONFIG(shortcut)
        pushButtonPA->setShortcut(QString::fromUtf8("A"));
#endif // QT_CONFIG(shortcut)
        pushButtonPA->setAutoRepeatDelay(100);
        pushButtonPA->setAutoDefault(false);

        horizontalLayout->addWidget(pushButtonPA);

        pushButtonPB = new QPushButton(layoutWidget);
        pushButtonPB->setObjectName("pushButtonPB");
        sizePolicy.setHeightForWidth(pushButtonPB->sizePolicy().hasHeightForWidth());
        pushButtonPB->setSizePolicy(sizePolicy);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/image/two_peashooter.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonPB->setIcon(icon7);
        pushButtonPB->setIconSize(QSize(65, 65));

        horizontalLayout->addWidget(pushButtonPB);

        pushButtonPC = new QPushButton(layoutWidget);
        pushButtonPC->setObjectName("pushButtonPC");
        sizePolicy.setHeightForWidth(pushButtonPC->sizePolicy().hasHeightForWidth());
        pushButtonPC->setSizePolicy(sizePolicy);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/image/walnut.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonPC->setIcon(icon8);
        pushButtonPC->setIconSize(QSize(65, 65));

        horizontalLayout->addWidget(pushButtonPC);

        pushButtonPD = new QPushButton(layoutWidget);
        pushButtonPD->setObjectName("pushButtonPD");
        sizePolicy.setHeightForWidth(pushButtonPD->sizePolicy().hasHeightForWidth());
        pushButtonPD->setSizePolicy(sizePolicy);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/image/plum mine_transparent.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonPD->setIcon(icon9);
        pushButtonPD->setIconSize(QSize(65, 65));
        pushButtonPD->setAutoRepeatInterval(302);

        horizontalLayout->addWidget(pushButtonPD);

        pushButtonPE = new QPushButton(layoutWidget);
        pushButtonPE->setObjectName("pushButtonPE");
        sizePolicy.setHeightForWidth(pushButtonPE->sizePolicy().hasHeightForWidth());
        pushButtonPE->setSizePolicy(sizePolicy);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/image/jalapino.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonPE->setIcon(icon10);
        pushButtonPE->setIconSize(QSize(65, 65));

        horizontalLayout->addWidget(pushButtonPE);

        pushButtonPF = new QPushButton(layoutWidget);
        pushButtonPF->setObjectName("pushButtonPF");
        sizePolicy.setHeightForWidth(pushButtonPF->sizePolicy().hasHeightForWidth());
        pushButtonPF->setSizePolicy(sizePolicy);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/image/boomrang_transparent.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonPF->setIcon(icon11);
        pushButtonPF->setIconSize(QSize(65, 65));

        horizontalLayout->addWidget(pushButtonPF);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(1140, 170, 63, 41));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setPixmap(QPixmap(QString::fromUtf8(":/image/sun.png")));
        label->setScaledContents(true);
        label->setMargin(-4);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(1230, 180, 71, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI Black")});
        font.setPointSize(35);
        font.setBold(true);
        font.setItalic(true);
        label_2->setFont(font);
        label_2->setScaledContents(true);
        brainlabel = new QLabel(centralwidget);
        brainlabel->setObjectName("brainlabel");
        brainlabel->setEnabled(true);
        brainlabel->setGeometry(QRect(1140, 450, 63, 31));
        sizePolicy.setHeightForWidth(brainlabel->sizePolicy().hasHeightForWidth());
        brainlabel->setSizePolicy(sizePolicy);
        brainlabel->setPixmap(QPixmap(QString::fromUtf8(":/image/Brain.png")));
        brainlabel->setScaledContents(true);
        Brainlabel = new QLabel(centralwidget);
        Brainlabel->setObjectName("Brainlabel");
        Brainlabel->setEnabled(true);
        Brainlabel->setGeometry(QRect(1250, 450, 131, 41));
        sizePolicy.setHeightForWidth(Brainlabel->sizePolicy().hasHeightForWidth());
        Brainlabel->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(35);
        font1.setBold(true);
        font1.setItalic(true);
        Brainlabel->setFont(font1);
        Brainlabel->setToolTipDuration(14);
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
        pushButtonZA->setText(QString());
        pushButtonZB->setText(QString());
        pushButtonZC->setText(QString());
        pushButtonZD->setText(QString());
        pushButtonZE->setText(QString());
        pushButtonZF->setText(QString());
        pushButtonPA->setText(QString());
        pushButtonPB->setText(QString());
#if QT_CONFIG(shortcut)
        pushButtonPB->setShortcut(QCoreApplication::translate("plantzombie", "B", nullptr));
#endif // QT_CONFIG(shortcut)
        pushButtonPC->setText(QString());
#if QT_CONFIG(shortcut)
        pushButtonPC->setShortcut(QCoreApplication::translate("plantzombie", "D", nullptr));
#endif // QT_CONFIG(shortcut)
        pushButtonPD->setText(QString());
#if QT_CONFIG(shortcut)
        pushButtonPD->setShortcut(QCoreApplication::translate("plantzombie", "C", nullptr));
#endif // QT_CONFIG(shortcut)
        pushButtonPE->setText(QString());
#if QT_CONFIG(shortcut)
        pushButtonPE->setShortcut(QCoreApplication::translate("plantzombie", "Return", nullptr));
#endif // QT_CONFIG(shortcut)
        pushButtonPF->setText(QString());
        label->setText(QString());
        label_2->setText(QString());
        brainlabel->setText(QString());
        Brainlabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class plantzombie: public Ui_plantzombie {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLANTZOMBIE_H
