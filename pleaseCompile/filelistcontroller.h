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

    /**
     * @brief collectDuplicateFileNames - Collects all filenames which appear more than once in the project
     * @param duplicateFileNames - Contains the duplicates afterwards
     */
    void collectDuplicateFileNames(QSet<QString> &duplicateFileNames) const;
    void collectPathsOfDuplicateFiles(const QSet<QString> &duplicateFileNames, QStringList &result) const;
};

#endif // FILELIST_H
