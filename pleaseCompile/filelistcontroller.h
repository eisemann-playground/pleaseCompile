#ifndef FILELIST_H
#define FILELIST_H

#include <QStringList>

#include "directorylist.h"

/**
 * @brief The FileList class - Queries the names of all files in the project
 */
class FileListController
{
public:
    FileListController();

    void queryFileList( const DirectoryList& dirList );

    QStringList getDuplicateFiles() const;

    const QStringList& fileList();

private:

    /**
     * @brief m_fileList - After calling queryFileList this variable contains all files of your project
     */
    QStringList m_fileList;
};

#endif // FILELIST_H
