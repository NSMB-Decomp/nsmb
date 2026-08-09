#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 312  |  ov009  |  profile @ 0x020db0b0
class Object312 : public StageEntity {
public:
	static void *create();
	inline Object312() {};
	inline ~Object312() {};
};

extern ActorProfile Object312_Profile;

