#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 192  |  ov049  |  profile @ 0x02147ff0
class Object192 : public StageEntity {
public:
	static void *create();
	inline Object192() {};
	inline ~Object192() {};
};

extern ActorProfile Object192_Profile;

