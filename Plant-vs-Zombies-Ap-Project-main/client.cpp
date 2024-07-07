#include "client.h"
#include <QPointF>
Client::Client(plantzombie *game, QObject *parent)
    : QObject(parent), m_socket(new QTcpSocket(this)), m_game(game)
{
    connect(m_socket, &QTcpSocket::readyRead, this, &Client::onReadyRead);
    connect(m_game, &plantzombie::SInsertPA, this, &Client::sendAddPAMessage);
    connect(m_game, &plantzombie::SInsertPB, this, &Client::sendAddPBMessage);
    connect(m_game, &plantzombie::SInsertPC, this, &Client::sendAddPCMessage);
    connect(m_game, &plantzombie::SInsertPD, this, &Client::sendAddPDMessage);
    connect(m_game, &plantzombie::SInsertPE, this, &Client::sendAddPEMessage);
    connect(m_game, &plantzombie::SInsertPF, this, &Client::sendAddPFMessage);
    connect(m_game, &plantzombie::SInsertZA, this, &Client::sendAddZAMessage);
    connect(m_game, &plantzombie::SInsertZB, this, &Client::sendAddZBMessage);
    connect(m_game, &plantzombie::SInsertZC, this, &Client::sendAddZCMessage);
    connect(m_game, &plantzombie::SInsertZD, this, &Client::sendAddZDMessage);
    connect(m_game, &plantzombie::SInsertZE, this, &Client::sendAddZEMessage);
    connect(m_game, &plantzombie::SInsertZF, this, &Client::sendAddZFMessage);
    m_game->show();
}

void Client::connectToServer(const QString &address, quint16 port)
{
    m_socket->connectToHost(address, port);
}



void Client::sendAddPAMessage(int rect, int x, int y)
{
    QString message = QString("addPA,%1,%2,%3").arg(rect).arg(x).arg(y);
    m_socket->write(message.toUtf8());
}

void Client::sendAddPBMessage(int rect, int x, int y)
{
    QString message = QString("addPB,%1,%2,%3").arg(rect).arg(x).arg(y);
    m_socket->write(message.toUtf8());
}

void Client::sendAddPCMessage(int rect, int x, int y)
{
    QString message = QString("addPC,%1,%2,%3").arg(rect).arg(x).arg(y);
    m_socket->write(message.toUtf8());
}

void Client::sendAddPDMessage(int rect, int x, int y)
{
    QString message = QString("addPD,%1,%2,%3").arg(rect).arg(x).arg(y);
    m_socket->write(message.toUtf8());
}

void Client::sendAddPEMessage(int rect, int x, int y)
{
    QString message = QString("addPE,%1,%2,%3").arg(rect).arg(x).arg(y);
    m_socket->write(message.toUtf8());
}

void Client::sendAddPFMessage(int rect, int x, int y)
{
    QString message = QString("addPF,%1,%2,%3").arg(rect).arg(x).arg(y);
    m_socket->write(message.toUtf8());
}

void Client::sendAddZAMessage(int rect, int x, int y)
{
    QString message = QString("addZA,%1,%2,%3").arg(rect).arg(x).arg(y);
    m_socket->write(message.toUtf8());
}

void Client::sendAddZBMessage(int rect, int x, int y)
{
    QString message = QString("addZB,%1,%2,%3").arg(rect).arg(x).arg(y);
    m_socket->write(message.toUtf8());
}

void Client::sendAddZCMessage(int rect, int x, int y)
{
    QString message = QString("addZC,%1,%2,%3").arg(rect).arg(x).arg(y);
    m_socket->write(message.toUtf8());
}

void Client::sendAddZDMessage(int rect, int x, int y)
{
    QString message = QString("addZD,%1,%2,%3").arg(rect).arg(x).arg(y);
    m_socket->write(message.toUtf8());
}

void Client::sendAddZEMessage(int rect, int x, int y)
{
    QString message = QString("addZE,%1,%2,%3").arg(rect).arg(x).arg(y);
    m_socket->write(message.toUtf8());
}

void Client::sendAddZFMessage(int rect, int x, int y)
{
    QString message = QString("addZF,%1,%2,%3").arg(rect).arg(x).arg(y);
    m_socket->write(message.toUtf8());
}

