#ifndef SERVER_H
#define SERVER_H
#include "VectorClient.h"
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>
#include <QVector>
class Server : public QObject
{
    Q_OBJECT
public:
    Server(QObject *parent=nullptr);
    void start(quint16 port);


private slots:
    void onNewConnection();
    void onReadyRead();
    void onClientDisconnected();

private:
        QTcpServer *m_server;
        QVector<QTcpSocket*> m_clients;
};
#endif // SERVER_H
