#include "StageActor.hpp"
#include "Player/PlayerActor.hpp"

StageActor::StageActor()
{
    this->collision_manager.__1 = &this->platform_manager;
    this->platform_manager.init(this, NULL);
    this->platform_manager.__1 = &this->collision_manager;
    this->__1 = 0;
    this->__2 = 0;
}
StageActor::~StageActor()
{
    this->active_collider.delink();
}

void func_ov000_020aba48(CollisionManager *);
void func_0201d794(PlatformManager *);
bool StageActor::preUpdate()
{
    this->empty = false;
    bool a = Actor::preUpdate();
    if (a == false)
    {
        return false;
    }

    if (GlobalFader.isComplete() != 0)
    {
        func_ov000_020aba48(&this->collision_manager);
        func_0201d794(&this->platform_manager);
        this->empty = true;
        return true;
    }

    return false;
}

void StageActor::postUpdate(u32 a)
{
    if (
        ((Stage::actorFreezeFlag & this->actorCategory & 0xff) == 0) &&
        (this->active_collider.resetCollisionState(), !this->pending_destroy))
    {
        this->collision_manager.func_ov000_020ab9ac();
        this->platform_manager.func_0201d730();
    }
    Actor::postUpdate(a);
}

PlayerActor* GAME_getPlayer(u8);
bool StageActor::isInActiveView()
{
    PlayerActor* iVar1;

    u8 i = 0;
    while 
        (
            (iVar1 = GAME_getPlayer(i), iVar1 == NULL) ||
            (iVar1->__4 != this->__4)
        )
    {
        i += 1;
        if (1 < i)
        {
            return false;
        }
    }
    return true;
}