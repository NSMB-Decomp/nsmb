#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 113  |  ov028  |  profile @ 0x021413d0
class Object113 : public StageEntity {
public:
	static void *create();
	inline Object113() {};
	inline ~Object113() {};
};

extern ActorProfile Object113_Profile;

