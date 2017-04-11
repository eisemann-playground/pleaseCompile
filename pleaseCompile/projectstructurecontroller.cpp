#include "projectstructurecontroller.h"

#include <iostream>

ProjectStructureController::ProjectStructureController(const DirectoryList& d )
{    
    std::cout << "Checking project folder structure.\n";
    checkFolderTreeDepth( "/app/", d.aplicationDirs() );
    checkFolderTreeDepth( "/lib/", d.libraryDirs() );
}

void ProjectStructureController::checkFolderTreeDepth( const QString match, const std::vector<QString>& dirs ) const
{
    for(const QString& it : dirs){
        std::cout << it.toStdString() << std::endl;

        const int lastIdxOfSlash = it.lastIndexOf( match ) + 5;
        QString substr{it};
        substr.remove(0, lastIdxOfSlash);

        if(substr.contains("/")){
            QString errorMessage = "The project structure is not according to the structure requested by pleaseCompile. No subfolders are allowed within each library or application. \nCheck: " + it + "\n";
            throw errorMessage;
        }

        std::cout << substr.toStdString() << std::endl;
    }
}
