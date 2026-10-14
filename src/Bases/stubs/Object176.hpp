#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 176  |  ov010  |  profile @ 0x02126e2c
class Object176 : public StageEntity {
public:
	static void *create();
	inline Object176() {};
	inline ~Object176() {};
};

extern ActorProfile Object176_Profile;

