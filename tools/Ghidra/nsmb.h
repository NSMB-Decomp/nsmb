// This file includes all types that are used within the Ghidra project
// Todo: Shalst we seperate this into different header files?
#include "macros.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef signed char i8;
typedef signed short i16;
typedef signed long i32;

// Placeholders
typedef u8 unknown1;
typedef u16 unknown2;
typedef u32 unknown4;
typedef void *unknown_pointer;
struct unknown_vtable
{
};

// Math
struct Vec3_16
{
    unknown_vtable *vtable;
    i16 x;
    i16 y;
    i16 z;
    u8 _pad0[2];
};
struct Vec3_32
{
    unknown_vtable *vtable;
    i32 x;
    i32 y;
    i32 z;
};
struct Vec2_32
{
    unknown_vtable *vtable;
    i32 x;
    i32 y;
};

// Process
// TODO: Can we improve these names at all?
struct ProcessNode
{
    ProcessNode *prev;
    ProcessNode *next;
    struct Base *object;
};

struct PriorityNode
{
    ProcessNode _;
    u16 currentPriority;
    u16 sortPriority;
};

struct SceneNode
{
    SceneNode *parent;
    SceneNode *firstChild;
    SceneNode *prev;
    SceneNode *next;
    struct Base *object;
};

struct ProcessLink
{
    SceneNode connect;
    PriorityNode update;
    PriorityNode render;
    ProcessNode idLookup;
};

struct PTMF
{ // What is a PTMF?
    void (*func)(void *, ...);
    u32 params;
};

struct SceneGraph
{
    SceneNode *root;
    PTMF executor;
};

struct LinkedList
{
    ProcessNode *first;
    ProcessNode *last;
};

struct ProcessManager
{
    SceneGraph sceneGraph;
    ProcessLink updateProcess;
    ProcessLink deleteProcess;
    ProcessLink renderProcess;
    ProcessLink createProcess;
    LinkedList idLookupProcesses[8];
};

struct ProcessList
{
    LinkedList _;
    PTMF executor;
};

// TODO: Does this need to be renamed?
// TODO: Does this have a optioanal 4th function?
struct ActorProfile
{
    void *constructor;
    u16 updatePriority;
    u16 renderPriority;
    void *_unknownFunc;
};

// Class: Collider
struct Collider
{
    u8 _pad[0x23];
    Vec2_32 a;
    Vec2_32 b;
    Vec2_32 c;
    Vec2_32 d;
    Vec2_32 e;
};

// Class: Base
struct Base_vtable
{
    D_Base_vtable
};
struct Base
{
    Base_vtable *vtable;
    D_Base_data
};

// Class: Actor
struct Actor_vtable
{
    D_Actor_vtable
};
struct Actor
{
    Actor_vtable *vtable;
    D_Actor_data
};

// Class ActiveCollider
struct Rect
{
    i32 x;
    i32 y;
    i32 halfWidth;
    i32 halfHeight;
};
struct ActiveCollider_vtable
{
    unknown_pointer __0;
    unknown_pointer __1;
};
struct ActiveCollider
{
    ActiveCollider_vtable *vtable;
    u8 _pad_04[0x10];
    Rect rect;
    u8 _24;
    u8 _25;
    u16 _26;
    u8 _pad_28[4];
    void *_2c;
    u8 _pad_30[10];
    i32 _3c;
    u8 _pad_40[96];
    u16 _1c0; // 0x1C0
    u8 _pad_a2[4];
    u8 _1c6;
    u8 _pad_a7[9];
};

// Class: CollisionManager
struct CollisionManager_vtable
{
    unknown_pointer __0;
    unknown_pointer __1;
};
struct CollisionManager
{
    CollisionManager_vtable *vtable;
    u8 _pad0[0x1f];
    void *__1;
    u8 _pad1[0x8];
    CollisionManager *__2;
    u8 _pad2[0x5a];
    i8 _25e;
    u8 _pad3[40];
    u8 _b7;
};

// Struct PlatformManager
struct PlatformManager_vtable
{
};
struct PlatformManager
{
    PlatformManager_vtable *vtable;
    u8 _pad0[0x14];
    void *__1;
    u8 _pad1[0x18];
};

// Class: StageActor
struct StageActor
{
    Actor_vtable *vtable;
    D_StageActor_data
};

// Class: StageEntity
struct StageEntity_vtable
{
    D_StageEntity_vtable
};
struct StageEntity
{
    StageEntity_vtable *vtable;
    D_StageEntity_Data
};

// Class: PlayerBase
struct PlayerBase_vtable
{
    D_PlayerBase_vtable
};
struct PlayerModel
{
    u8 _2c4;
};
struct SpinClass
{
    u8 _pad;
};
struct BlendColor
{
    u8 _pad;
};

struct PlayerBase
{
    PlayerBase_vtable *vtable;
    D_PlayerBase_data
};

// Class: Player
struct PendulumController
{
    u8 pad;
};
struct Unknown
{
    Vec3_32 a;
};


typedef PlayerBase_vtable PlayerActor_vtable;
struct PlayerActor
{
    PlayerBase_vtable *vtable;
    D_PlayerActor_data
};

// Class: Coin
typedef StageEntity_vtable Coin_vtable;
struct Coin_data
{
    D_StageEntity_Data;
    u32 _3f4;      // 0x3F4
    Vec3_32 _3f8;  // 0x3F8
    Vec3_32 _408;  // 0x408
    Vec2_32 _418;  // 0x418
    Vec2_32 _424;  // 0x424
    PTMF *_430;    // 0x430
    Vec3_32 _434;  // 0x434
    Collider _444; // 0x444
    u8 _pad0[9];
    u8 _4ad;
    u8 _pad5[1];
    u32 _4b0;
    u8 _pad7[12];
    u32 _4c0;
    u32 _4c4;
    u16 _4ce;
    u16 _4d0;
    u16 _4d8;
    u16 _4da;
    u16 _4dc;
    u16 _4de;
    u16 _4e0;
    u16 _4e2;
    u8 _4e8; // 0x4E8
    u8 _4e9;
    u8 _4ea;
    u8 _4eb;
    u8 _4ec;
    u8 _4ed;
    u8 _4ee;
    u8 _4ef;
    u8 _pad3[0x3];
    u8 _4e3;
    u8 _4e4;
};
struct Coin
{
    Coin_vtable *vtable;
    Coin_data _;
};
