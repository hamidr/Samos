#include "io.h"
IO::IO()
{
}

void IO::input(QString *in)
{
    QTextStream qin(stdin);

    QString input;
    qin >> input;
    *in = "000000" + input.mid(input.size() - 4, 4);
}

void IO::output(QString *out)
{
    QTextStream qout(stdout);
    int number = out->toInt();
    if ( number )
        qout << number;
    else {
        QString temp = out->mid(6,4);
        if ( temp == "000N" )
            qout << '\n';
        else if ( temp == "000S" )
            qout << " ";
        else
            qout << temp;
    }
}
