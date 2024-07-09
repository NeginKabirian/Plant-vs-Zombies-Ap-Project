#include "mainwindow2.h"
#include "Client.h"
#include <QApplication>
#include "plantzombie.h"
#include "signup.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow2 w;
    //plantzombie z;
    //z.show();

    //signup ss;
    w.show();
    return a.exec();
}
