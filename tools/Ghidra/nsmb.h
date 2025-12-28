// This file includes all types that are used within the Ghidra project
// Todo: Shalst we seperate this into different header files? 
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef signed char i8;
typedef signed short i16;
typedef signed long i32;
enum bool8 { // 4 bytes long
    False = 0,
    True = 1,
};

// Placeholders
typedef u8 unknown1;
typedef u16 unknown2;
typedef u32 unknown4;
typedef void* unknown_pointer;
struct unknown_vtable {};

// Math
struct Vec3_16 {
    unknown_vtable *vtable;
    i16 x;
    i16 y;
    i16 z;
    u8 _pad0[2];
};
struct Vec3_32 {
    unknown_vtable *vtable;
    i32 x;
    i32 y;
    i32 z;
};
struct Vec2_32 {
    unknown_vtable *vtable;
    i32 x;
    i32 y;
};

// Process
// TODO: Can we improve these names at all?
struct ProcessNode {
    ProcessNode *prev;
    ProcessNode *next;
    struct Base *object;
};

struct PriorityNode {
    ProcessNode _;
    u16 currentPriority;
    u16 sortPriority;
};

struct SceneNode {
    SceneNode *parent;
    SceneNode *firstChild;
    SceneNode *prev;
    SceneNode *next;
    struct Base *object;
};

struct ProcessLink {
    SceneNode connect;
    PriorityNode update;
    PriorityNode render;
    ProcessNode idLookup;
};

struct PTMF { // What is a PTMF?
    void (*func)(void *, ...);
    u32 params;
};

struct SceneGraph {
    SceneNode *root;
    PTMF executor;
};

struct LinkedList {
    ProcessNode *first;
    ProcessNode *last;
};

struct ProcessManager {
    SceneGraph sceneGraph;
    ProcessLink updateProcess;
    ProcessLink deleteProcess;
    ProcessLink renderProcess;
    ProcessLink createProcess;
    LinkedList idLookupProcesses[8];
};

struct ProcessList {
    LinkedList _;
    PTMF executor;
};

enum ActorType {
    None = 0,
    Scene = 1,
    Actor = 2,
};

enum ObjectType {

};

enum ProcessType {
    Null = 0,
    Connect = 1,
    Create = 2,
    Execute = 3,
    Delete = 4,
    Draw = 5,
};

// TODO: Does this need to be renamed?
// TODO: Does this have a optioanal 4th function?
struct ActorProfile {
    void *constructor;
    u16 updatePriority;
    u16 renderPriority;
    void *_unknownFunc;
};

// Class: Collider
struct Collider {
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
    u8 __1;
    u8 __2;
    u8 __3;
    u8 __4;
    ProcessLink processLink;
    unknown_pointer __5;
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
    Base_data Base; // 0x00
    Vec3_32 position;
    Vec3_32 lastPosition;
    Vec3_32 lastStep; // 0x78
    Vec3_32 centerOffset;
    Vec3_16 rotation;
    Vec3_16 lastRotation;
    i32 velH; // TODO: These names are awful, fix them D:<.
    i32 minVelH;
    i32 accelV;
    i32 minVelV;
    i32 accelH; // 0xC4
    u32 _c8; //0xC8
    Vec3_32 velocity; // 0xCA
    Vec3_32 minVelocity;
    Vec3_32 scale;
    Vec3_32 acceleration;
    Vec3_32 velocitylimit;
    u8 actorType; // 0x11C
    bool visible;
    i8 linked_player;
    u8 actorCategory; //0x11F
};
struct Actor
{
    Actor_vtable *vtable;
    Actor_data _;
};

// Class ActiveCollider
struct ActiveCollider_vtable {
    unknown_pointer __0;
    unknown_pointer __1;
};
struct ActiveCollider_data {
    u8 _pad0[0x18];
    void *__1;
    u8 _pad1[138];
    u8 _1c6;
    u8 _pad2[9];
};
struct ActiveCollider {
    ActiveCollider_vtable *vtable;
    ActiveCollider_data _;
};

// Class: CollisionManager
struct CollisionManager_vtable {
    unknown_pointer __0;
    unknown_pointer __1;
};
struct CollisionManager_data {
    u32 __00;
    u32 __04;
    u32 __08;
    u32 __0c;
    u32 __10;
    u32 __14;
    u32 __18;
    u32 __1c;
    u32 __20;
    u32 __24;
    u32 __28;
    u32 __2c;
    u32 __30;
    u32 __34;
    u32 __38;
    u32 __3c;
    u32 __40;
    u32 __44;
    u32 __48;
    u32 __4c;
    u32 __50;
    u32 __54;
    u32 __58;
    u32 __5c;
    u32 __60;
    u32 __64;
    u32 __68;
    u32 __6c;
    u32 __70;
    u32 __74;
    u32 __78;
    u32 __7c;
    u32 __80;
    u32 __84;
    u32 __88;
    u32 __8c;
    u32 __90;
    u32 __94;
    u32 __98;
    u32 __9c;
    u32 __a0;
    u32 __a4;
    u32 __a8;
    u32 __ac;
    u32 __b0;
};
struct CollisionManager {
    CollisionManager_vtable *vtable;
    CollisionManager_data _;
};

