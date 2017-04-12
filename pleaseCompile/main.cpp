#include <iostream>
#include <exception>
#include <string>

#include <QApplication>
#include <QDebug>
#include <QDir>
#include <QString>

#include "directorylist.h"
#include "filelistcontroller.h"
#include "projectstructurecontroller.h"

void startCompilation(int argc, char *argv[]){
    std::cout << "Oh, please compile!\n";

    const QString projectFolder( argv[1] );

    // query all directories of the project containing source code //
    DirectoryList listOfDirectories( projectFolder );

    // check if the project folders are correctly arranged and no file duplicates exits //
    std::cout << "Checking project folders and files.\n";

    ProjectStructureController::controlProjectStructure( listOfDirectories );

    FileListController fileList;
    fileList.queryFileList( listOfDirectories );

    QStringList duplicates = fileList.getDuplicateFiles();
    if( duplicates.size() != 0 ){
        QString errorMessage = "Your project contains duplicate files, please rename:\n";
        for(auto& it : duplicates){
            errorMessage += (it + "\n");
        }
        throw fileList.getDuplicateFiles();
    }    
}

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
        startCompilation(argc, argv);
        std::cout << "Yay, compilation finished successfully!\n";
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
    catch(const QString message){
        std::cerr << message.toStdString();
        std::exit(-1);
    }
    catch(...)
    {
        std::cerr << "An unhandled exception was thrown.";
        std::exit(-1);
    }

    return 0;
}
