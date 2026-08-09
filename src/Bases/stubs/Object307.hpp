#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"
#include "../../graphics/3d/model.hpp"

// MainProfileTable slot 307  |  ov009  |  profile @ 0x020dacdc
class Object307 : public Actor {
public:
	Model model;
	u8 _pad[0x18];
	static void *create();
	inline Object307() {};
	inline ~Object307() {};
};

extern ActorProfile Object307_Profile;

