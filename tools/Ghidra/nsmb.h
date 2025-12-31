// This file includes all types that are used within the Ghidra project
// Todo: Shalst we seperate this into different header files?
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
#define D_Base_vtable               \
    bool (*onCreate)(void);         \
    bool (*preCreate)(void);        \
    void (*postCreate)(u16, u16);   \
    bool (*onDestroy)();            \
    bool (*preDestroy)();           \
    void (*postDestroy)(u16, u16);  \
    bool (*onUpdate)();             \
    bool (*preUpdate)();            \
    void (*postUpdate)();           \
    bool (*onRender)();             \
    bool (*preRender)();            \
    void (*postRender)();           \
    void (*pendingDestroy)();       \
    void (*prepareResourcesSafe)(); \
    void (*prepareResourcesFast)(); \
    bool (*onPrepareResources)();   \
    void (*destroy1)();             \
    void (*destroy2)();

#define D_Base_data           \
    u32 guid; /*Base*/        \
    u32 settings;             \
    u16 object_id;            \
    u8 state;                 \
    bool pending_destroy;     \
    bool pending_update;      \
    bool pending_create;      \
    u8 _12;                   \
    u8 skipFlags;             \
    ProcessLink process_link; \
    void *_54;                \
    void *heap;

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
#define D_Actor_vtable               \
    D_Base_vtable void (*setPosX)(); \
    void (*incPosX)();

#define D_Actor_data                  \
    D_Base_data                       \
        Vec3_32 position; /* Actor */ \
    Vec3_32 lastPosition;             \
    Vec3_32 lastStep;                 \
    Vec3_32 centerOffset;             \
    Vec3_16 rotation;                 \
    Vec3_16 lastRotation;             \
    i32 velH;                         \
    i32 minVelH;                      \
    i32 accelV;                       \
    i32 minVelV;                      \
    i32 accelH;                       \
    u32 _c8;                          \
    Vec3_32 velocity;                 \
    Vec3_32 minVelocity;              \
    Vec3_32 scale;                    \
    Vec3_32 acceleration;             \
    Vec3_32 velocitylimit;            \
    u8 actorType;                     \
    bool visible;                     \
    i8 linked_player;                 \
    u8 actorCategory;

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
#define D_StageActor_Data               \
    D_Actor_data                        \
        ActiveCollider active_collider; \
    CollisionManager collision_manager; \
    PlatformManager platform_manager;   \
    u8 _2bc;                            \
    u8 direction;                       \
    u8 _2be;                            \
    u8 _2bf;                            \
    u32 empty; /* TODO: what does empty mean?*/

struct StageActor
{
    Actor_vtable *vtable;
    D_StageActor_Data
};

// Class: StageEntity
#define D_StageEntity_Data       \
    D_StageActor_Data;           \
    u8 _2c4;         /* 0x2C4 */ \
    u8 _2c5;         /* 0x2C5 */ \
    u16 _2c6;        /* 0x2C6 */ \
    u8 _pad13[0x02]; /* 0x2C0 */ \
    u16 _2ca;        /* 0x2CA */ \
    u8 _pad9[0x2];               \
    u32 _2d0; /* 0x2D0 */        \
    u8 _pad1[0x38];              \
    Vec3_32 _30c; /* 0x30C */    \
    Vec3_32 _31c; /* 0x31C */    \
    u8 _pad2[0x14];              \
    i32 _340; /* 0x340 */        \
    u8 _pad14[0x8];              \
    u32 _34c; /* 0x34C */        \
    i32 _350; /* 0x350 */        \
    u8 _pad6[0x4];               \
    u32 _358;     /* 0x358 */    \
    Vec3_32 _35c; /* 0x35C */    \
    Vec2_32 _36c; /* 0x36C */    \
    Vec2_32 _378; /* 0x378 */    \
    Vec2_32 _384; /* 0x384 */    \
    Vec2_32 _390; /* 0x390 */    \
    Vec2_32 _39c; /* 0x39C */    \
    u32 _3a8;     /* 0x3A8 */    \
    u8 _pad3[0x8];               \
    u32 _3b4; /* 0x3B4 */        \
    u32 _3b8; /* 0x3B8 */        \
    u16 _3bc; /* 0x3BC */        \
    u8 _pad11[0x4];              \
    u16 _3c2; /* 0x3C2 */        \
    u8 _pad_3c4[2];              \
    u16 _3c6[2]; /* 0x3C6 */     \
    u8 _pad_3ca[1];              \
    u16 *_3cc; /* 0x3CC */       \
    u8 _3d0;   /* 0x3D0 */       \
    u8 _pad15[0x1];              \
    u8 _3d2; /* 0x3D2 */         \
    u8 Pad5[0x3];                \
    u8 *_3d8; /* 0x3D8 */        \
    u8 _pad4[0x2];               \
    u8 _3de; /* 0x3DE */         \
    u8 _3df; /* 0x3DF */         \
    u8 _pad16[0x4];              \
    u8 _3e4; /* 0x3E4 */         \
    u8 _pad8[2];                 \
    i8 _3e7; /* 0x3E7 */         \
    u8 _3e8; /* 0x3E8 */         \
    u8 _3e9; /* 0x3E9 */         \
    u8 _3ea; /* 0x3EA */         \
    u8 _3eb; /* 0x3EB */         \
    u8 _3ec; /* 0x3EC */         \
    u8 _3ed; /* 0x3ED */         \
    u8 _3ee; /* 0x3EE */         \
    u8 _3ef; /* 0x3EF */         \
    u8 _3f0; /* 0x3F0 */         \
    u8 _3f1; /* 0x3F1 */

