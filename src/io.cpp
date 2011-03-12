#include "io.h"
#include <iostream>

IO::IO()
{
}

void IO::input(QString *in)
{
    char s[10];
    std::cin >> s;
    QString temp(s);

    *in = temp.mid(0,10);
}

void IO::output(QString *out)
{
    int number = out->toInt();
    if ( number )
        qDebug() << number;
    else
        qDebug() << *out;
}
