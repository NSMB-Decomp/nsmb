#include "Actor.hpp"

class CollisionManager;

class ActiveCollider {
public:
    u8 padding[0x34];
    static void delink(void*);
    ActiveCollider();
    ~ActiveCollider();
};

class PlatformManager {
public:
    u8 padding[0x9b];
    CollisionManager *collision_manager;
    u8 padding2[0x10];
    void init(void*, void*);
    PlatformManager();
    ~PlatformManager();
};

class CollisionManager {
public:
    u8 padding[0x23];
    PlatformManager *platform_manager;
    u8 padding2[0x90];
    CollisionManager();
    ~CollisionManager();
};

class StageActor : Actor {
public:
    PlatformManager platform_manager;
    CollisionManager collision_manager;
    ActiveCollider active_collider;
    u8 __1;
    u8 __3;
    u8 __4;
    u8 __2;

    StageActor();
    ~StageActor();
    bool preUpdate();
    void postUpdate();
};