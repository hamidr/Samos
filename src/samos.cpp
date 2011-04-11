#include "samos.h"

Samos::Samos()
{
    ACC = new QString("0000000000");
    MBR = new QString[10000];
    id  = new ID(MBR, ACC);
    this->isRunnable = false;
    qerr = new QTextStream(stderr);
}

void Samos::getFile(QString* addr)
{
    SamosFile = addr;
    QFile infile(*SamosFile);
    if (!(this->isRunnable = infile.open(QIODevice::ReadOnly)))
        return;

    int count = 0;
    char endl = '\n'; // :D
    QString cmd;
    QTextStream file(&infile);
    while(!(cmd = file.readLine(0)).isEmpty())
    {
        if ( cmd.mid(3,3) != "000" || cmd.size() < 10 )
        {
            *qerr << "Oops! Error:\n" << "Line " <<count <<": " <<cmd << endl;
            *qerr << "Format should be like this: CMD000OPRD" << endl;
            this->isRunnable = false;
            infile.close();
            return;
        }
        MBR[count] = cmd.mid(0,10);
        count++;
    }
    infile.close();
    this->isRunnable = true;
}

void Samos::run()
{
    if ( this->isRunnable )
    {
         this->PC = 0;
         while( this->exec(&MBR[PC], &PC) )
             PC++;
     } else {
         *qerr << "File is not runnable!" << '\n';
     }
}

bool Samos::exec(QString *cmd, int *pc)
{
    id->setCode(cmd, pc) ;
    return id->run();
}

Samos::~Samos()
{
    if ( this->isRunnable )
    {
        *qerr << "\n\n*The END*\nREADING MEMORIES:\n";
        for(int i=0; i<= 9999;i++)
        {
            if (! MBR[i].isEmpty())
                *qerr <<i<<":\t"<< MBR[i] <<'\n';
        }
        *qerr <<"ACC"<<":\t"<< *ACC <<'\n';
    }

    delete[] MBR;
    delete qerr;
    delete id;
    delete ACC;
}
