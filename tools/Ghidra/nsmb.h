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
    Base_data Base;
    Vec3_32C pos;
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
    unknown1 __43;
};
struct Actor
{
    Actor_vtable *vtable;
    Actor_data _;
};

// Class: StageActor
typedef Actor_vtable StageActor_vtable;
struct StageActor_data {
    Actor_data Actor;
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