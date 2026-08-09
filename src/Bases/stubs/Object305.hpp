#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 305  |  ov009  |  profile @ 0x020dabb4
class Object305 : public StageEntity {
public:
	static void *create();
	inline Object305() {};
	inline ~Object305() {};
};

extern ActorProfile Object305_Profile;

