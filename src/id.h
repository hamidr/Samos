/*****
    Author:  Hamidreza Davoodi
    E-mail:  hrdavodi[at]gmail.com
    Written: in C++ under Qt framework
    License: GPLv3
*****/

#include <QString>
#include <QDebug>
#include "alu.h"
#include "io.h"
#include "bus.h"

#ifndef ID_H
#define ID_H

class ID
{
public:
    ID( QString *, QString *);
    bool setCode(QString *, int*);
    bool deCode();
    bool run();
    ~ID();

private:
    void jumpIfMinus(int );
    void jumpAnyway(int );
    int cmd;
    QString Opcode;
    QString Operand;
    QString *ACC;
    QString *MBR;
    bool state;
    int *PC;
    ALU *alu;
    Bus *bus;

};

#endif // ID_H
