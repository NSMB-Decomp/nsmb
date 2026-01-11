#include "Actor.hpp"
#include "Nitro.hpp"
#include "../Math.hpp"

// TODO: Some of this may be a part of inline Object::Object(). To comapre Actor::Actor() to Scene::Scene() and confirm if any comparisons
Actor::Actor()
{
    // Set Position
    if (ActorSpawnPosition != NULL)
    {
        this->position = *ActorSpawnPosition;
        this->lastPosition = *ActorSpawnPosition;
        this->lastStep.x = 0;
        this->lastStep.y = 0;
        this->lastStep.z = 0;
    }
    // Set Rotation
    if (ActorSpawnRotation != NULL)
    {
        this->rotation = *ActorSpawnRotation;
        this->lastRotation = *ActorSpawnRotation;
    }
    // Set Scale
    if (ActorSpawnScale != NULL)
    {
        i32 a = *ActorSpawnScale;
        this->scale.x = a;
        this->scale.y = a;
        this->scale.z = a;
    }
    else
    {
        this->scale.x = 0x1000;
        this->scale.y = 0x1000;
        this->scale.z = 0x1000;
    }
    // Set Linked Player
    if (ActorSpawnPlayer != 0x0)
    {
        this->linkPlayer(*ActorSpawnPlayer);
    }
    else
    {
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

bool Actor::preCreate()

{
    return Base::preCreate() != false;
}
void Actor::postCreate(u32 a)
{
    Object::postCreate(a);
}

bool Actor::preDestroy()
{
    return Base::preDestroy() != false;
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

    if (!(Stage::actorFreezeFlag & this->actorCategory))
    {
        Vec3_32 step = this->position.sub(&this->lastPosition);
        this->lastStep = step;
        this->lastPosition = this->position;
        return true;
    }
    return false;
}

void Actor::postUpdate(u32 a)
{
    Base::postUpdate(a);
}

bool Actor::preRender()
{
    if (
        (!Base::preRender()) ||
        (data_ov000_020ca84c &
         (((1 << this->actorType) | 0x80) & 0xff)) &
            0xff)
    {
        return false;
    }
    else
    {
        return !!this->visible;
    }
}

void Actor::postRender(u32 a)
{
    Base::postRender(a);
}

u32 Actor::getActorCount(u8 a)
{
    Base *prev;
    u32 i = 0;

    for (
        prev = ProcessManager::getNextObjectByObjectID(a, (Base *)NULL);
        prev != NULL;
        prev = ProcessManager::getNextObjectByObjectID(a, prev))
    {
        i += 1;
    }

    return i;
}

void Actor::setSpawnParams(Vec3_32 *a, Vec3_16 *b, i32 *c, i8 *d)
{
    ActorSpawnPosition = a;
    ActorSpawnRotation = b;
    ActorSpawnScale = c;
    ActorSpawnPlayer = d;
}

u16 data_0203bd34;
Actor* Actor::spawnActor(u16 a, u32 b, Vec3_32 *c, Vec3_16 *d, i32 *e, i8 *f)
{
    Base *pBVar1;

    setSpawnParams(c, d, e, f);
    pBVar1 = ProcessManager::getNextObjectByObjectID(data_0203bd34, (Base *)0x0);
    return (Actor*)Object::spawnObject(a, pBVar1, b, 2);
}

void Actor::linkPlayer(i32 player_id)
{
    this->linked_player = player_id;
}

Vec3_32 Actor::applyAcceleration(Vec3_32 *acceleration)
{
    Vec3_32 result;
    result.x = acceleration->x + this->acceleration.x;
    i32 iVar1;
    i32 iVar2 = result.x;
    if (iVar2 < 0)
    {
        iVar1 = -this->velocitylimit.x;
        if (iVar2 < iVar1)
        {
            result.x = iVar1;
        }
    }
    else
    {
        iVar1 = this->velocitylimit.x;
        if (iVar2 > iVar1)
        {
            result.x = iVar1;
        }
    }
    result.y = acceleration->y + this->acceleration.y;
    iVar2 = result.y;
    if (iVar2 < 0)
    {
        iVar1 = -this->velocitylimit.y;
        if (iVar2 < iVar1)
        {
            result.y = iVar1;
        }
    }
    else
    {
        iVar1 = this->velocitylimit.y;
        if (iVar2 > iVar1)
        {
            result.y = iVar1;
        }
    }
    result.z = acceleration->z;
    return result;
}

// TODO: Is there a better sytax?
void Actor::applyVelocityToPosition(Vec3_32 *velocity)
{
    u32 c = ((u32)this + 0x5c);
    if (c != 0)
    {
        c += 4;
    }

    u32 a = ((i32)this + 0x5c);
    if (a != 0)
    {
        a += 4;
    }

    u32 b = ((u32)velocity + 4);

    Nitro::Math_AddVec3_32s(
        (Vec3_32s *)a,
        (Vec3_32s *)b,
        (Vec3_32s *)c);
}

void Actor::applyVelocity()
{
    Vec3_32 newVelocity = this->applyAcceleration(&this->velocity);
    this->applyVelocityToPosition(&newVelocity);
}

void Actor::applyDirectionalVelocity() {}

void Actor::setDirectionalVelocity3D() {}

void Actor::updateHorizontalVelocity()
{
    i32 velX = this->velocity.x;
    i32 minVelX = this->minVelocity.x;
    if (velX < minVelX)
    {
        velX += this->accelH;
        if (velX > minVelX)
        {
            velX = minVelX;
        }
    }
    else if ((velX > minVelX) && (velX -= this->accelH, velX < minVelX))
    {
        velX = minVelX;
    }
    this->velocity.x = velX;
}

void Actor::updateVerticalVelocity()
{
    i32 iVar2 = this->velocity.y + this->accelV;
    i32 iVar1 = this->minVelocity.y;
    if (iVar2 < iVar1)
    {
        iVar2 = iVar1;
    }
    this->velocity.y = iVar2;
    return;
}

void Actor::StepVelocityYClamped()
{

    i32 minVelV = this->minVelV;
    i32 velY = this->velocity.y;
    if (velY < minVelV)
    {
        velY -= this->accelV;
        if (velY <= minVelV)
        {
            minVelV = velY;
        }
        this->velocity.y = minVelV;
        return;
    }
    if (velY <= minVelV)
    {
        return;
    }
    velY += this->accelV;
    if (velY >= minVelV)
    {
        minVelV = velY;
    }
    this->velocity.y = minVelV;
}

void Actor::StepVelocityXClamped()
{
    i32 minVelH = this->minVelH;
    i32 velH = this->velH;
    if (velH < minVelH)
    {
        velH += this->accelH;
        if (velH <= minVelH)
        {
            minVelH = velH;
        }
        this->velH = minVelH;
        return;
    }
    if (velH <= minVelH)
    {
        return;
    }
    velH -= this->accelH;
    if (velH >= minVelH)
    {
        minVelH = velH;
    }
    this->velH = minVelH;
    return;
}

void Actor::stepVelocityClamped()
{
    this->StepVelocityXClamped();
    this->velocity.x = this->velH;
    this->StepVelocityYClamped();
}

void Actor::applyDirectionalVelocity3D()
{
    this->setDirectionalVelocity3D();
    this->applyVelocity();
}

void Actor::attenuateAcceleration() {
  Math::expLerp(&this->acceleration.x,0,0x200,0x4000,0x100);
  Math::expLerp(&this->acceleration.y,0,0x200,0x4000,0x100);
  Math::expLerp(&this->acceleration.z,0,0x200,0x4000,0x100);
}

Vec3_32 Actor::getCenteredPosition()
{
    Vec3_32 result;

    i32 x = this->position.x + this->centerOffset.x;
    i32 z = this->position.z + this->centerOffset.z;
    i32 y = this->position.y + this->centerOffset.y;

    result.x = x;
    result.y = y;
    result.z = z;

    return result;
}

bool Actor::isOutOfViewVertical(Rect *rect,int player_id)
{
  return 
    rect->halfHeight + rect->y + this->position.y + 0x18000 <
    -Game::cameraY[player_id] + Game::cameraZoomY[player_id];
}

i32(*data_ov000_020ca858)(i32, i32, i32, i32);
i32(*data_ov000_020c6c14[3])(i32, i32, i32, i32) = {
    Actor::calcDistanceToPlayerNoWrap,
    Actor::calcDistanceToPlayerWrap,
    Actor::calcDistanceToPlayerWrap,
};

i32 Actor::calcDistanceToPlayerNoWrap(i32, i32, i32, i32) {

}

i32 Actor::calcDistanceToPlayerWrap(i32, i32, i32, i32) {

}

i32 Actor::getDistanceToPlayer(i32 x, i32 y) {
    //(*data_ov000_020ca858)()
}

void Actor::setCalcPositionToPlayerFunction(u32 param_1)
{
    data_ov000_020ca858 = data_ov000_020c6c14[param_1];
}

void Actor::wrapPosition(u32 param_1,u32 param_2,u32 param_3)
{  
    (*data_02039968)(param_1,param_3);
}

bool(*data_ov000_020ca854)(i32, i32);
bool(*data_ov000_020c6c20[3])(i32, i32) = {
    Actor::isBehindTargetNoWrap,
    Actor::isBehindTargetWrap,
    Actor::isBehindTargetWrap,
};

void Actor::setWrapPositionFunction() {
    func_020067dc();
}


bool Actor::isBehindTarget(Actor* other) {
    return (*data_ov000_020ca854)(
        this->position.x + this->centerOffset.x,
        other->position.x + other->centerOffset.x
    );
}

bool Actor::isInFrontOfTarget(Actor* other) {
    return (*data_ov000_020ca854)(
        other->position.x + other->centerOffset.x,
        this->position.x + this->centerOffset.x
    );
}

//bool Actor::

bool Actor::isBehindTargetNoWrap(i32 param_1,i32 param_2)
{
  return param_1 < param_2;
}

bool Actor::isBehindTargetWrap(i32 this_, i32 other) {
    i32 iVar1 = (this_ & data_02085aa4) - (other & data_02085aa4);
    i32 iVar2 = (data_02085aa4 + 1) / 2;
    if (iVar1 < 0) {
        return -iVar1 >= iVar2;
    } else {
        return iVar1 > iVar2;
    }
}

void Actor::setIsBehindTargetFunction(u32 a) {
    data_ov000_020ca854 = data_ov000_020c6c20[a];
}

void Actor::initWrapFunctions(u32 a) {
    Actor::setWrapPositionFunction();
    Actor::setCalcPositionToPlayerFunction(a);
    Actor::setIsBehindTargetFunction(a);
}

//bool ()