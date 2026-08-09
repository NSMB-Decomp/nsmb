#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 315  |  ov004  |  profile @ 0x020ccd30
class Object315 : public StageEntity {
public:
	static void *create();
	inline Object315() {};
	inline ~Object315() {};
};

extern ActorProfile Object315_Profile;

