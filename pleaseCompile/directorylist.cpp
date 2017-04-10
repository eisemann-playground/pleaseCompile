#include "directorylist.h"

#include <iostream>
#include <string>

#include <QDebug>
#include <QDir>
#include <QDirIterator>

DirectoryList::DirectoryList(const QString &pathToDirectory)
{
    queryAllDirectories(pathToDirectory);
}

void DirectoryList::queryAllDirectories(const QString& pathToDirectory){
    QDirIterator it(pathToDirectory + "/src", QDir::Dirs | QDir::NoDotAndDotDot | QDir::NoSymLinks, QDirIterator::Subdirectories);

    // add the current path and all subdirectories to the appropriate vectors for later usage //
    m_srcRootDir = it.path();

    while(it.hasNext()){

        QString currentDir = it.next();

        QString substr {currentDir};
        substr.replace(m_srcRootDir + "/", "");

        if(substr.startsWith("lib")){
            m_libraryDirs.push_back(currentDir); }
        else if(substr.startsWith("app")){
            m_aplicationDirs.push_back(currentDir); }
        else{
            std::cerr << "The project directory does not follow the pleaseCompile standards! Aborting compilation.";
            std::exit(1);
        }
    }
}

std::ostream& operator<< (std::ostream &out, const DirectoryList &d)
{
    out << "\nSource directory:\n" << d.m_srcRootDir.toStdString() << std::endl << std::endl;

    out << "Library directories:\n";
    for(auto it : d.m_libraryDirs){
        out << it.toStdString() << std::endl;
    }

    out << "\nApplication directories:\n";
    for(auto it : d.m_aplicationDirs){
        out << it.toStdString() << std::endl;
    }
    out << std::endl;    

    return out;
}

