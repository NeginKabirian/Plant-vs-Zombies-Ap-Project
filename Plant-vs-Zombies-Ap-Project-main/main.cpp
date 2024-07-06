#include "mainwindow.h"
#include "Client.h"
#include <QApplication>
#include "plantzombie.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //plantzombie z;
    //z.show();
    plantzombie *game = new plantzombie();
    Client *client = new Client(game);
    client->connectToServer("127.0.0.1", 12345);
    return a.exec();
}
