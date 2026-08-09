#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 313  |  ov009  |  profile @ 0x020db134
class Object313 : public StageEntity {
public:
	static void *create();
	inline Object313() {};
	inline ~Object313() {};
};

extern ActorProfile Object313_Profile;

