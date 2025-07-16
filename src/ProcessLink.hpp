#import "base_types.hpp"
class Base;

class SceneNode   {
public:
    SceneNode* parent;
    SceneNode* firstChild;
    SceneNode* prev;
    SceneNode* next;
    Base* object;
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