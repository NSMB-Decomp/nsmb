// This file includes all types that are used within the Ghidra project
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef signed char i8;
typedef signed short i16;
typedef signed long i32;

typedef u8 unknown1;
typedef u16 unknown2;
typedef u32 unknown4;
typedef void* unknown_pointer;
struct unknown_vtable {};

// Math
struct Vec3_32 {
    unknown_vtable *vtable;
    i32 x;
    i32 y;
    i32 z;
};
struct Vec3_16 {
    unknown_vtable *vtable;
    i16 x;
    i16 y;
    i16 z;
    i16 __padding;
};

// Process
struct ProcessNode {
    struct ProcessNode *prev;
    struct ProcessNode *next;
    struct Base *object;
};

struct PriorityNode {
    struct ProcessNode _;
    u16 currentPriority;
    u16 sortPriority;
};

struct SceneNode {
    struct SceneNode *parent;
    struct SceneNode *firstChild;
    struct SceneNode *prev;
    struct SceneNode *next;
    struct Base *object;
};

struct ProcessLink {
    struct SceneNode connect;
    struct PriorityNode update;
    struct PriorityNode render;
    struct ProcessNode idLookup;
};


// Class: Base
struct Base_vtable
{
    bool (*onCreate)(void);
    bool (*preCreate)(void);
    void (*postCreate)(u16, u16); // TODO: Confirm the paramater types
    bool (*onDestroy)();
    bool (*preDestroy)();
    void (*postDestroy)(u16, u16); // TODO: Confirm the paramater types
    bool (*onUpdate)();
    bool (*preUpdate)();
    void (*postUpdate)(); // TODO: Confirm the paramater types
    bool (*onRender)();
    bool (*preRender)();
    void (*postRender)(); // TODO: Confirm the paramater types
    void (*pendingDestroy)();
    void (*prepareResourcesSafe)();
    void (*prepareResourcesFast)();
    bool (*onPrepareResources)();
    void (*destroy1)();
    void (*destroy2)();
};
struct Base_data
{
    u32 guid;
    u32 settings;
    u16 objectId;
    u8 state;
    bool destroy;
    u8 unknown8_1;
    u8 unknown8_2;
    u8 unknown8_3;
    u8 unknown8_4;
    ProcessLink unknown;
    unknown_pointer unknownPointer;
    unknown_pointer heap;
};
struct Base
{
    Base_vtable *vtable;
    Base_data _;
};

// Class: Actor
struct Actor_vtable
{
    Base_vtable Base;
    void (*setPosX)();
    void (*incPosX)();
};
struct Actor_data
{
    Base_data Base;
    Vec3_32 pos;
    Vec3_32 lastPos;
};
struct Actor
{
    Actor_vtable *vtable;
    Actor_data _;
};

struct StageActor_vtable
{
    Actor_vtable Actor;
};

struct Player_vtable
{
    Actor_vtable Actor;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
};

struct Coin_vtable
{
    Actor_vtable Actor;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
};

struct StageEntity_vtable
{
    Actor_vtable Actor;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
    unknown_pointer unknown;
};