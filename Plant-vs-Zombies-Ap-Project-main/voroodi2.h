#ifndef VOROODI2_H
#define VOROODI2_H

#include <QMainWindow>

namespace Ui {
class voroodi2;
}

class voroodi2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit voroodi2(QWidget *parent = nullptr);
    ~voroodi2();
signals:
    void startgame();
    void SHistory();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::voroodi2 *ui;
};

#endif // VOROODI2_H
