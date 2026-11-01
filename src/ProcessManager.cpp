#include "ProcessManager.hpp"
#include "Bases/Base.hpp"

// This file uses autoload_2, autload_3 & main sections.
namespace ProcessManager
{
SceneGraph ConnectTask(&Base::doOrderProc);
ProcessList CreateTask(&Base::processCreate);
ProcessList ExecuteTask(&Base::processUpdate);
ProcessList DrawTask(&Base::procesRender);
ProcessList DestroyTask(&Base::processDestroy);
UnkListEntry idLookupProcesses[8];
} // namespace ProcessManager