void Client::onReadyRead()
{
    QByteArray data = m_socket->readAll();
    QString message = QString::fromUtf8(data);
    if(message=="zombie"){
       m_game->Zombie=true;
       m_game->visibleButton();
    }else if(message=="plant"){
       m_game->plant=true;
       m_game->visibleButton();
    }else{
    QStringList parts = message.split(',');
    if (parts.size() == 4 && parts[0] == "addPA") {
        bool ok1, ok2,ok3;
        int rect = parts[1].toInt(&ok1);
        int x = parts[2].toInt(&ok2);
        int y = parts[3].toInt(&ok3);
        if (ok1 && ok2&& ok3) {
           QPointF p;
           p.setX(x);p.setY(y);
           m_game->insertfieldPA(rect,p);
        }
    }else if(parts.size() == 4 && parts[0] == "addPB"){
        bool ok1, ok2,ok3;
        int rect = parts[1].toInt(&ok1);
        int x = parts[2].toInt(&ok2);
        int y = parts[3].toInt(&ok3);
        if (ok1 && ok2&& ok3) {
           QPointF p;
           p.setX(x);p.setY(y);
           m_game->insertfieldPB(rect,p);
        }
    }else if(parts.size() == 4 && parts[0] == "addPC"){
        bool ok1, ok2,ok3;
        int rect = parts[1].toInt(&ok1);
        int x = parts[2].toInt(&ok2);
        int y = parts[3].toInt(&ok3);
        if (ok1 && ok2&& ok3) {
           QPointF p;
           p.setX(x);p.setY(y);
           m_game->insertfieldPC(rect,p);
        }
    }else if(parts.size() == 4 && parts[0] == "addPD"){
        bool ok1, ok2,ok3;
        int rect = parts[1].toInt(&ok1);
        int x = parts[2].toInt(&ok2);
        int y = parts[3].toInt(&ok3);
        if (ok1 && ok2&& ok3) {
           QPointF p;
           p.setX(x);p.setY(y);
           m_game->insertfieldPD(rect,p);
        }
    }else if(parts.size() == 4 && parts[0] == "addPE"){
        bool ok1, ok2,ok3;
        int rect = parts[1].toInt(&ok1);
        int x = parts[2].toInt(&ok2);
        int y = parts[3].toInt(&ok3);
        if (ok1 && ok2&& ok3) {
           QPointF p;
           p.setX(x);p.setY(y);
           m_game->insertfieldPE(rect,p);
        }
    }else if(parts.size() == 4 && parts[0] == "addPF"){
        bool ok1, ok2,ok3;
        int rect = parts[1].toInt(&ok1);
        int x = parts[2].toInt(&ok2);
        int y = parts[3].toInt(&ok3);
        if (ok1 && ok2&& ok3) {
           QPointF p;
           p.setX(x);p.setY(y);
           m_game->insertfieldPF(rect,p);
        }
    }else if(parts.size() == 4 && parts[0] == "addZA"){
        bool ok1, ok2,ok3;
        int rect = parts[1].toInt(&ok1);
        int x = parts[2].toInt(&ok2);
        int y = parts[3].toInt(&ok3);
        if (ok1 && ok2&& ok3) {
           QPointF p;
           p.setX(x);p.setY(y);
           m_game->insertfieldZA(rect,p);
        }
    }else if(parts.size() == 4 && parts[0] == "addZB"){
        bool ok1, ok2,ok3;
        int rect = parts[1].toInt(&ok1);
        int x = parts[2].toInt(&ok2);
        int y = parts[3].toInt(&ok3);
        if (ok1 && ok2&& ok3) {
           QPointF p;
           p.setX(x);p.setY(y);
           m_game->insertfieldZB(rect,p);
        }
    }else if(parts.size() == 4 && parts[0] == "addZC"){
        bool ok1, ok2,ok3;
        int rect = parts[1].toInt(&ok1);
        int x = parts[2].toInt(&ok2);
        int y = parts[3].toInt(&ok3);
        if (ok1 && ok2&& ok3) {
           QPointF p;
           p.setX(x);p.setY(y);
           m_game->insertfieldZC(rect,p);
        }
    }else if(parts.size() == 4 && parts[0] == "addZD"){
        bool ok1, ok2,ok3;
        int rect = parts[1].toInt(&ok1);
        int x = parts[2].toInt(&ok2);
        int y = parts[3].toInt(&ok3);
        if (ok1 && ok2&& ok3) {
           QPointF p;
           p.setX(x);p.setY(y);
           m_game->insertfieldZD(rect,p);
        }
    }else if(parts.size() == 4 && parts[0] == "addZE"){
        bool ok1, ok2,ok3;
        int rect = parts[1].toInt(&ok1);
        int x = parts[2].toInt(&ok2);
        int y = parts[3].toInt(&ok3);
        if (ok1 && ok2&& ok3) {
           QPointF p;
           p.setX(x);p.setY(y);
           m_game->insertfieldZE(rect,p);
        }
    }else if(parts.size() == 4 && parts[0] == "addZF"){
        bool ok1, ok2,ok3;
        int rect = parts[1].toInt(&ok1);
        int x = parts[2].toInt(&ok2);
        int y = parts[3].toInt(&ok3);
        if (ok1 && ok2&& ok3) {
           QPointF p;
           p.setX(x);p.setY(y);
           m_game->insertfieldZF(rect,p);
        }
    }
   }
}
