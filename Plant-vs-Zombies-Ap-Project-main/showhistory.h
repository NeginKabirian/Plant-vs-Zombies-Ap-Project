#ifndef SHOWHISTORY_H
#define SHOWHISTORY_H

#include <QMainWindow>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonObject>
namespace Ui {
class showhistory;
}

class showhistory : public QMainWindow
{
    Q_OBJECT

public:
    explicit showhistory(QWidget *parent = nullptr);
    ~showhistory();
    void displayGames(QJsonArray gamesArray);

private:
    Ui::showhistory *ui;
};

#endif // SHOWHISTORY_H
