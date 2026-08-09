#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 303  |  ov000  |  profile @ 0x020c9388
class Object303 : public StageEntity {
public:
	static void *create();
	inline Object303() {};
	inline ~Object303() {};
};

extern ActorProfile Object303_Profile;

