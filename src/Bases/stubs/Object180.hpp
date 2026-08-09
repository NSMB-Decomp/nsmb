#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 180  |  ov100  |  profile @ 0x021893f8
class Object180 : public StageEntity {
public:
	static void *create();
	inline Object180() {};
	inline ~Object180() {};
};

extern ActorProfile Object180_Profile;

