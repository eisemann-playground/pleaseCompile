#include <iostream>
#include <QApplication>

#include "directorylist.h"


int main(int argc, char *argv[])
{
    //QApplication app(argc, argv);
    //return app.exec();

    DirectoryList d("/Users/martineisemann/sciebo/code/C++/pleaseCompile/test");

    std::cout << d;

    return 0;
}
