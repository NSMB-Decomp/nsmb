#pragma once
#include "StageEntity.hpp"
#include "../graphics/3d/model.hpp"
#include "../graphics/3d/animation.hpp"

class FireSnake : public StageEntity
{
public:
	Model _484;
	Model _514;
	Animation _a0;
	Animation _a1;
	u8 _pad0[8];
	ActiveCollider a[4];
	Vec2_32 _v0[4];
	Vec2_32 _v1[0x40];
	u8 _pad1[0x4];

	static void *create();
	static void *create_unused();
	static bool loadResources();
	inline FireSnake();

	s32 onCreate();
};
ActorProfile FireSnake_Profile = {
    FireSnake::create,
    0x6A,
    0x7A,
    FireSnake::loadResources,
};
ActorProfile FireSnakeUnused_Profile = {
    FireSnake::create_unused,
    0x2E,
    0x3C,
    FireSnake::loadResources,
};