// Struct PlatformManager
struct PlatformManager_vtable {

};
struct PlatformManager_data {
    u32 __00;
    u32 __04;
    u32 __08;
    u32 __0c;
    u32 __10;
    u32 __14;
    u32 __18;
    u32 __1c;
    u32 __20;
    u32 __24;
    u32 __28;
    u32 __2c;
};
struct PlatformManager {
    PlatformManager_vtable *vtable;
    PlatformManager_data _;
};

// Class: StageActor
typedef Actor_vtable StageActor_vtable;
struct StageActor_data {
    Actor_data Actor;
    ActiveCollider active_collider;
    CollisionManager collision_manager;
    PlatformManager platform_manager;
    u8 __1;
    u8 direction; // 0 = left, 1 = right
    u8 __3;
    u8 __4;
};
struct StageActor {
    StageActor_vtable *vtable;
    StageActor_data _;
};

// Class: StageEntity
struct StageEntity_vtable
{
    StageActor_vtable StageActor;
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
struct StageEntity_data {
    StageActor_data StageActor;
    u8 _pad0[0x04]; // 0x2C0
    u8 _2c4; //0x2C4
    u8 _pad13[0x05]; // 0x2C0
    u16 _2ca; // 0x2CA
    u8 _pad9[0x2];
    u32 _2d0; // 0x2D0
    u8 _pad1[0x38];
    Vec3_32 _30c; // 0x30C
    Vec3_32 _31c; // 0x31C
    u8 _pad2[0x14];
    i32 _340; // 0x340
    u8 _pad14[0x8];
    u32 _34c; //0x34C
    i32 _350; // 0x350
    u8 _pad6[0x4];
    u32 _358; //0x358
    Vec3_32 _35c; // 0x35C
    Vec2_32 _36c; // 0x36C
    Vec2_32 _378; // 0x378
    Vec2_32 _384; // 0x384
    Vec2_32 _390; // 0x390
    Vec2_32 _39c; // 0x39C
    u32 _3a8; // 0x3A8
    u8 _pad3[0x8];
    u32 _3b4; // 0x3B4
    u8 _pad11[0xe];
    u16 _3c6; // 0x3C6
    u16 _3c8; // 0x3CA
    u8 pad12[0x6];
    u8 _3d0; //0x3D0
    u8 _pad15[0x1];
    u8 _3d2; // 0x3D2
    u8 Pad5[0x5];
    u32 _3d8; // 0x3D8
    u8 _pad4[0x2];
    u8 _3de; // 0x3DE
    u8 _3df; // 0x3DF
    u8 _pad16[0x4];
    u8 _3e4; // 0x3E4
    u8 _pad8[2];
    i8 _3e7; //0x3E7
    u8 _3e8; // 0x3E8
    u8 _3e9; //0x3E9
    u8 _3ea; //0x3EA
    u8 _3eb; //0x3EB
    u8 _3ec; //0x3EC
    u8 _3ed; //0x3ED
    u8 _3ee; //0x3EE
    u8 _3ef; //0x3EF
    u8 _3f0; //0x3F0
    u8 _3f1; //0x3F1
};
struct StageEntity {
    StageEntity_vtable *vtable;
    StageEntity_data _;
};

// Class: PlayerBase
struct PlayerBase_vtable {
    StageActor_vtable StageActor;
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
struct PlayerBase_data {
    StageActor_data StageActor;
    u8 _pad0[0x4];
    u8 _2c4;
    u8 _pad1[0x4b4];
    u32 _77c;
    u32 _780;
    u8 _pad2[0x14];
    u32 _798;
    u8 _pad3[0x10];
    i8 _7ac;
    u8 _pad4[0x3];
    i8 _7b0;
};
struct PlayerBase {
    PlayerBase_vtable *vtable;
    PlayerBase_data _;
};

// Class: Player
typedef PlayerBase_vtable Player_vtable;
struct Player_data {
    PlayerBase_data PlayerBase;
};
struct Player {
    Player_vtable *vtable;
    Player_data _;
};

// Class: Coin
typedef StageEntity_vtable Coin_vtable;
struct Coin_data {
    StageEntity_data StageEntity;
    u32 _3f4; // 0x3F4
    Vec3_32 _3f8; // 0x3F8
    Vec3_32 _408; // 0x408
    Vec2_32 _418; // 0x418
    Vec2_32 _424; // 0x424
    PTMF* _430; // 0x430
    Vec3_32 _434; // 0x434
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
struct Coin {
    Coin_vtable *vtable;
    Coin_data _;
};
