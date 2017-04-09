#include <iostream>
#include <QApplication>
#include <QDir>

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
    DirectoryList d( QDir::currentPath() );

    std::cout << d;

    return 0;
}
