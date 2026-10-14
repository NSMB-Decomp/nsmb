#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 91  |  ov036  |  profile @ 0x02143770
class Object91 : public StageEntity {
public:
	static void *create();
	inline Object91() {};
	inline ~Object91() {};
};

extern ActorProfile Object91_Profile;

