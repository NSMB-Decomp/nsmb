#include "base_types.hpp"

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
};

class PriorityNode
{
public:
    ProcessNode _;
    u16 currentPriority;
    u16 sortPriority;
};

class ProcessLink
{
public:
    SceneNode connect;
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
extern u32 CurrentTask;
extern ProcessList CreateTask;
void func_020438e8(ProcessList*, PriorityNode*);