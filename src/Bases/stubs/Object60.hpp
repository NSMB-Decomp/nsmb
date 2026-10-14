#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 60  |  ov025  |  profile @ 0x021416b0
class Object60 : public StageEntity {
public:
	static void *create();
	inline Object60() {};
	inline ~Object60() {};
};

extern ActorProfile Object60_Profile;

