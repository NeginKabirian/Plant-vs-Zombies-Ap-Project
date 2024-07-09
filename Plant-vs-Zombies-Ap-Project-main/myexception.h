//#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include "signup.h"
#include "login.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include <QMainWindow>
#include <QException>

class MyException : public QObject, public QException
{
    Q_OBJECT
public:
    MyException(QString = " ");
    const char* what() const noexcept override;
private:
    QString str;
};

#endif // MYEXCEPTION_H
