#include "StageActor.hpp"

StageActor::StageActor() {
    this->collision_manager.platform_manager = &this->platform_manager;
    this->platform_manager.init(this, NULL);
    this->platform_manager.collision_manager = &this->collision_manager;
    this->__1 = 0;
    this->__2 = 0;
}
StageActor::~StageActor() {
    ActiveCollider::delink((void*)&this->platform_manager);
}

bool StageActor::preUpdate() {
    bool a = Actor::preUpdate();
    if (a == false) {
        return false;
    }

    return false;
}

void StageActor::postUpdate() {
    Actor::postUpdate();
}