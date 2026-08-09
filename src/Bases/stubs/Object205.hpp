#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 205  |  ov059  |  profile @ 0x02174990
class Object205 : public StageEntity {
public:
	static void *create();
	inline Object205() {};
	inline ~Object205() {};
};

extern ActorProfile Object205_Profile;

