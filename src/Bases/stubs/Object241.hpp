#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 241  |  ov010  |  profile @ 0x021245a8
class Object241 : public StageEntity {
public:
	static void *create();
	inline Object241() {};
	inline ~Object241() {};
};

extern ActorProfile Object241_Profile;

