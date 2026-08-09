#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 234  |  ov101  |  profile @ 0x02187468
class Object234 : public StageEntity {
public:
	static void *create();
	inline Object234() {};
	inline ~Object234() {};
};

extern ActorProfile Object234_Profile;

