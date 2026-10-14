#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 301  |  ov025  |  profile @ 0x02141a50
class Object301 : public StageEntity {
public:
	static void *create();
	inline Object301() {};
	inline ~Object301() {};
};

extern ActorProfile Object301_Profile;

