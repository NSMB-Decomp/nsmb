#include "StageActor.hpp"
#include "Player/PlayerActor.hpp"

StageActor::StageActor()
{
    this->collision_manager.__1 = &this->platform_manager;
    this->platform_manager.init(this, NULL);
    this->platform_manager.__1 = &this->collision_manager;
    this->_2bc = 0;
    this->_2bf = 0;
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

PlayerActor *GAME_getPlayer(i32);
bool StageActor::isInActiveView()
{
    for (i32 i = 0; i < 2; ++i)
    {
        PlayerActor *player = GAME_getPlayer(i);
        if (player != NULL)
        {
            if (player->_2be == this->_2be)
                return true;
        }
    }

    return false;
}