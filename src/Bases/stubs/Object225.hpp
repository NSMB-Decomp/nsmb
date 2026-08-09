#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 225  |  ov086  |  profile @ 0x0217ec88
class Object225 : public StageEntity {
public:
	static void *create();
	inline Object225() {};
	inline ~Object225() {};
};

extern ActorProfile Object225_Profile;

