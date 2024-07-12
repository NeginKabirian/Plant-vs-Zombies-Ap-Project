#include "historygameshowww.h"
#include "ui_historygameshowww.h"

historyGameshowww::historyGameshowww(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::historyGameshowww)
{
    ui->setupUi(this);
}

historyGameshowww::~historyGameshowww()
{
    delete ui;
}

void historyGameshowww::displayGames(QJsonArray gamesArray)
{
    ui->listWidget->clear();

                for (int i = 0; i < gamesArray.size(); ++i) {
                    QJsonObject gameObj = gamesArray.at(i).toObject();
                    QString game = gameObj.value("game").toString();
                    QString opponentusername = gameObj.value("opponent username").toString();
                    QString Role = gameObj.value("Role").toString();
                    QString Date = gameObj.value("Date").toString();
                    QString winer = gameObj.value("winer").toString();
                    QString gameInfo = QString("%1,%2,%3,%4,%5,%6,%7,%8,%9,%10").arg("  game:").arg(game).arg(" opponent username:").arg(opponentusername).arg(" Role:").arg(Role).arg(" Date:").arg(Date).arg("winner: ").arg(winer);
                    ui->listWidget->addItem(gameInfo);
                }
}
