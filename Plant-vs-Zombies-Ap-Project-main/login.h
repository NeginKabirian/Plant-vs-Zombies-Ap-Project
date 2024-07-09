#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>

namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

signals:
    void sendmessagelogin(QString m);
    void uiforgetpass();
    void uisignup();
private:
    Ui::login *ui;
};

#endif // LOGIN_H
