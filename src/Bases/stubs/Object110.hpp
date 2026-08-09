#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 110  |  ov068  |  profile @ 0x02179420
class Object110 : public StageEntity {
public:
	static void *create();
	inline Object110() {};
	inline ~Object110() {};
};

extern ActorProfile Object110_Profile;

