#ifndef DIRECTORYLIST_H
#define DIRECTORYLIST_H

#include <iostream>
#include <vector>

#include <QString>

class DirectoryList
{
public:
    DirectoryList(const QString& pathToDirectory);  

    // getter-functions //
    QString srcRootDir() const;
    const std::vector<QString>& libraryDirs() const;
    const std::vector<QString>& aplicationDirs() const;

    friend std::ostream& operator<< (std::ostream &out, const DirectoryList &d);

private:
    QString m_srcRootDir;
    std::vector<QString> m_libraryDirs;
    std::vector<QString> m_aplicationDirs;

    void queryAllDirectories(const QString& pathToDirectory);
};


#endif // DIRECTORYLIST_H
