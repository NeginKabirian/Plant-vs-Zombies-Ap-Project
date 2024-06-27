#include "mainwindow.h"

#include <QApplication>
#include "zombieplanet.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    zombieplanet z;
    z.show();
    return a.exec();
}
