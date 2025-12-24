#include "Actor.hpp"

Vec3_32 *data_ov000_020ca85c;
Vec3_16 *data_ov000_020ca860;
i32 *data_ov000_020ca868;
i8 *data_ov000_020ca864;

Actor::Actor() {

    // Set Position
    if (data_ov000_020ca85c != NULL) {
        this->position = *data_ov000_020ca85c;
        this->lastPosition = *data_ov000_020ca85c;
        this->lastStep.x = 0;
        this->lastStep.y = 0;
        this->lastStep.z = 0;
    }
    // Set Rotation
    if (data_ov000_020ca860 != NULL) {
        this->rotation = *data_ov000_020ca860;
        this->lastRotation = *data_ov000_020ca860;
    }
    // Set Scale
    if (data_ov000_020ca868 != NULL) {
        i32 a = *data_ov000_020ca868;
        this->scale.x = a;
        this->scale.y = a;
        this->scale.z = a;
    } else {
        this->scale.x = 0x1000;
        this->scale.y = 0x1000;
        this->scale.z = 0x1000;
    }
    // Set Linked Player 
    if ( data_ov000_020ca864 != 0x0) {
        this->linkPlayer(*data_ov000_020ca864);
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
Actor::~Actor() {}
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
u32 Actor::getActorCount(u8 a) {
    Base* prev;
    u32 i = 0;

    for (
        prev = ProcessManager::getNextObjectByObjectID(a, (Base*)NULL);
        prev != NULL;
        prev = ProcessManager::getNextObjectByObjectID(a, prev)
    ) {
        i += 1;
    }

    return i;
}