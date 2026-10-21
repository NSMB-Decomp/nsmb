#include "Goomba.hpp"

Goomba::Goomba()
{
}

s32 Goomba::onCreate()
{
}

u32 Goomba::func_ov010_020e127c()
{
}

u32 Goomba::megaDroppedState()
{
    if (this->_45a == 0)
    {
        this->_45a += 1;

        this->accelV = -0x300;

        this->velocity.x = 0;
        this->velocity.y = 0;
        this->velocity.z = 0;

        this->minVelocity.x = 0;
        this->minVelocity.y  = -0x8000;
        this->minVelocity.z  = 0;

        this->_458 = 0;
    }
    else if (this->_45a != -1)
    {
        this->rotation.x += 0x800;

        Actor::updateVerticalVelocity();

        this->StageEntity::func_ov000_0209c85c();

        if (func_020202a0() == 1)
        {
            this->func_ov010_020e19ac();
        }

        this->func_ov010_020e1694();
    }

    return 1;
}

extern u16 data_ov010_021217a0[2];

u32 Goomba::stompedState()
{
    if (this->_45a == 0) {
        this ->_440 = 1;
        this->_442 = 0;
        this->_444 = *data_ov010_021217a0;
        this->_446 = 0;

        this->_45a++;

        this->rotation.y = 0;
        this->_42c = 0x1E;
        this->_3e4 = 1;
        this->activeCollider._28 = 0;
    }
    else if (this->_45a != -1) {
        if (this->_42c == 0) {
            this->activeCollider.unlink(); // replace by delink ?
            this->StageEntity::destroy(true);
        }
        else {
            this->_42c--;
        }

        this->func_ov010_020e1694();
    }

    return 1;
}

bool Goomba::onUpdate_defeated()
{
  this->rotation.x += 0x800;
  Actor::updateVerticalVelocity();
  this->Actor::applyVelocity();
  this->StageEntity::func_ov000_0209c820(-0x300);
  this->func_ov010_020e1694();
  this->StageEntity::destroyInactive(0);
  return true;
}

void Goomba::onStomped()
{
    this->_2c6 |= 0x0FF0;
    this->activeCollider._28 &= -0x403;
    this->activeCollider._2a |= 0x8000;
}

bool Goomba::playerCollision(ActiveCollider* param_2, ActiveCollider* param_3)
{
    PlayerBase* owner = (PlayerBase*)param_3->owner;

    if (owner->actorType != 1)
        return false;

    if (this->_452 != 0 && owner->powerup != 4)
    {
        if (param_3->_24 == 1)
        {
            if (this->StageEntity::func_ov000_0209d240())
                return true;
        }
        else
        {
            if (this->StageEntity::func_ov000_0209d3d0())
                return true;
        }
    }

    return this->StageEntity::playerCollision(param_2, param_3);
}

extern u32 data_02088b94[];

bool Goomba::updateMusicEvents(i32 param_2)
{
    if (this->_428 != 0 && *(i32*)(data_02088b94 + 2) > 0)
    {
        if (param_2 == 0x3000) {
            this->velocity.y = param_2;
            return true;
        }

        if ((this->collisionMgr._rawr & 0x1f40) != 0) {
            this->velocity.y = param_2;
            this->_3ec = 3;
            return true;
        }
    }

    return false;
}

void *Goomba::create()
{
	return new Goomba();
}

void *ParaGoomba::create()
{
	return new ParaGoomba();
}

void *MiniGoomba::create()
{
	return new MiniGoomba();
}

ParaGoomba::~ParaGoomba()
{
}

MiniGoomba::~MiniGoomba()
{
}
