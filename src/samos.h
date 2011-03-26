/*****
    Author:  Hamidreza Davoodi
    E-mail:  hrdavodi[at]gmail.com
    Written: in C++ under Qt framework
    License: GPLv3
*****/

#include <QString>
#include <QStringList>
#include <QTextStream>
#include <QFile>
#include "id.h"

#ifndef SAMOS_H
#define SAMOS_H

class Samos
{
public:
    Samos();
    void run();
    bool exec(QString *, int*);
    void getFile(QString *); // MBR
    ~Samos();


private:
    QString     *SamosFile;
    QString     *ACC;
    QString     *MBR;
    QTextStream *qerr;
    ID *id;
    int PC;
    bool isRunnable;
};

#endif // SAMUS_H
