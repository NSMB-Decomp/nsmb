#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 160  |  ov054  |  profile @ 0x0216e2b0
class Object160 : public StageEntity {
public:
	static void *create();
	inline Object160() {};
	inline ~Object160() {};
};

extern ActorProfile Object160_Profile;

