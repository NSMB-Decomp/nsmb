#include "StageActor.hpp"
#include "Player/PlayerActor.hpp"

StageActor::StageActor()
{
	this->collisionMgr.__1 = &this->platformMgr;
	this->platformMgr.init(this, NULL);
	this->platformMgr.linkedCollisionMgr = &this->collisionMgr;
	this->_2bc = 0;
	this->_2bf = 0;
}
StageActor::~StageActor()
{
	this->activeCollider.unlink();
}

void func_ov000_020aba48(CollisionMgr *);
void func_0201d794(PlatformMgr *);
bool StageActor::preUpdate()
{
	this->empty = false;
	bool a = Actor::preUpdate();
	if (a == false) {
		return false;
	}

	if (GlobalFader.isComplete() != 0) {
		func_ov000_020aba48(&this->collisionMgr);
		func_0201d794(&this->platformMgr);
		this->empty = true;
		return true;
	}

	return false;
}

void StageActor::postUpdate(u32 a)
{
	if (((Stage::actorFreezeFlag & this->actorCategory & 0xff) == 0) && (this->activeCollider.resetCollisionState(), !this->pending_destroy)) {
		this->collisionMgr.func_ov000_020ab9ac();
		this->platformMgr.func_0201d730();
	}
	Actor::postUpdate(a);
}

PlayerActor *GAME_getPlayer(i32);
bool StageActor::isInActiveView()
{
	for (i32 i = 0; i < 2; ++i) {
		PlayerActor *player = GAME_getPlayer(i);
		if (player != NULL) {
			if (player->_2be == this->_2be)
				return true;
		}
	}

	return false;
}
