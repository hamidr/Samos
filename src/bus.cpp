#include "bus.h"

Bus::Bus(QString* mem, QString* acc)
{
    MBR = mem;
    ACC = acc;
}

void Bus::load(int raw)
{
    *ACC = MBR[raw];
    //qDebug() <<"LDA:"<< *ACC <<MBR[raw] << raw;
}

void Bus::store(int raw)
{
    MBR[raw] = *ACC ;
    //qDebug() <<"STO:"<< *ACC <<MBR[raw] << raw;
}
