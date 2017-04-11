#include "filelistcontroller.h"

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
//TODO
}

QStringList FileListController::getDuplicateFiles() const
{
    QStringList result;

    // TODO

    return result;
}

const std::vector<QString>& FileListController::fileList()
{
    // TODO
}
