#include <QtCore/QCoreApplication>
#include "samos.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QString input = "input.sm";
    Samos *sm = new Samos;
    sm->getFile(&input);
    sm->run();
    delete sm;
    getchar();
    app.exit(0);
    return 0;
}
