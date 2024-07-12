#include "client.h"
#include <QPointF>
#include <QMessageBox>
#include <QTime>
Client::Client(plantzombie *game, QObject *parent)
    : QObject(parent), m_socket(new QTcpSocket(this)), m_game(game)
{
    Signup=new signup();
    Login=new login();
    forget= new forgetpass();
    m_game2=new plantzombie();
    vorood=new voroodi2();
    HGS=new historyGameshowww();
    Timercheckvorod = new QTimer(this);
    connect(Timercheckvorod, SIGNAL(timeout()), this,SLOT(checkstartvorood()));

    connect(Signup,&signup::sendmessage,this,&Client::sendSignupMessage);
    connect(Login,&login::sendmessagelogin,this,&Client::sendloginMessage);
    connect(forget,&forgetpass::messageforgetpass,this,&Client::sendforgetpassmessage);
    connect(Login,&login::uiforgetpass,this,&Client::showuiforget);
    connect(Login,&login::uisignup,this,&Client::showuisignup);
    connect(m_socket, &QTcpSocket::readyRead, this, &Client::onReadyRead);
    connect(vorood,&voroodi2::startgame,this,&Client::startforgame);
    connect(vorood,&voroodi2::SHistory,this,&Client::historyShow);
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
    connect(m_game, &plantzombie::checkedMapEnd,this,&Client::EndMap);
    //connect(m_game, &plantzombie::checkTimeEnd,this,&Client::EndTime);
    connect(m_game2, &plantzombie::SInsertPA, this, &Client::sendAddPAMessage2);
    connect(m_game2, &plantzombie::SInsertPB, this, &Client::sendAddPBMessage2);
    connect(m_game2, &plantzombie::SInsertPC, this, &Client::sendAddPCMessage2);
    connect(m_game2, &plantzombie::SInsertPD, this, &Client::sendAddPDMessage2);
    connect(m_game2, &plantzombie::SInsertPE, this, &Client::sendAddPEMessage2);
    connect(m_game2, &plantzombie::SInsertPF, this, &Client::sendAddPFMessage2);
    connect(m_game2, &plantzombie::SInsertZA, this, &Client::sendAddZAMessage2);
    connect(m_game2, &plantzombie::SInsertZB, this, &Client::sendAddZBMessage2);
    connect(m_game2, &plantzombie::SInsertZC, this, &Client::sendAddZCMessage2);
    connect(m_game2, &plantzombie::SInsertZD, this, &Client::sendAddZDMessage2);
    connect(m_game2, &plantzombie::SInsertZE, this, &Client::sendAddZEMessage2);
    connect(m_game2, &plantzombie::SInsertZF, this, &Client::sendAddZFMessage2);
    connect(m_game2,&plantzombie::checkedMapEnd,this,&Client::EndMap2);
    //  connect(m_game2,&plantzombie::checkTimeEnd,this,&Client::EndTime2);
    //Signup->show();
    // m_game->show();
    //waitt->show();
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


void Client::sendAddPAMessage2(int rect, int x, int y)
{
    QString message = QString("addPA,%1,%2,%3,%4").arg(rect).arg(x).arg(y).arg("2");
    m_socket->write(message.toUtf8());
}

void Client::sendAddPBMessage2(int rect, int x, int y)
{
    QString message = QString("addPB,%1,%2,%3,%4").arg(rect).arg(x).arg(y).arg("2");
    m_socket->write(message.toUtf8());
}

void Client::sendAddPCMessage2(int rect, int x, int y)
{
    QString message = QString("addPC,%1,%2,%3,%4").arg(rect).arg(x).arg(y).arg("2");
    m_socket->write(message.toUtf8());
}

void Client::sendAddPDMessage2(int rect, int x, int y)
{
    QString message = QString("addPD,%1,%2,%3,%4").arg(rect).arg(x).arg(y).arg("2");
    m_socket->write(message.toUtf8());
}

void Client::sendAddPEMessage2(int rect, int x, int y)
{
    QString message = QString("addPE,%1,%2,%3,%4").arg(rect).arg(x).arg(y).arg("2");
    m_socket->write(message.toUtf8());
}

void Client::sendAddPFMessage2(int rect, int x, int y)
{
    QString message = QString("addPF,%1,%2,%3,%4").arg(rect).arg(x).arg(y).arg("2");
    m_socket->write(message.toUtf8());
}

void Client::sendAddZAMessage2(int rect, int x, int y)
{
    QString message = QString("addZA,%1,%2,%3,%4").arg(rect).arg(x).arg(y).arg("2");
    m_socket->write(message.toUtf8());
}

void Client::sendAddZBMessage2(int rect, int x, int y)
{
    QString message = QString("addZB,%1,%2,%3,%4").arg(rect).arg(x).arg(y).arg("2");
    m_socket->write(message.toUtf8());
}

void Client::sendAddZCMessage2(int rect, int x, int y)
{
    QString message = QString("addZC,%1,%2,%3,%4").arg(rect).arg(x).arg(y).arg("2");
    m_socket->write(message.toUtf8());
}

void Client::sendAddZDMessage2(int rect, int x, int y)
{
    QString message = QString("addZD,%1,%2,%3,%4").arg(rect).arg(x).arg(y).arg("2");
    m_socket->write(message.toUtf8());
}

void Client::sendAddZEMessage2(int rect, int x, int y)
{
    QString message = QString("addZE,%1,%2,%3,%4").arg(rect).arg(x).arg(y).arg("2");
    m_socket->write(message.toUtf8());
}

void Client::sendAddZFMessage2(int rect, int x, int y)
{
    QString message = QString("addZF,%1,%2,%3,%4").arg(rect).arg(x).arg(y).arg("2");
    m_socket->write(message.toUtf8());
}


void Client::sendSignupMessage(QString message)
{
    m_socket->write(message.toUtf8());
    qDebug()<<"b";
}

void Client::sendloginMessage(QString message)
{
    m_socket->write(message.toUtf8());
}

void Client::sendforgetpassmessage(QString message)
{
    m_socket->write(message.toUtf8());
}

void Client::showuiforget()
{
    forget->show();
}

void Client::showuisignup()
{
    Login->close();
    Signup->show();
}

void Client::EndMap(QString message)
{
    qDebug()<<"wwwwww34567890";
    QString m;
    QString Role;
    QString WOrL;
    if(m_game->Zombie==true){

        Role="zombie";

        m = QString("END,%1,%2,%3,%4").arg(Role).arg(Login->usernamee).arg(message).arg("1");
        m_game->close();
        delete m_game;
        m_game2->show();
        m_game2->plant=true;
        m_game2->visibleButton();
        m_game2->time->start();
    }else if(m_game->plant==true){

        Role="plant";

        m = QString("END,%1,%2,%3,%4").arg(Role).arg(Login->usernamee).arg(message).arg("1");
        m_game->close();
        delete m_game;
        m_game2->show();
        m_game2->Zombie=true;
        m_game2->visibleButton();
        m_game2->time->start();
    }
    m_socket->write(m.toUtf8());
    qDebug()<<"wwwwww";

}

void Client::EndTime(QString message)
{
    QString m;
    QString Role;
    QString WOrL;
    if(m_game->Zombie==true){

        Role="zombie";

        m = QString("END,%1,%2,%3,%4").arg(Role).arg(Login->usernamee).arg(message).arg("1");
        m_game->close();
        delete m_game;
        m_game2->show();
        m_game2->plant=true;
        m_game2->visibleButton();
        m_game2->time->start();

    }else if(m_game->plant==true){

        Role="plant";

        m = QString("END,%1,%2,%3,%4").arg(Role).arg(Login->usernamee).arg(message).arg("1");
        m_game->close();
        delete m_game;
        m_game2->show();
        m_game2->Zombie=true;
        m_game2->visibleButton();
        m_game2->time->start();
    }
    m_socket->write(m.toUtf8());

}

void Client::EndMap2(QString message)
{
    QString m;
    QString Role;
    QString WOrL;
    if(m_game->Zombie==true){

        Role="zombie";

        m = QString("END,%1,%2,%3,%4").arg(Role).arg(Login->usernamee).arg(message).arg("2");

    }else if(m_game->plant==true){

        Role="plant";

        m = QString("END,%1,%2,%3,%4").arg(Role).arg(Login->usernamee).arg(message).arg("2");
    }
     m_socket->write(m.toUtf8());
     qDebug()<<"wwwwww";
     m_game2->close();
     delete m_game2;
}

void Client::EndTime2(QString message)
{
    QString m;
    QString Role;
    QString WOrL;
    if(m_game->Zombie==true){

        Role="zombie";

        m = QString("END,%1,%2,%3,%4").arg(Role).arg(Login->usernamee).arg(message).arg("2");

    }else if(m_game->plant==true){

        Role="plant";

        m = QString("END,%1,%2,%3").arg(Role).arg(Login->usernamee).arg(message).arg("2");
    }
    m_socket->write(m.toUtf8());
    m_game2->close();
    delete m_game2;
}

void Client::startforgame()
{
    QString m="clickstart";
    m_socket->write(m.toUtf8());
    /*if(number=="2" && checknumber){
        QString m = QString("gameStartOrNo");
        m_socket->write(m.toUtf8());
        Login->close();
        m_game->show();
        m_game->time->start();
        if(ZOrP=="1"){
            m_game->Zombie=true;
            m_game->visibleButton();
        }else if(ZOrP=="0"){
            m_game->plant=true;
            m_game->visibleButton();
        }
        QString s="startgaming";
        m_socket->write(s.toUtf8());
    }else if(number=="1"){
        QMessageBox::information(nullptr,"ERROR","game start when secend user login.");
        Timercheckvorod->start(500);
    }*/
    QMessageBox::information(nullptr,"ERROR","game start when secend user login.");
    Timercheckvorod->start(500);
}

void Client::checkstartvorood()
{

    if(checknumber){
        Timercheckvorod->stop();
        //forget->show();
        QString m = "startgaming";
       m_socket->write(m.toUtf8());
        Login->close();
        m_game->show();
        m_game->time->start();
        if(ZOrP=="1"){
            m_game->Zombie=true;
            m_game->visibleButton();
        }
        if(ZOrP=="0"){
            m_game->plant=true;
            m_game->visibleButton();
        }
        QString s="startgaming";
        m_socket->write(s.toUtf8());
    }
   //else if(number=="1"){
        //QMessageBox::information(nullptr,"ERROR","game start when secend user login.");

   // }
}
void Client::historyShow()
{
  QString m = QString("history,%1").arg(Login->usernamee);
  m_socket->write(m.toUtf8());
}



void Client::onReadyRead()
{
    QByteArray data = m_socket->readAll();
    QString message = QString::fromUtf8(data);
    QByteArray JData=data;
    QJsonDocument doc=QJsonDocument::fromJson(JData);
    if(message=="clickstart"){
           checknumber=true;
           //HGS->show();
       }
    if(message=="1" ||message=="0"){
           ZOrP=message;
           //HGS->show();
       }
    if(doc.isArray()){
        qDebug()<<"oooooo";
        QJsonArray gamesArray=doc.array();
        //forget->show();
        HGS->show();
        HGS->displayGames(gamesArray);
        //ShowHistory->displayGames(gamesArray);

    }else if(message=="zombie"){
        //waitt->close();
       //Login->close();
       //m_game->show();
       m_game->Zombie=true;
       m_game->visibleButton();


    }else if(message=="plant"){
        //waitt->close();
       //Login->close();
        //m_game->show();
       m_game->plant=true;
       m_game->visibleButton();

    }else if(message=="endtimer1"){
        QString WL;
      if(m_game->plant==true){
          WL="w";
      }else if(m_game->Zombie==true){
          WL="l";
      }
      EndTime(WL);
    } else if(message=="endtimer2"){
        QString WL;
      if(m_game2->plant==true){
          WL="w";
      }else if(m_game2->Zombie==true){
          WL="l";
      }
      EndTime2(WL) ;
    }else{
    QStringList parts = message.split(',');
    if(parts.size()==2&&parts[0]=="startgame"){
        Login->close();
        m_game->show();
        if(parts[1]=="1"){
            m_game->Zombie=true;
            m_game->visibleButton();
        }else if(parts[1]=="0"){
            m_game->plant=true;
            m_game->visibleButton();
        }
    }else if (parts.size() == 4 && parts[0] == "addPA") {
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
    }else if (parts.size() == 5 && parts[0] == "addPA") {
                bool ok1, ok2,ok3;
                int rect = parts[1].toInt(&ok1);
                int x = parts[2].toInt(&ok2);
                int y = parts[3].toInt(&ok3);
                if (ok1 && ok2&& ok3) {
                   QPointF p;
                   p.setX(x);p.setY(y);
                   m_game2->insertfieldPA(rect,p);
                }
     }else if(parts.size() == 5 && parts[0] == "addPB"){
                bool ok1, ok2,ok3;
                int rect = parts[1].toInt(&ok1);
                int x = parts[2].toInt(&ok2);
                int y = parts[3].toInt(&ok3);
                if (ok1 && ok2&& ok3) {
                   QPointF p;
                   p.setX(x);p.setY(y);
                   m_game2->insertfieldPB(rect,p);
                }
    }else if(parts.size() == 5 && parts[0] == "addPC"){
                bool ok1, ok2,ok3;
                int rect = parts[1].toInt(&ok1);
                int x = parts[2].toInt(&ok2);
                int y = parts[3].toInt(&ok3);
                if (ok1 && ok2&& ok3) {
                   QPointF p;
                   p.setX(x);p.setY(y);
                   m_game2->insertfieldPC(rect,p);
                }
    }else if(parts.size() == 5 && parts[0] == "addPD"){
                bool ok1, ok2,ok3;
                int rect = parts[1].toInt(&ok1);
                int x = parts[2].toInt(&ok2);
                int y = parts[3].toInt(&ok3);
                if (ok1 && ok2&& ok3) {
                   QPointF p;
                   p.setX(x);p.setY(y);
                   m_game2->insertfieldPD(rect,p);
                }
     }else if(parts.size() == 5 && parts[0] == "addPE"){
                bool ok1, ok2,ok3;
                int rect = parts[1].toInt(&ok1);
                int x = parts[2].toInt(&ok2);
                int y = parts[3].toInt(&ok3);
                if (ok1 && ok2&& ok3) {
                   QPointF p;
                   p.setX(x);p.setY(y);
                   m_game2->insertfieldPE(rect,p);
                }
     }else if(parts.size() == 5 && parts[0] == "addPF"){
                bool ok1, ok2,ok3;
                int rect = parts[1].toInt(&ok1);
                int x = parts[2].toInt(&ok2);
                int y = parts[3].toInt(&ok3);
                if (ok1 && ok2&& ok3) {
                   QPointF p;
                   p.setX(x);p.setY(y);
                   m_game2->insertfieldPF(rect,p);
                }
     }else if(parts.size() == 5 && parts[0] == "addZA"){
                bool ok1, ok2,ok3;
                int rect = parts[1].toInt(&ok1);
                int x = parts[2].toInt(&ok2);
                int y = parts[3].toInt(&ok3);
                if (ok1 && ok2&& ok3) {
                   QPointF p;
                   p.setX(x);p.setY(y);
                   m_game2->insertfieldZA(rect,p);
                }
    }else if(parts.size() == 5 && parts[0] == "addZB"){
                bool ok1, ok2,ok3;
                int rect = parts[1].toInt(&ok1);
                int x = parts[2].toInt(&ok2);
                int y = parts[3].toInt(&ok3);
                if (ok1 && ok2&& ok3) {
                   QPointF p;
                   p.setX(x);p.setY(y);
                   m_game2->insertfieldZB(rect,p);
                }
    }else if(parts.size() == 5 && parts[0] == "addZC"){
                bool ok1, ok2,ok3;
                int rect = parts[1].toInt(&ok1);
                int x = parts[2].toInt(&ok2);
                int y = parts[3].toInt(&ok3);
                if (ok1 && ok2&& ok3) {
                   QPointF p;
                   p.setX(x);p.setY(y);
                   m_game2->insertfieldZC(rect,p);
                }
     }else if(parts.size() == 5 && parts[0] == "addZD"){
                bool ok1, ok2,ok3;
                int rect = parts[1].toInt(&ok1);
                int x = parts[2].toInt(&ok2);
                int y = parts[3].toInt(&ok3);
                if (ok1 && ok2&& ok3) {
                   QPointF p;
                   p.setX(x);p.setY(y);
                   m_game2->insertfieldZD(rect,p);
                }
     }else if(parts.size() == 5 && parts[0] == "addZE"){
                bool ok1, ok2,ok3;
                int rect = parts[1].toInt(&ok1);
                int x = parts[2].toInt(&ok2);
                int y = parts[3].toInt(&ok3);
                if (ok1 && ok2&& ok3) {
                   QPointF p;
                   p.setX(x);p.setY(y);
                   m_game2->insertfieldZE(rect,p);
                }
     }else if(parts.size() == 5 && parts[0] == "addZF"){
                bool ok1, ok2,ok3;
                int rect = parts[1].toInt(&ok1);
                int x = parts[2].toInt(&ok2);
                int y = parts[3].toInt(&ok3);
                if (ok1 && ok2&& ok3) {
                   QPointF p;
                   p.setX(x);p.setY(y);
                   p.setX(x);p.setY(y);
                   m_game2->insertfieldZF(rect,p);
                }
    }else if(parts.size()==2 && parts[0]=="signup"){
        qDebug()<<"recive salahiat";
        if(parts[1]=="true"){

            //QMessageBox::critical(nullptr,"ERROR","OK");

            Signup->close();
            Login->show();
        }else{

            QMessageBox::critical(nullptr,"ERROR","this username is already taken.");
        }
    }else if(parts.size()==2 && parts[0]=="login"){
        if(parts[1]=="2"){

            QMessageBox::critical(nullptr,"ERROR","password is incorrect.");
        }else if(parts[1]=="1"){
            QMessageBox::critical(nullptr,"ERROR","username not found.");
        }
    }else if(parts.size()==4 && parts[0]=="login"){
        if(parts[2]=="2"){
            //QString m = QString("gameStartOrNo");
            //m_socket->write(m.toUtf8());
           // Login->close();
            //m_game->show();
            //m_game->time->start();
            number="2";
            if(parts[3]=="1"){
                //m_game->Zombie=true;
                //m_game->visibleButton();
                ZOrP="1";
                QString numZorP="0";
                m_socket->write(numZorP.toUtf8());
            } if(parts[3]=="0"){
                //m_game->plant=true;
                //m_game->visibleButton();
                ZOrP="0";
                QString numZorP="1";
                m_socket->write(numZorP.toUtf8());
            }

        }else if(parts[2]=="1"){
            //QMessageBox::information(nullptr,"ERROR","game start when secend user login.");
            number="1";
        }
        Login->close();
        vorood->show();
    }else if(parts.size()==2 && parts[0]=="forgetpassword"){
        if(parts[1]=="true"){

            //QMessageBox::critical(nullptr,"ERROR","OK");
            forget->close();

        }else{

            QMessageBox::critical(nullptr,"ERROR","user with this username and password was not found.");
        }
    }
   }
}
