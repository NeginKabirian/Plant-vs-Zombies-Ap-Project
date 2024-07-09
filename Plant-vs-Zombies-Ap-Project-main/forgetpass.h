#ifndef FORGETPASS_H
#define FORGETPASS_H

#include <QMainWindow>
#include<myexception.h>
namespace Ui {
class forgetpass;
}

class forgetpass : public QMainWindow
{
    Q_OBJECT

public:
    explicit forgetpass(QWidget *parent = nullptr);
    ~forgetpass();
    void checkPasswordStrength(const QString& password);

private slots:
    void on_pushButton_clicked();
signals:
    void messageforgetpass(QString message);

private:
    Ui::forgetpass *ui;
};

#endif // FORGETPASS_H
