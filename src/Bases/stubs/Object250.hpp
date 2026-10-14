#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 250  |  ov098  |  profile @ 0x02189478
class Object250 : public StageEntity {
public:
	static void *create();
	inline Object250() {};
	inline ~Object250() {};
};

extern ActorProfile Object250_Profile;

