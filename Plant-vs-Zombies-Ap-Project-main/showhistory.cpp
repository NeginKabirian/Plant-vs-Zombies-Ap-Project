#include "showhistory.h"
#include "ui_showhistory.h"

showhistory::showhistory(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::showhistory)
{
    ui->setupUi(this);
}

showhistory::~showhistory()
{
    delete ui;
}

void showhistory::displayGames(QJsonArray gamesArray)
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
