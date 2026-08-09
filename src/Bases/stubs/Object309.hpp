#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 309  |  ov009  |  profile @ 0x020daf4c
class Object309 : public StageEntity {
public:
	static void *create();
	inline Object309() {};
	inline ~Object309() {};
};

extern ActorProfile Object309_Profile;

