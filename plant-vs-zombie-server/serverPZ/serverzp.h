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
#include <QDateTime>
#include <QTimer>
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
    QString getwifiip();
    QString username1="";
    QString username2="";
    void addGameToJson(const QString &username, const QJsonObject &newGame);
    QJsonArray readJsonFromFile(const QString &fileName);
    QByteArray sendGameHistory(QString username);
    void updateTimer();
    void updateTimer2();
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
    QTimer *Timergame1;
    QTimer *Timergame2;
};

#endif // SERVERZP_H
