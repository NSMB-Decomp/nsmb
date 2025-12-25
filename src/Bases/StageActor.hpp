#include "Actor.hpp"

class ActiveCollider {
public:
    u8 padding[0x18];
    void *__1;
    u8 padding2[0x94];

    ActiveCollider();
    ~ActiveCollider();

    static void delink(void*);
};

class PlatformManager {
public:
    u8 padding[0x18];
    void *__1;
    u8 padding2[0x18];

    PlatformManager();
    ~PlatformManager();

    void init(void*, void*);
};

class CollisionManager {
public:
    u8 _pad1[0x23];
    void *__1;
    u8 _pad2[0x8];
    CollisionManager *__2;
    u8 padding3[0x84];

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
    u8 __3;
    u8 __4;
    u8 __2;

    StageActor();
    ~StageActor();

    bool preUpdate();
    void postUpdate();
};