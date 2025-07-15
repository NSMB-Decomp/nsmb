#include "Base.hpp"

class SceneNode   {
    SceneNode* parent;
    SceneNode* firstChild;
    SceneNode* prev;
    SceneNode* next;
    Base* object;
};

class ProcessNode {
    ProcessNode * prev;
    ProcessNode * next;
    Base* object;
};

class PriorityNode {
    ProcessNode _;
    u16 currentPriority;
    u16 sortPriority;
};

class ProcessLink {
    SceneNode connect;
    PriorityNode update;
    PriorityNode render;
    ProcessNode idLookup;
};