#include <iostream>
#include <QApplication>
#include <QDir>
#include <QString>

#include "directorylist.h"

/**
 * @brief main - Compiles the program. It is assumed that the program is called from the root node of the project
 * @return
 */
int main(int argc, char *argv[])
{
    //QApplication app(argc, argv);
    //return app.exec();  


    // query all directories of the project //
    // /Users/martineisemann/sciebo/code/C++/pleaseCompile/test //
    // QDir::currentPath() //
    DirectoryList d( "/Users/martineisemann/sciebo/code/C++/pleaseCompile/test" );

    std::cout << d;   

    return 0;
}
