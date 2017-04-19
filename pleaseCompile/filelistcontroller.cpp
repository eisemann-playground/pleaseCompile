#include "filelistcontroller.h"

#include <QDebug>
#include <QDirIterator>
#include <QSet>

#include <set>

/**
 * @brief FileList::FileList - Empty constructor
 */
FileListController::FileListController()
{

}



/**
 * @brief FileList::queryFileList - Collects all files from the directory list
 * @param dirList
 */
void FileListController::queryFileList( const DirectoryList& dirList )
{
    QDirIterator it(dirList.srcRootDir(), QDir::Files | QDir::NoDotAndDotDot | QDir::NoSymLinks, QDirIterator::Subdirectories);    
    while (it.hasNext()){
        m_fileList.push_back( it.next() );
    }
/*
    for(auto& file : m_fileList){
        std::cout << file.toStdString() << std::endl;
    }
*/
}

void FileListController::collectDuplicateFileNames(QSet<QString>& duplicateFileNames) const
{
    QSet<QString> uniqueFileNames;

    for(const QString& it : m_fileList){

        const int lastIdxOfSlash = it.lastIndexOf( "/" ) + 1;
        QString substr{it};
        substr.remove(0, lastIdxOfSlash);

        const int sizeBefore = uniqueFileNames.size();
        uniqueFileNames.insert(substr);
        const int sizeAfter = uniqueFileNames.size();
        if(sizeBefore == sizeAfter){
            duplicateFileNames.insert(substr);
        }
    }
}

void FileListController::collectPathsOfDuplicateFiles(const QSet<QString>& duplicateFileNames, QStringList& result) const
{
    for(const QString& it : m_fileList){
        for(const QString& it2 : duplicateFileNames){
            if(it.endsWith(it2)){
                result.push_back(it);
            }
        }
    }
}

QStringList FileListController::getDuplicateFiles() const
{
    QStringList result;
    QSet<QString> duplicateFileNames;

    collectDuplicateFileNames(duplicateFileNames);
    collectPathsOfDuplicateFiles(duplicateFileNames, result);

    return result;
}

const QStringList &FileListController::fileList()
{
    return m_fileList;
}
