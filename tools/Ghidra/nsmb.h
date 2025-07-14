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
struct Vec3_16C {
    unknown_vtable *vtable;
    i16 x;
    i16 y;
    i16 z;
    i16 __padding;
};
struct Vec3_32C {
    unknown_vtable *vtable;
    i32 x;
    i32 y;
    i32 z;
};

struct Vec3_16 {
    i16 x;
    i16 y;
    i16 z;
};
struct Vec3_32 {
    i32 x;
    i32 y;
    i32 z;
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
    Vec3_32C pos; // 0x58
    Vec3_32C lastPos;
    Vec3_32C __0;
    Vec3_32C __4;
    Vec3_16C __8;
    Vec3_16C __11;
    unknown4 __14;
    unknown4 __15;
    unknown4 __16;
    unknown4 __17;
    unknown4 __18;
    unknown4 __19;
    Vec3_32C __20;
    Vec3_32C __24;
    Vec3_32C __28;
    Vec3_32C __32;
    Vec3_32C __36;
    unknown1 __40;
    unknown1 __41;
    unknown1 __42;
    unknown1 __43; // 0x11b
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
enum Direction { // TODO: How do we force this to be 1 byte when importing into Ghidra?
    Left = 0,
    Right = 1,
} __attribute__((packed));

typedef Actor_vtable StageActor_vtable;
struct StageActor_data {
    Actor_data Actor;
    ActiveCollider active_collider;
    CollisionManager collision_manager;
    PlatformManager platform_manager;
    u8 __1;
    Direction __2; // Direction
    u8 __3;
    u8 __4;
    bool8 __5;
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
};
struct StageEntity {
    StageEntity_vtable *vtable;
    StageEntity_data _;
};

// Class: PlayerBase
struct PlayerBase_vtable {
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
    unknown_pointer __47;
    unknown_pointer __48;
    unknown_pointer __49;
    unknown_pointer __50;
};
struct PlayerBase_data {
    StageEntity_data StageEntity;
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
};
struct Coin {
    Coin_vtable *vtable;
    Coin_data _;
};