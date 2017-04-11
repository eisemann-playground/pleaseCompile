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

    const std::vector<QString>& fileList();

private:

    std::vector<QString> m_fileList;
};

#endif // FILELIST_H
