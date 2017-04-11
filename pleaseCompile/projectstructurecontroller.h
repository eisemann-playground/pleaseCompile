#ifndef PROJECTSTRUCTURECONTROLLER_H
#define PROJECTSTRUCTURECONTROLLER_H

#include "directorylist.h"

class ProjectStructureController
{
public:
    ProjectStructureController();
    static void controlProjectStructure(const DirectoryList& d);

private:
    static void checkFolderTreeDepth( const QString s, const std::vector<QString>& dirs );
};

#endif // PROJECTSTRUCTURECONTROLLER_H
