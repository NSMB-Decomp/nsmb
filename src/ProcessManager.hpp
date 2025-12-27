class Base;
class SceneNode
{
public:
    SceneNode *parent;
    SceneNode *firstChild;
    SceneNode *prev;
    SceneNode *next;
    Base *object;

    SceneNode *func_020439f0();
    SceneNode *func_02043a2c();
};

class ProcessNode
{
public:
    ProcessNode *prev;
    ProcessNode *next;
    Base *object;

    void unlink();
};

class PriorityNode
{
public:
    ProcessNode _;
    u16 currentPriority;
    u16 sortPriority;

    void unlink();
};

class ProcessLink
{
public:
    SceneNode connect; // 0x00
    PriorityNode update;
    PriorityNode render;
    ProcessNode idLookup;
};

class PTMF
{
public:
    void *a;
    u32 params;
};

class ProcessList
{
    PTMF executer;
};

enum ProcessType {
    Null,
    Connect,
    Create,
    Execute,
    Delete,
    Draw
};

namespace ProcessManager {
    // TODO: Switch these from extern
    extern u32 CurrentTask;
    extern ProcessList CreateTask;
    extern ProcessList ConnectTask;
    extern ProcessList ExecuteTask;
    extern ProcessList DrawTask;
    extern ProcessList DestroyTask;

    extern ProcessList idLookupProcesses[8];
    u32 getIDIndex(ProcessLink*);
    Base* getNextObjectByObjectID(u16 class_id, Base* prev);
}
