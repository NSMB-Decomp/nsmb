#pragma once
#include "../StageEntity.hpp"
#include "../../graphics/3d/modelanm.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 306  |  ov009  |  profile @ 0x020dac58
class Object306 : public Actor {
public:
	ModelAnm _120;
	u8 _pad0[0x1c];
	static void *create();
	inline Object306() {};
	inline ~Object306() {};
};

extern ActorProfile Object306_Profile;

