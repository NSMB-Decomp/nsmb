#include "ProcessManager.hpp"
#include "Bases/Base.hpp"

// This file uses autoload_2, autload_3 & main sections.
ProcessList CreateTask = {{NULL,NULL},Base::processCreate};
SceneGraph ConnectTask = {(SceneNode*)NULL,Base::doOrderProc};
ProcessList ExecuteTask = {{NULL,NULL},Base::processUpdate};
ProcessList DrawTask = {{NULL,NULL},Base::procesRender};
ProcessList DestroyTask = {{NULL,NULL},Base::processDestroy};
