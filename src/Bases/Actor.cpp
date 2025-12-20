#include "Actor.hpp"

Actor::Actor() {
    Vec3_32 *iRam020ca85c = (Vec3_32*)0x020ca85c;
    Vec3_16 *iRam020ca860 = (Vec3_16*)0x020ca85c;
    i32 *piRam020ca868 = (i32*)0x020ca868;
    i32 *pcRam020ca864 = (i32*)0x020ca864;
    // Set Position
    if (iRam020ca85c != NULL) {
        this->position.x = iRam020ca85c->x;
        this->position.y = iRam020ca85c->y;
        this->position.z = iRam020ca85c->z;
        this->lastPosition.x = iRam020ca85c->x;
        this->lastPosition.y = iRam020ca85c->y;
        this->lastPosition.z = iRam020ca85c->z;
        this->lastStep.x = 0;
        this->lastStep.y = 0;
        this->lastStep.z = 0;
    }
    // Set Rotation
    if (iRam020ca860 != NULL) {
        this->rotation.x = iRam020ca860->x;
        this->rotation.y = iRam020ca860->y;
        this->rotation.z = iRam020ca860->z;
        this->lastRotation.x = iRam020ca860->x;
        this->lastRotation.y = iRam020ca860->y;
        this->lastRotation.z = iRam020ca860->z;
    }
    // Set Scale
    if (piRam020ca868 != NULL) {
        i32 a = *piRam020ca868;
        this->scale.x = a;
        this->scale.y = a;
        this->scale.z = a;
    } else {
        this->scale.x = 0x1000;
        this->scale.y = 0x1000;
        this->scale.z = 0x1000;
    }
    // Set Linked Player 
    if ( *pcRam020ca864 != 0x0) {
        this->linkPlayer(*pcRam020ca864);
    }
    else {
        this->linkPlayer(-1);
    }
    this->lastPosition.x = this->position.x;
    this->lastPosition.y = this->position.y;
    this->lastPosition.z = this->position.z;
    this->visible = true;
    this->actorType = 0;
    this->actorCategory = (u8)(1 << this->actorType | 0x80); // unsigned to signed conversion?
    this->acceleration.x = 0;
    this->acceleration.y = 0;
    this->acceleration.z = 0;
    this->velocitylimit.x = 0x8000;
    this->velocitylimit.y = 0x8000;
    this->velocitylimit.z = 0x8000;
    this->actorCategory = 0x80;
}
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

void Actor::postCreate(u32 a)
{
    Object::postCreate(a);
}

bool Actor::preUpdate()
{
    if (!Base::preCreate())
    {
        return false;
    }

    if (!(Stage_actorFreezeFlag & this->actorCategory))
    {
        Vec3_32 step;
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

void Actor::linkPlayer(i32 player_id) {
    this->linked_player = player_id;
}