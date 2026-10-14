#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"
#include "../../graphics/3d/modelanm.hpp"

// MainProfileTable slot 311  |  ov009  |  profile @ 0x020db04c
class Object311 : public Actor {
public:
	Model model;
	u8 _pad0[0x14];
	static void *create();
	inline Object311() {};
	inline ~Object311() {};
};

extern ActorProfile Object311_Profile;

