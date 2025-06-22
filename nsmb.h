// This file includes all types that are used within the Ghidra project

typedef unsigned char u8;
typedef unsigned int u16;
typedef unsigned long u32;
typedef signed char i8;
typedef signed int i16;
typedef signed long i32;

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

struct Actor_vtable
{
    Base_vtable Base;
    void (*setPosX)();
    void (*incPosX)();
};

struct Player_vtable
{
    Actor_vtable Actor;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
};

struct Coin_vtable {
    Actor_vtable Actor;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
    void *unknown;
};