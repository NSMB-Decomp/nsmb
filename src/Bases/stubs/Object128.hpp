#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 128  |  ov016  |  profile @ 0x02133a88
class Object128 : public StageEntity {
public:
	static void *create();
	inline Object128() {};
	inline ~Object128() {};
};

extern ActorProfile Object128_Profile;

