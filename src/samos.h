#include <QString>
#include <QDebug>
#include <QFile>
#include "id.h"

#ifndef SAMOS_H
#define SAMOS_H

class Samos
{
public:
    Samos(QString*);
    void run();
    bool exec(QString *, int*);
    bool getMem(); // MBR
    bool debug(QString, int);
    ~Samos();


private:
    QString *SamosFile;
    QString *IR;
    QString *ACC;
    QString *MBR;
    ID *id;
    int PC;
};

#endif // SAMUS_H
