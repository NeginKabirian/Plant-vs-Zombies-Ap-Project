#ifndef SERVERZP_H
#define SERVERZP_H
#include "VectorClient.h"
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>
#include <QVector>
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

private slots:
    void onNewConnection();
    void onReadyRead();
    void onClientDisconnected();


private:
    Ui::serverzp *ui;
    QTcpServer *m_server;
    QVector<QTcpSocket*> m_clients;
    bool flagg = false;
};

#endif // SERVERZP_H
