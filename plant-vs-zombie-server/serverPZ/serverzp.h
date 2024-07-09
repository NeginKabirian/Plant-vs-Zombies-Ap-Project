#ifndef SERVERZP_H
#define SERVERZP_H
#include "VectorClient.h"
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>
#include <QVector>
#include <QCoreApplication>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>
#include<QCryptographicHash>
#include <QMainWindow>

namespace Ui {
class serverzp;
}

class serverzp : public QMainWindow
{
    Q_OBJECT

public:
    explicit serverzp(QWidget *parent = nullptr);
    void start(quint16 port);
    bool uniqusername(QString);
    void readfileadduser();
    void writefileaddgamer(QString name,QString username,QString phone,QString address,QString password );
    int matchUsernamePassword(QString user,QString passw);
    bool writeNewPassword(QString username,QString phone,QString newpassword);
private slots:
    void onNewConnection();
    void onReadyRead();
    void onClientDisconnected();


private:
    Ui::serverzp *ui;
    QTcpServer *m_server;
    QVector<QTcpSocket*> m_clients;
    bool flagg = false;
    QVector<QString> username;
    int number=0;
    int ZOrP;
};

#endif // SERVERZP_H
