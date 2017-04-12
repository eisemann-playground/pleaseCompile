#include "filelistcontroller.h"

#include <QDebug>
#include <QDirIterator>

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
    //QDirIterator it(dirList.srcRootDir(), QDir::NoDotAndDotDot | QDir::NoSymLinks, QDirIterator::Subdirectories);
    while (it.hasNext()){
        m_fileList.push_back( it.next() );
    }

    for(auto& file : m_fileList){
        std::cout << file.toStdString() << std::endl;
    }
    /*
    for(auto & dir : dirList.aplicationDirs()){
        queryFilesForCurrentFolder(dir);
    }
    for(auto & dir : dirList.libraryDirs()){
        queryFilesForCurrentFolder(dir);
    }
    */
}

QStringList FileListController::getDuplicateFiles() const
{
    QStringList result;

    // TODO

    return result;
}

const QStringList &FileListController::fileList()
{
    return m_fileList;
}
