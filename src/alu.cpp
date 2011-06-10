#include "alu.h"

ALU::ALU(QString *acc)
{
    ACC = acc;
}

void ALU::calc( int cmd, int ARG )
{
	if ( ARG != 0 )
    switch (cmd)
    {
    case 0:
        *ACC = QString::number(this->doADD(ARG));
        break;
    case 1:
        *ACC = QString::number(this->doSUB(ARG));
        break;
    case 2:
        *ACC = QString::number(this->doMUL(ARG));
        break;
    case 3:
		if ( ARG != 0 )
			*ACC = QString::number(this->doDIV(ARG));
        break;
    }
}

inline int ALU::doADD(int arg)
{
    return ACC->toInt() + arg;
}

inline int ALU::doSUB(int arg)
{
    return ACC->toInt() - arg;
}

inline int ALU::doMUL(int arg)
{
    return ACC->toInt() * arg;
}

inline int ALU::doDIV(int arg)
{
    return ACC->toInt() / arg;
}
