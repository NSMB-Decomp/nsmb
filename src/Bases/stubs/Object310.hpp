#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"
#include "../../graphics/3d/modelanm.hpp"

// MainProfileTable slot 310  |  ov009  |  profile @ 0x020dafd0
class Object310 : public Actor {
public:
	ModelAnm modelanm;
	u8 _pad0[0x11c];
	static void *create();
	Object310();
	inline ~Object310() {};
};

extern ActorProfile Object310_Profile;

