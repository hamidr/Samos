#include "bus.h"

Bus::Bus(QString* mem, QString* acc)
{
    MBR = mem;
    ACC = acc;
}

void Bus::load(int raw)
{
    *ACC = MBR[raw];
}

void Bus::store(int raw)
{
    MBR[raw] = *ACC ;
}
