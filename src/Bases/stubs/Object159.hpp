#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 159  |  ov054  |  profile @ 0x0216ff58
class Object159 : public StageEntity {
public:
	static void *create();
	inline Object159() {};
	inline ~Object159() {};
};

extern ActorProfile Object159_Profile;

