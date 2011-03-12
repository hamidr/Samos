/*****
    Author:  Hamidreza Davoodi
    E-mail:  hrdavodi[at]gmail.com
    Written: in C++ under Qt framework
    License: GPLv3
*****/

#include <QString>
#include <QDebug>


#ifndef BUS_H
#define BUS_H

class Bus
{
public:
    Bus(QString*, QString*);
    void load(int);
    void store(int);


private:
    QString* ACC;
    QString* MBR;

};

#endif // BUS_H
