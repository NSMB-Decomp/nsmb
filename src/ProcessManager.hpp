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
extern ProcessList ConnectTask;
extern ProcessList DestroyTask;
extern ProcessList data_0208fb58[8];
void func_020438e8(ProcessList*, PriorityNode*);
void func_02043a54(ProcessList*, ProcessLink*);
u32 getIDIndex(ProcessLink*);
void func_02043920(ProcessList*, void*); // TODO: Confirm these paramaters, is it ProcessList or PTMF, and what is void*?
void func_020438b0(ProcessList*, ProcessNode*);
void func_02043acc(ProcessList*, ProcessLink*, ProcessLink*);
