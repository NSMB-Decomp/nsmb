#include "Actor.hpp"

struct Rect {
    i32 x;
    i32 y;
    i32 halfWidth;
    i32 halfHeight;
};
size_assert(Rect, 0x10);

class ActiveCollider {
public:
    u8 _pad0[0x14];
    Rect rect;
    void *__1;
    u8 _pad4[18];
    i32 _3c;
    u8 _pad1[96];
    u16 _1c0; // 0x1C0
    u8 _pad3[3];
    u8 _1c6;
    u8 _pad2[7];

    ActiveCollider();
    ~ActiveCollider();

    void delink();
};
size_assert(ActiveCollider, 0xb0);

class PlatformManager {
public:
    u8 _pad0[0x18];
    void *__1;
    u8 _pad1[0x18];

    PlatformManager();
    ~PlatformManager();

    void init(void*, void*);
};

class CollisionManager {
public:
    u8 _pad0[0x23];
    void *__1;
    u8 _pad1[0x8];
    CollisionManager *__2;
    u8 _pad2[0x84];

    CollisionManager();
    ~CollisionManager();

    void func_ov000_020ab350();
};

class StageActor : public Actor {
public:
    ActiveCollider active_collider;
    CollisionManager collision_manager;
    PlatformManager platform_manager;
    u8 __1;
    u8 direction;
    u8 __4;
    u8 __2;
    u32 empty; // TODO: what does empty mean?

    StageActor();
    ~StageActor();

    bool preUpdate();
    void postUpdate();
    bool isInActiveView();
};