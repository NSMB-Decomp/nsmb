#include "Actor.hpp"

bool Actor::preDestroy()
{
    return Base::preDestroy() != false;
}

bool Actor::preCreate()
{
    return Base::preCreate() != false;
}

void Actor::postDestroy(u32 a)
{
    Base::postDestroy(a);
}

bool Actor::preUpdate()
{
    if (!Base::preCreate())
    {
        return false;
    }

    if (!(Stage_actorFreezeFlag & this->actorCategory))
    {
        Vec3 step;
        step.sub(this->position, this->lastPosition);

        // These need to also set the vtable
        this->lastStep = step;
        this->lastPosition = this->position;
        return true;
    }
    return false;
}

void Actor::postUpdate()
{
    Base::postUpdate();
}

bool Actor::preRender()
{
    if (
        (Base::preRender()) && 
        (data_0v000_020ca84c & (1 << (this->actorType & 0xffU | 0x80)))   
    )
    {
        return this->visible != 0;
    } else {
        return false;
    }
}

void Actor::postRender() {
    Base::postRender();
}

void Actor::linkPlayer(u8 player_id) {
    this->linked_player = player_id;
}