#include "StageActor.hpp"

StageActor::StageActor() {
    this->collision_manager.__1 = &this->platform_manager;
    this->platform_manager.init(this, NULL);
    this->platform_manager.__1 = &this->collision_manager;
    this->__1 = 0;
    this->__2 = 0;
}
StageActor::~StageActor() {
    this->active_collider.delink();
}

void func_ov000_020aba48(CollisionManager*);
void func_0201d794(PlatformManager*);
bool StageActor::preUpdate() {
    this->empty = false;
    bool a = Actor::preUpdate();
    if (a == false) {
        return false;
    }

    if (GlobalFader.isComplete() != 0) {
        func_ov000_020aba48(&this->collision_manager);
        func_0201d794(&this->platform_manager);
        this->empty = true;
        return true;
    }

    return false;
}

void StageActor::postUpdate() {
    Actor::postUpdate();
}

bool StageActor::isInActiveView() {
    u32 i = 0;
    return true;
}