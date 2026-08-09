#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 304  |  ov052  |  profile @ 0x0215c67c
class Object304 : public StageEntity {
public:
	static void *create();
	inline Object304() {};
	inline ~Object304() {};
};

extern ActorProfile Object304_Profile;

