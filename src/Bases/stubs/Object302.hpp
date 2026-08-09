#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 302  |  ov054  |  profile @ 0x02170084
class Object302 : public StageEntity {
public:
	static void *create();
	inline Object302() {};
	inline ~Object302() {};
};

extern ActorProfile Object302_Profile;

