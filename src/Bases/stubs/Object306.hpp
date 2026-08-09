#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 306  |  ov009  |  profile @ 0x020dac58
class Object306 : public StageEntity {
public:
	static void *create();
	inline Object306() {};
	inline ~Object306() {};
};

extern ActorProfile Object306_Profile;

