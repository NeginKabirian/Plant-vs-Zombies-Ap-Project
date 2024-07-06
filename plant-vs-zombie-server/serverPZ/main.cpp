
#include "serverzp.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    serverzp *server = new serverzp();
    server->start(12345);
    //MainWindow w;
    server->show();
    return a.exec();
}
