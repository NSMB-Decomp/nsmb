#include "Actor.hpp"
#include "AAA.hpp"

bool Actor::preDestroy() {
    return Base::preDestroy() != false;
}

bool Actor::preCreate() {
    return Base::preCreate() != false;
}

void Actor::postDestroy(u32 a) {
    Base::postDestroy(a);
}

bool Actor::preUpdate() {
    if (!Base::preCreate()) {
        return false;
    }

    if (!(Stage_actorFreezeFlag & this->actorCategory)) {
        Vec3 step;
        step.sub(this->position, this->lastPosition);
        
        // These need to also set the vtable
        this->lastStep = step;
        this->lastPosition = this->position;
        return true;
    }
    return false;
}