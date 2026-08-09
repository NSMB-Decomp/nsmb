#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 314  |  ov008  |  profile @ 0x020ee2c8
class Object314 : public StageEntity {
public:
	static void *create();
	inline Object314() {};
	inline ~Object314() {};
};

extern ActorProfile Object314_Profile;

