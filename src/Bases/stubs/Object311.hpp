#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 311  |  ov009  |  profile @ 0x020db04c
class Object311 : public StageEntity {
public:
	static void *create();
	inline Object311() {};
	inline ~Object311() {};
};

extern ActorProfile Object311_Profile;

