#include "serverzp.h"
#include "ui_serverzp.h"
// #include <cstime>
#include <cstdlib>
#define fj "F:/userssss.json"

serverzp::serverzp(QWidget *parent)
:  m_server(new QTcpServer())
{
    readfileadduser();
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

bool serverzp::uniqusername(QString u)
{
    //bool flag=true;
    foreach(const QString &user , username){
        if(user==u){
            return false;
        }
    }
    return true;
}

void serverzp::readfileadduser()
{
    QString jsonFilePath = fj;

            QFile file(jsonFilePath);
            QJsonObject jsonhelpy;
            jsonhelpy["name"]="";
            jsonhelpy["username"]="";
            jsonhelpy["phone"]="";
            jsonhelpy["address"]="";
            jsonhelpy["password"]="";
            QJsonDocument jsonDochelpy(jsonhelpy);
            if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                    qDebug() << "Cannot open file for start:" << file.errorString();
                    return;
                }
            file.write(jsonDochelpy.toJson());
            file.close();
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                    qDebug() << "Cannot open file for reading:" << file.errorString();
                    return;
                }

                QByteArray jsonData = file.readAll();
                file.close();

                QJsonParseError parseError;
                QJsonDocument doc = QJsonDocument::fromJson(jsonData, &parseError);

                if (parseError.error != QJsonParseError::NoError) {
                    qDebug() << "Failed to parse JSON:" << parseError.errorString();
                    return;
                }

                //if (!doc.isArray()) {
                   // qDebug() << "JSON file does not contain an array.";
                   // return;
               // }

                QJsonArray jsonArray = doc.array();
                qDebug() << "Number of entries in JSON file:" << jsonArray.size();

                for (int i = 0; i < jsonArray.size(); ++i) {
                    QJsonObject obj = jsonArray.at(i).toObject();
                    QString usern = obj["username"].toString();


                    qDebug() << "Entry" << i+1 << ":";
                    qDebug() << "  Username:" << usern;
                    username.push_back(usern);
                }
                for(int j=0;j<username.size();++j){
                    qDebug() << "  User:" << username[j];
                }
}

void serverzp::writefileaddgamer(QString usern, QString name, QString phone, QString address, QString password)
{
     qDebug()<<"write";

     QByteArray hash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
     QString hashedPassword = QString(hash.toHex());
     QString jsonFilePath = fj;
     QFile file(jsonFilePath);
     if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
           qDebug() << "Cannot open file for reading and writing:" << file.errorString();
           return;
      }

      QByteArray jsonData = file.readAll();
      QJsonDocument doc = QJsonDocument::fromJson(jsonData);

      if (doc.isNull()) {
           qDebug() << "Failed to create JSON document from file:" << file.errorString();
           return;
      }

         // Extract the JSON array
      QJsonArray jsonArray = doc.array();

         // Create a new person object
      QJsonObject newPerson;
      newPerson["username"] = usern;
      newPerson["name"] = name;
      newPerson["password"] = hashedPassword;
      newPerson["address"] = address;
      newPerson["phone"] = phone;


      jsonArray.append(newPerson);
      doc.setArray(jsonArray);
      file.resize(0); // Clear previous content
      file.write(doc.toJson());
      file.close();

}

int serverzp::matchUsernamePassword(QString user, QString passw)
{
    QByteArray hash = QCryptographicHash::hash(passw.toUtf8(), QCryptographicHash::Sha256);
    QString hashedPassword = QString(hash.toHex());
    QString jsonFilePath = fj;
    QFile file(jsonFilePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Cannot open file for reading:" << file.errorString();
            return 1;
        }

        QByteArray jsonData = file.readAll();
        file.close();

        QJsonParseError parseError;
        QJsonDocument doc = QJsonDocument::fromJson(jsonData, &parseError);

        if (parseError.error != QJsonParseError::NoError) {
            qDebug() << "Failed to parse JSON:" << parseError.errorString();
            return 1;
        }

        if (!doc.isArray()) {
            qDebug() << "JSON file does not contain an array.";
            return 1;
        }

        QJsonArray jsonArray = doc.array();
        qDebug() << "Number of entries in JSON file:" << jsonArray.size();

        for (int i = 0; i < jsonArray.size(); ++i) {
            QJsonObject obj = jsonArray.at(i).toObject();
            QString usernam = obj["username"].toString();
            if(usernam==user){
                QString password=obj["password"].toString();
                if(password==hashedPassword){
                    return 3;
                }else{
                    return 2;
                }
            }


        }
        return 1;
}

