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

QString DirectoryList::srcRootDir() const
{
    return m_srcRootDir;
}

const std::vector<QString>& DirectoryList::libraryDirs() const
{
    return m_libraryDirs;
}

const std::vector<QString>& DirectoryList::aplicationDirs() const
{
    return m_aplicationDirs;
}


void DirectoryList::queryAllDirectories(const QString& pathToDirectory){
    QDirIterator it(pathToDirectory + "/src", QDir::Dirs | QDir::NoDotAndDotDot | QDir::NoSymLinks, QDirIterator::Subdirectories);

    // add the current path and all subdirectories to the appropriate vectors for later usage //
    m_srcRootDir = it.path();

    while(it.hasNext()){

        QString currentDir = it.next();

        QString substr {currentDir};
        substr.replace(m_srcRootDir + "/", "");

        if(substr == "app" || substr == "lib"){ continue; }
        else if(substr.startsWith("lib")){
            m_libraryDirs.push_back(currentDir); }
        else if(substr.startsWith("app")){
            m_aplicationDirs.push_back(currentDir); }
        else{
            QString errorMessage = "The project directory does not follow the pleaseCompile standards! Aborting compilation.\nPlease check: "
                    + currentDir;
            throw errorMessage;
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

