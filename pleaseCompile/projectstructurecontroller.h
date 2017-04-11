#ifndef PROJECTSTRUCTURECONTROLLER_H
#define PROJECTSTRUCTURECONTROLLER_H

#include "directorylist.h"

class ProjectStructureController
{
public:
    ProjectStructureController( const DirectoryList& d );

private:
    void checkFolderTreeDepth( const QString s, const std::vector<QString>& dirs ) const;
};

#endif // PROJECTSTRUCTURECONTROLLER_H
