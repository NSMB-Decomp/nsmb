#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"
#include "../../graphics/3d/modelanm.hpp"

// MainProfileTable slot 312  |  ov009  |  profile @ 0x020db0b0
class Object312 : public Actor {
public:
	ModelAnm model;
	u8 _pad0[0x8];
	static void *create();
	inline Object312() {};
	inline ~Object312() {};
};

extern ActorProfile Object312_Profile;

