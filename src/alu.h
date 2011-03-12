#ifndef ALU_H
#define ALU_H

#include <QString>
#include <QDebug>

class ALU
{
public:
    ALU(QString *);
    void calc(int, int);

private:
    inline int doADD(int);
    inline int doSUB(int);
    inline int doMUL(int);
    inline int doDIV(int);
    QString *ACC;
};

#endif // ALU_H