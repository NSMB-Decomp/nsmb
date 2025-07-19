#include "base_types.hpp"

class Base;

class SceneNode   {
public:
    SceneNode* parent;
    SceneNode* firstChild;
    SceneNode* prev;
    SceneNode* next;
    Base* object;

    SceneNode* func_020439f0();
    SceneNode* func_02043a2c();
};

class ProcessNode {
public:
    ProcessNode * prev;
    ProcessNode * next;
    Base* object;
};

class PriorityNode {
public:
    ProcessNode _;
    u16 currentPriority;
    u16 sortPriority;
};

class ProcessLink {
public:
    SceneNode connect;
    PriorityNode update;
    PriorityNode render;
    ProcessNode idLookup;
};