struct StageEntity_vtable
{
    Actor_vtable StageActor;
    unknown_pointer __0;
    unknown_pointer __1;
    unknown_pointer __2;
    unknown_pointer __3;
    unknown_pointer __4;
    unknown_pointer __5;
    unknown_pointer __6;
    unknown_pointer __7;
    unknown_pointer __8;
    unknown_pointer __9;
    unknown_pointer __10;
    unknown_pointer __11;
    unknown_pointer __12;
    unknown_pointer __13;
    unknown_pointer __14;
    unknown_pointer __15;
    unknown_pointer __16;
    unknown_pointer __17;
    unknown_pointer __18;
    unknown_pointer __19;
    unknown_pointer __20;
    unknown_pointer __21;
    unknown_pointer __22;
    unknown_pointer __23;
    unknown_pointer __24;
    unknown_pointer __25;
    unknown_pointer __26;
    unknown_pointer __27;
    unknown_pointer __28;
    unknown_pointer __29;
    unknown_pointer __30;
    unknown_pointer __31;
    unknown_pointer __32;
    unknown_pointer __33;
    unknown_pointer __34;
    unknown_pointer __35;
    unknown_pointer __36;
    unknown_pointer __37;
    unknown_pointer __38;
    unknown_pointer __39;
    unknown_pointer __40;
    unknown_pointer __41;
    unknown_pointer __42;
    unknown_pointer __43;
    unknown_pointer __44;
    unknown_pointer __45;
    unknown_pointer __46;
};
struct StageEntity
{
    StageEntity_vtable *vtable;
    D_StageEntity_Data
};

// Class: PlayerBase
struct PlayerBase_vtable
{
    Actor_vtable StageActor;
    unknown_pointer virt_20;
    unknown_pointer virt_21;
    unknown_pointer virt_22;
    unknown_pointer virt_23;
    unknown_pointer virt_24;
    unknown_pointer virt_25;
    unknown_pointer virt_26;
    unknown_pointer virt_27;
    unknown_pointer virt_28;
    unknown_pointer virt_29;
    unknown_pointer virt_30;
    unknown_pointer virt_31;
    unknown_pointer virt_32;
    unknown_pointer virt_33;
    unknown_pointer virt_34;
    unknown_pointer virt_35;
    unknown_pointer virt_36;
    unknown_pointer virt_37;
    unknown_pointer virt_38;
    unknown_pointer virt_39;
    unknown_pointer virt_40;
    unknown_pointer virt_41;
    unknown_pointer virt_42;
    unknown_pointer virt_43;
    unknown_pointer virt_44;
    unknown_pointer virt_45;
    unknown_pointer virt_46;
    unknown_pointer virt_47;
    unknown_pointer virt_48;
    unknown_pointer virt_49;
    unknown_pointer virt_50;
    unknown_pointer virt_51;
    unknown_pointer virt_52;
    unknown_pointer virt_53;
    unknown_pointer virt_54;
    unknown_pointer virt_55;
    unknown_pointer virt_56;
    unknown_pointer virt_57;
    unknown_pointer virt_58;
    unknown_pointer virt_59;
    unknown_pointer virt_60;
    unknown_pointer virt_61;
    unknown_pointer virt_62;
    unknown_pointer virt_63;
    unknown_pointer virt_64;
    unknown_pointer virt_65;
    unknown_pointer virt_66;
    unknown_pointer virt_67;
    unknown_pointer virt_68;
    unknown_pointer virt_69;
    unknown_pointer virt_70;
};
struct PlayerModel {
    u8 _2c4;
};
struct SpinClass {};
struct BlendColor{};
struct PlayerBase
{
    PlayerBase_vtable *vtable;
        D_StageActor_Data
    PlayerModel _000;
    u8 _pad1[0x3c0];
    Actor* linkedActor;
    u8 _pad10[0x44];
    SpinClass _40c;
    u8 _pad11[0x23];
    BlendColor _430;
    u8 _pad12[0x17];
    BlendColor _488;
    u8 _pad8[0x16];
    Vec3_32 _724;
    Vec3_32 _734;
    Vec3_32 _744;
    u8 _pad9[0x24];
    u32 _778;
    u32 _77c;
    u32 _780;
    u8 _pad7[0x4];
    u32 _788;
    u8 _pad2[0x0b];
    i32 _798;
    i16 _79c;
    u8 _pad3[0xa];
    i8 _7a8;
    u8 _7a9;
    u8 _7aa;
    i8 _7ab;
    i8 _7ac;
    u8 _pad5[0x3];
    u8 _7b0;
    i8 _7b1;
    i8 _7b2;
    u8 _7b3;
    i8 _7b4;
    u8 _pad6[0xa];
    u8 _7bf;
    u8 _7c0;
    u8 _7c1;
    u32 _7c4;
    u32 _7c8;
};

// Class: Player
typedef PlayerBase_vtable PlayerActor_vtable;
struct PlayerActor_data
{
    PlayerBase PlayerBase;
};
struct PlayerActor
{
    PlayerActor_data *vtable;
    PlayerActor_data _;
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
