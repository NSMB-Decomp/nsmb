#include "StageActor.hpp"

StageActor::~StageActor() {
    ActiveCollider::delink((void*)&this->c);
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