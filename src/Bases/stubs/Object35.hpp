#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 35  |  ov042  |  profile @ 0x02152460
class Object35 : public StageEntity {
public:
	static void *create();
	inline Object35() {};
	inline ~Object35() {};
};

extern ActorProfile Object35_Profile;

