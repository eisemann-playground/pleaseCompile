#include "directorylist.h"

#include <iostream>

#include <QDebug>
#include <QDir>
#include <QDirIterator>

DirectoryList::DirectoryList(const QString &pathToDirectory)
{
    // only lists the current directory not recursive //

    queryAllDirectories(pathToDirectory);
}

void DirectoryList::queryAllDirectories(const QString& pathToDirectory){
    QDirIterator it(pathToDirectory, QDir::Dirs | QDir::NoDotAndDotDot | QDir::NoSymLinks, QDirIterator::Subdirectories);

    // add the current path and all subdirectories //
    m_directories.push_back(it.path());
    while(it.hasNext()){
        m_directories.push_back(it.next());
    }
}


std::ostream& operator<< (std::ostream &out, const DirectoryList &d)
{
    for(auto it : d.m_directories){
        out << it.toStdString() << std::endl;
    }

    return out;
}

