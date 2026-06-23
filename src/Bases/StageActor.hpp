#pragma once
#include "Actor.hpp"
#include "../Collision/activecollider.hpp"
#include "../Collision/collisionmgr.hpp"
#include "../Collision/platform.hpp"

class StageActor : public Actor
{
      public:
	ActiveCollider activeCollider;
	CollisionMgr collisionMgr;
	PlatformMgr platformMgr;
	u8 _2bc;      /* 0x2BC */
	u8 direction; /* 0x2BD */
	u8 _2be;      /* 0x2BE */
	u8 _2bf;      /* 0x2BF */
	u32 empty;    /* TODO: what does empty mean? */

	StageActor();
	~StageActor();

	bool preUpdate();
	void postUpdate(u32);
	bool isInActiveView();
	void func_ov000_0209ab90(u32, u32, u32, i8);
};
