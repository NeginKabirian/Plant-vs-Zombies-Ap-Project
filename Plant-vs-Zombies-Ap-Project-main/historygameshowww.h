#ifndef HISTORYGAMESHOWWW_H
#define HISTORYGAMESHOWWW_H

#include <QMainWindow>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
namespace Ui {
class historyGameshowww;
}

class historyGameshowww : public QMainWindow
{
    Q_OBJECT

public:
    explicit historyGameshowww(QWidget *parent = nullptr);
    ~historyGameshowww();
    void displayGames(QJsonArray gamesArray);

private:
    Ui::historyGameshowww *ui;
};

#endif // HISTORYGAMESHOWWW_H
