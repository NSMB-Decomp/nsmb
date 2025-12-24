#include "Actor.hpp"

class ActiveCollider {
public:
    static void delink(void*);
    ActiveCollider();
    ~ActiveCollider();
};

class CollisionMgr {
public:
    CollisionMgr();
    ~CollisionMgr();
};

class PlatformManager {
public:
    PlatformManager();
    ~PlatformManager();
};

class StageActor : Actor {
public:
    PlatformManager c;
    u8 padding2[175];
    CollisionMgr b;
    u8 padding3[183];
    ActiveCollider a;

    StageActor();
    ~StageActor();
    bool preUpdate();
    void postUpdate();
};