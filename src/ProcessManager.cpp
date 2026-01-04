#include "ProcessManager.hpp"
#include "Bases/Base.hpp"

// This file uses autoload_2, autload_3 & main sections.
ProcessListN CreateTask = {{NULL,NULL},Base::processCreate};
SceneGraph ConnectTask = {(SceneNode*)NULL,Base::doOrderProc};
ProcessListN ExecuteTask = {{NULL,NULL},Base::processUpdate};
ProcessListN DrawTask = {{NULL,NULL},Base::procesRender};
ProcessListN DestroyTask = {{NULL,NULL},Base::processDestroy};
