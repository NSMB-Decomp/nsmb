#include "StageActor.hpp"

StageActor::StageActor() {
    this->collision_manager.__1 = &this->platform_manager;
    this->platform_manager.init(this, NULL);
    this->platform_manager.__1 = &this->collision_manager;
    this->__1 = 0;
    this->__2 = 0;
}
StageActor::~StageActor() {
    ActiveCollider::delink((void*)&this->active_collider);
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