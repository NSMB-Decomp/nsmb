#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 72  |  ov054  |  profile @ 0x0217067c
class Object72 : public StageEntity {
public:
	static void *create();
	inline Object72() {};
	inline ~Object72() {};
};

extern ActorProfile Object72_Profile;

