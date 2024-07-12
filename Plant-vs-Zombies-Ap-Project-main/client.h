#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include "plantzombie.h"
#include "signup.h"
#include "login.h"
#include "forgetpass.h"
#include "voroodi2.h"
#include "historygameshowww.h"
#include <QJsonArray>
class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(plantzombie *game, QObject *parent = nullptr);
    void connectToServer(const QString &address, quint16 port);
    void EndTime(QString message);
    void EndTime2(QString message);
    signup* Signup;
    login* Login;
    forgetpass *forget;
    voroodi2 *vorood;
    historyGameshowww *HGS;
    //int v;
    QString ZOrP;
    QString number;
    bool checkv=false;
    QTimer *Timercheckvorod;
    bool checknumber=false;
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

     void sendAddPAMessage2(int rect,int x, int y);
     void sendAddPBMessage2(int rect,int x, int y);
     void sendAddPCMessage2(int rect,int x, int y);
     void sendAddPDMessage2(int rect,int x, int y);
     void sendAddPEMessage2(int rect,int x, int y);
     void sendAddPFMessage2(int rect,int x, int y);
     void sendAddZAMessage2(int rect,int x, int y);
     void sendAddZBMessage2(int rect,int x, int y);
     void sendAddZCMessage2(int rect,int x, int y);
     void sendAddZDMessage2(int rect,int x, int y);
     void sendAddZEMessage2(int rect,int x, int y);
     void sendAddZFMessage2(int rect,int x, int y);

     void sendSignupMessage(QString message);
     void sendloginMessage(QString message);
     void sendforgetpassmessage(QString message);
     void showuiforget();
     void showuisignup();
     void EndMap(QString message);
     //void EndTime(QString message);
     void EndMap2(QString message);
     //void EndTime2(QString message);
     void startforgame();
     void checkstartvorood();
     void historyShow();
private slots:
    void onReadyRead();

private:
    QTcpSocket *m_socket;
    plantzombie *m_game;
    plantzombie *m_game2;
};

#endif // CLIENT_H
