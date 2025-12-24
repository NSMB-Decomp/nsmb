#include "Actor.hpp"

class CollisionManager;

class ActiveCollider {
public:
    u8 padding[0x18];
    void *__1;
    u8 padding2[0x94];
    static void delink(void*);
    ActiveCollider();
    ~ActiveCollider();
};

class PlatformManager {
public:
    u8 padding[0x18];
    void *__1;
    u8 padding2[0x18];
    void init(void*, void*);
    PlatformManager();
    ~PlatformManager();
};

class CollisionManager {
public:
    u8 padding[0x23];
    void *__1;
    u8 padding2[0x90];
    CollisionManager();
    ~CollisionManager();
};

class StageActor : Actor {
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