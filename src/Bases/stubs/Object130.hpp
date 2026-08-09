#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 130  |  ov101  |  profile @ 0x021876d8
class Object130 : public StageEntity {
public:
	static void *create();
	inline Object130() {};
	inline ~Object130() {};
};

extern ActorProfile Object130_Profile;

