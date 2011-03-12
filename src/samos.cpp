#include "samos.h"

Samos::Samos(QString* addr)
{
    SamosFile = addr;
    ACC = new QString("0000000000");
    MBR = new QString[1000];
    id  = new ID(MBR, ACC);
}

bool Samos::getMem()
{
    QFile infile(*SamosFile);
    if (!infile.open(QFile::ReadOnly))
    {
        qDebug() << "The file can't be read!";
        return false;
    }
    char buf[1024]; // buffer for a
    int x = 0;
    int count=0;
    QString cmd;
    while((x = infile.readLine(buf, sizeof(buf))) != -1) {
        cmd = QString::QString(buf);
        MBR[count] = cmd.mid(0,10);
        count++;
    }
    infile.close();
    return true;
}

void Samos::run()
{
     if ( this->getMem() )
    {
         this->PC = 0;
         while( this->exec(&MBR[PC], &PC) )
             PC++;
     } else {
         qDebug("Samus can't run :( !");
     }
}

bool Samos::exec(QString *cmd, int *pc)
{
    //qDebug() << PC <<MBR[PC];
    id->setCode(cmd, pc) ;
    return id->run();
}

Samos::~Samos()
{
    qDebug() << "\nREADING MEMORIES:";

    for(int i=0; i<= 999;i++)
    {
        if ( ! MBR[i].isEmpty())
            qDebug() <<i<<":\t"<< MBR[i];
    }
    qDebug() <<"ACC"<<":\t"<< *ACC;
    delete[] MBR;
    delete id;
    delete ACC;
}