bool serverzp::writeNewPassword(QString username, QString phone, QString newpassword)
{
    QByteArray hash = QCryptographicHash::hash(newpassword.toUtf8(), QCryptographicHash::Sha256);
    QString hashedPassword = QString(hash.toHex());
    bool f=false;
    QString jsonFilePath = fj;
    QFile file(jsonFilePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file for reading .";
        return false ;
     }

     QByteArray jsonData = file.readAll();
     QJsonDocument doc(QJsonDocument::fromJson(jsonData));

     if (!doc.isArray())
     {
         qDebug() << "JSON file does not contain an array.";
         return false;
     }

     QJsonArray jsonArray = doc.array();

     for (int i = 0; i < jsonArray.size(); ++i)
     {
          QJsonObject person = jsonArray[i].toObject();
          QString currentUsername = person["username"].toString();
          QString currentPhone = person["phone"].toString();

          if (currentUsername == username && currentPhone == phone)
          {

             person["password"] = hashedPassword;
             jsonArray[i] = person;
             qDebug() << "Password updated for" << username << "with phone number" << phone;
             f=true;
             break;
           }
        }

        file.close();
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            qDebug() << "Failed to open file for writing.";
            return false ;
         }
        file.resize(0);
        QJsonDocument updatedDoc(jsonArray);
        file.write(updatedDoc.toJson());
        file.close();
        return f;
}

QString serverzp::getwifiip()
{

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

}

void serverzp::onReadyRead()
{
    QTcpSocket *senderSocket = qobject_cast<QTcpSocket*>(sender());
    if (!senderSocket) return;

    QByteArray data = senderSocket->readAll();
    QString message = QString::fromUtf8(data);
    QStringList parts = message.split(',');
    if(message=="gameStartOrNo"){
        if(number==2 && flagg==false){
            flagg=true;
            foreach(QTcpSocket *c,m_clients){
                if(c!=senderSocket){
                     QString me = QString("startgame,%1").arg(ZOrP);
                    c->write(me.toUtf8());
                }
            }
        }
    }
    else if(parts.size() == 6 && parts[0] == "signup"){
        qDebug()<<"signup";
      if(uniqusername(parts[1])){
          writefileaddgamer(parts[1],parts[2],parts[3],parts[4],parts[5]);
          QString s="signup";
          QString a=",";
          QString t="true";
          QString message = QString("signup,%1").arg(t);
          if (m_clients[0] == senderSocket){
              m_clients[0]->write(message.toUtf8());
              qDebug()<<"sendme";
          }else if(m_clients[1] == senderSocket){
              m_clients[1]->write(message.toUtf8());
          }
      }else{
          QString s="signup";
          QString a=",";
          QString f="false";
          QString message = QString("signup,%1").arg(f);
          if (m_clients[0] == senderSocket){
              m_clients[0]->write(message.toUtf8());
          }else if(m_clients[1] == senderSocket){
              m_clients[1]->write(message.toUtf8());
          }
      }
    }else if(parts.size() == 3 && parts[0] == "login"){
        QString usern=parts[1];
        QString passw=parts[2];
        if(matchUsernamePassword(usern,passw)==3){
            ++number;
            qDebug()<<"num"<<number;
            int r=-1;
            if(number==2){
                r=std::rand()%2;
                ZOrP=1-r;
                qDebug()<<"r"<<r;
            }
             QString message = QString("login,%1,%2,%3").arg("3").arg(number).arg(r);
             if (m_clients[0] == senderSocket){
                 m_clients[0]->write(message.toUtf8());

             }else if(m_clients[1] == senderSocket){
                 m_clients[1]->write(message.toUtf8());

             }
        }else if(matchUsernamePassword(usern,passw)==2){
            QString message = QString("login,%1").arg("2");
            if (m_clients[0] == senderSocket){
                m_clients[0]->write(message.toUtf8());
            }else if(m_clients[1] == senderSocket){
                m_clients[1]->write(message.toUtf8());
            }
        }else if(matchUsernamePassword(usern,passw)==1){
            QString message = QString("login,%1").arg("1");
            if (m_clients[0] == senderSocket){
                m_clients[0]->write(message.toUtf8());
            }else if(m_clients[1] == senderSocket){
                m_clients[1]->write(message.toUtf8());
            }
        }
    }else if(parts.size() == 4 && parts[0] == "forgetpassword"){
        if(writeNewPassword(parts[1],parts[2],parts[3])){
            QString message = QString("forgetpassword,%1").arg("true");
            if (m_clients[0] == senderSocket){
                m_clients[0]->write(message.toUtf8());
            }else if(m_clients[1] == senderSocket){
                m_clients[1]->write(message.toUtf8());
            }
        }else{
            QString message = QString("forgetpassword,%1").arg("false");
            if (m_clients[0] == senderSocket){
                m_clients[0]->write(message.toUtf8());
            }else if(m_clients[1] == senderSocket){
                m_clients[1]->write(message.toUtf8());
            }
        }

    }else{
        if (m_clients[0] != senderSocket){
            m_clients[0]->write(data);
        }else if(m_clients[1] != senderSocket){
            m_clients[1]->write(data);
        }
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

