#include <QString>
#include <QDebug>

#ifndef IO_H
#define IO_H

class IO
{
public:
    IO();
    static void output(QString *);
    static void input(QString *);
};

#endif // IO_H
