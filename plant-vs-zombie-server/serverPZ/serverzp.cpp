#include "serverzp.h"
#include "ui_serverzp.h"
//#include <cstime>
#include <cstdlib>

serverzp::serverzp(QWidget *parent)
:  m_server(new QTcpServer())
{
    connect(m_server, &QTcpServer::newConnection, this, &serverzp::onNewConnection);

}

void serverzp::start(quint16 port)
{
    if (m_server->listen(QHostAddress::Any, port)) {
        qDebug() << "Server started on port" << port;
    } else {
        qDebug() << "Server failed to start";
    }
}

void serverzp::onNewConnection()
{
    QTcpSocket *clientSocket = m_server->nextPendingConnection();
    connect(clientSocket, &QTcpSocket::readyRead, this, &serverzp::onReadyRead);
    connect(clientSocket, &QTcpSocket::disconnected, this, &serverzp::onClientDisconnected);
    try{
         m_clients.push_back(clientSocket);
    }catch(std::length_error& e){
        std::cerr<<"length Error:"<<e.what()<<"\n";
    }

    qDebug() << "New client connected";
    if(m_clients.size()==2 && flagg==false){
        flagg=true;
        srand(time(nullptr));
        int pzrand=rand()%2;
        if(pzrand==0){
            QString message="zombie";
            m_clients[0]->write(message.toUtf8());
            message="plant";
            m_clients[1]->write(message.toUtf8());
        }else{
            QString message="zombie";
            m_clients[1]->write(message.toUtf8());
            message="plant";
            m_clients[0]->write(message.toUtf8());
        }

    }
}

void serverzp::onReadyRead()
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

void serverzp::onClientDisconnected()
{
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket*>(sender());
    if (clientSocket) {
        m_clients.removeOne(clientSocket);
        clientSocket->deleteLater();
        qDebug() << "Client disconnected";
    }
}

