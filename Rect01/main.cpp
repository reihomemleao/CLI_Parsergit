#include "CLI_Parser.h"
#include "stdafx.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CLI_Parser w;
    w.show();
    return a.exec();
}
