#include "myexception.h"

MyException::MyException(QString str) : str(str) {}

const char* MyException::what() const noexcept
{
    const char *cstr = str.toUtf8().constData();
    return cstr;
}
