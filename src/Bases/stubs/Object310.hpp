#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 310  |  ov009  |  profile @ 0x020dafd0
class Object310 : public StageEntity {
public:
	static void *create();
	inline Object310() {};
	inline ~Object310() {};
};

extern ActorProfile Object310_Profile;

