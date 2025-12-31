#include "Actor.hpp"

struct Rect
{
    i32 x;
    i32 y;
    i32 halfWidth;
    i32 halfHeight;
};
size_assert(Rect, 0x10);

class ActiveCollider
{
public:
    u8 _pad_04[0x10];
    Rect rect;
    u8 _24;
    u8 _25;
    u16 _26;
    u8 _pad_28[4];
    void* _2c;
    u8 _pad_30[10];
    i32 _3c;
    u8 _pad_40[96];
    u16 _1c0; // 0x1C0
    u8 _pad_a2[4];
    u8 _1c6;
    u8 _pad_a7[9];

    ActiveCollider();
    ~ActiveCollider();

    bool resetCollisionState();
    void delink();
    virtual void _TEMP(); // To make sure size is correct
};
size_assert(ActiveCollider, 0xb0);

class PlatformManager
{
public:
    u8 _pad0[0x14];
    void *__1;
    u8 _pad1[0x18];

    PlatformManager();
    ~PlatformManager();

    void func_0201d730();
    void init(void *, void *);
    virtual void _TEMP(); // To make sure size is correct
};
size_assert(PlatformManager, 0x34);

class CollisionManager
{
public:
    u8 _pad0[0x1f];
    void *__1;
    u8 _pad1[0x8];
    CollisionManager *__2;
    u8 _pad2[0x5a];
    i8 _25e;
    u8 _pad3[0x26];

    CollisionManager();
    ~CollisionManager();

    void func_ov000_020ab9ac();
    void func_ov000_020ab350();
    virtual void _TEMP(); // To make sure size is correct
};
size_assert(CollisionManager, 0xb8);

class StageActor : public Actor
{
public:
    ActiveCollider active_collider;
    CollisionManager collision_manager;
    PlatformManager platform_manager;
    u8 _2bc;      /* 0x2BC */
    u8 direction; /* 0x2BD */
    u8 _2be;      /* 0x2BE */
    u8 _2bf;      /* 0x2BF */
    u32 empty;    /* TODO: what does empty mean? */

    StageActor();
    ~StageActor();

    bool preUpdate();
    void postUpdate(u32);
    bool isInActiveView();
};