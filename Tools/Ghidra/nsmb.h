// This file includes all types that are used within the Ghidra project
// Todo: Shalst we seperate this into different header files? 
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
    u8 __1;
    u8 __2;
    u8 __3;
    u8 __4;
    ProcessLink unknown;
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
    Vec3_32 pos;
    Vec3_32 lastPos;
    unknown4 __0;
    unknown4 __1;
    unknown4 __2;
    unknown4 __3;
    unknown4 __4;
    unknown4 __5;
    unknown4 __6;
    unknown4 __7;
    unknown4 __8;
    unknown4 __9;
    unknown4 __10;
    unknown4 __11;
    unknown4 __12;
    unknown4 __13;
    unknown4 __14;
    unknown4 __15;
    unknown4 __16;
    unknown4 __17;
    unknown4 __18;
    unknown4 __19;
    unknown4 __20;
    unknown4 __21;
    unknown4 __22;
    unknown4 __23;
    unknown4 __24;
    unknown4 __25;
    unknown4 __26;
    unknown4 __27;
    unknown4 __28;
    unknown4 __29;
    unknown4 __30;
    unknown4 __31;
    unknown4 __32;
    unknown4 __33;
    unknown4 __34;
    unknown4 __35;
    unknown4 __36;
    unknown4 __37;
    unknown4 __38;
    unknown4 __39;
    unknown4 __40;
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

struct Coin_vtable
{
    Actor_vtable Actor;
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

struct StageEntity_vtable
{
    Actor_vtable Actor;
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