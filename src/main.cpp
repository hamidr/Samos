#include <QtCore/QCoreApplication>
#include <QString>
#include <QDebug>

#include "samos.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QString str(app.argv()[1]);
    if (str.isEmpty()) {
        qDebug() << "Where the hell is the INPUT?!";
        return 1;
    }

    Samos *sm = new Samos(&str);
    if ( ! (sm->getMem()) )
    {
        qDebug() << "What kind of input is this?!";
        qDebug() << str;
        return 1;
    }
    sm->run();
    delete sm;

    app.exit(0);
    return 0;
}
