#include <QtCore/QCoreApplication>
#include "samos.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QString input(app.argv()[1]);
    if (input.isEmpty() || argc < 2)
    {
        QTextStream out(stdout);
        out << "This program is free software; you can redistribute it and/or modify\nit under the terms of the GNU General Public License as published by\nthe Free Software Foundation; either version 3 of the License , or\n(at your option) any later version.\n"
            << "\t* * * * * * * *\n"
            << "All you need is an editor like notepad on windows or vim on unixes.\n"
            << "Note: Just plain text and each command as in OPC000oprd.\n"
            << "Usage: Samos.exe <INPUT.SM>\nLike this: c:\\Samos.exe input.sm\n"
            << "---\nSources are available in http://github.com/hamidr/Samos\nCopyrighted by Hamidreza Davoodi <hrdavodi@gmail.com>.\n";
        app.exit(1);
        return 1;
    }

    Samos sm;
    sm.getFile(&input);
    sm.run();
    app.exit(0);
    return 0;
}
