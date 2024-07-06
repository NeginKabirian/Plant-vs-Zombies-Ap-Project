#include "server.h"

Server::Server(QObject *parent)
 : QObject(parent), m_server(new QTcpServer(this))
{
  connect(m_server, &QTcpServer::newConnection, this, &Server::onNewConnection);
}
void Server::start(quint16 port)
{
    if (m_server->listen(QHostAddress::Any, port)) {
        qDebug() << "Server started on port" << port;
    } else {
        qDebug() << "Server failed to start";
    }
}

void Server::onNewConnection()
{
    QTcpSocket *clientSocket = m_server->nextPendingConnection();
    connect(clientSocket, &QTcpSocket::readyRead, this, &Server::onReadyRead);
    connect(clientSocket, &QTcpSocket::disconnected, this, &Server::onClientDisconnected);
    try{
         m_clients.push_back(clientSocket);
    }catch(std::length_error& e){
        std::cerr<<"length Error:"<<e.what()<<"\n";
    }

    qDebug() << "New client connected";
}

void Server::onReadyRead()
{
    QTcpSocket *senderSocket = qobject_cast<QTcpSocket*>(sender());
    if (!senderSocket) return;

    QByteArray data = senderSocket->readAll();
    if (m_clients[0] != senderSocket){
        m_clients[0]->write(data);
    }else if(m_clients[1] != senderSocket){
        m_clients[1]->write(data);
    }
}

void Server::onClientDisconnected()
{
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket*>(sender());
    if (clientSocket) {
        m_clients.removeOne(clientSocket);
        clientSocket->deleteLater();
        qDebug() << "Client disconnected";
    }
}
