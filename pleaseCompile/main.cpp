#include <iostream>
#include <exception>
#include <string>

#include <QApplication>
#include <QDir>
#include <QString>

#include "directorylist.h"

/**
 * @brief main - Compiles the program. It is assumed that the program is called from the root node of the project
 * @return 0 if all went well
 */
int main(int argc, char *argv[])
{
    if(argc <= 1){
        std::cerr << "You need to provide a project root directory." << std::endl;
        std::exit(-1);
    }

    try{
        DirectoryList d( argv[1] );
        std::cout << d;
    }
    catch(const std::exception& e){
        std::cerr << "Standard exception: " << e.what();
        std::exit(-1);
    }
    catch(const char* message){
        std::cerr << message;
        std::exit(-1);
    }
    catch(const std::string message){
        std::cerr << message;
        std::exit(-1);
    }
    catch(...)
    {
        std::cerr << "An unhandled exception was thrown.";
        std::exit(-1);
    }

    return 0;
}
