#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include "plantzombie.h"

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(plantzombie *game, QObject *parent = nullptr);
    void connectToServer(const QString &address, quint16 port);

public slots:

    void sendAddPAMessage(int rect,int x, int y);
    void sendAddPBMessage(int rect,int x, int y);
    void sendAddPCMessage(int rect,int x, int y);
    void sendAddPDMessage(int rect,int x, int y);
    void sendAddPEMessage(int rect,int x, int y);
    void sendAddPFMessage(int rect,int x, int y);
    void sendAddZAMessage(int rect,int x, int y);
    void sendAddZBMessage(int rect,int x, int y);
    void sendAddZCMessage(int rect,int x, int y);
    void sendAddZDMessage(int rect,int x, int y);
    void sendAddZEMessage(int rect,int x, int y);
    void sendAddZFMessage(int rect,int x, int y);
private slots:
    void onReadyRead();

private:
    QTcpSocket *m_socket;
    plantzombie *m_game;
};

#endif // CLIENT_H
