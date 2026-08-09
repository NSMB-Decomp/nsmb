#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 61  |  ov078  |  profile @ 0x0217b4c0
class Object61 : public StageEntity {
public:
	static void *create();
	inline Object61() {};
	inline ~Object61() {};
};

extern ActorProfile Object61_Profile;

