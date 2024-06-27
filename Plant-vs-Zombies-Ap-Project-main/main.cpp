#include "mainwindow.h"

#include <QApplication>
#include "plantzombie.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    plantzombie z;
    z.show();
    return a.exec();
}
