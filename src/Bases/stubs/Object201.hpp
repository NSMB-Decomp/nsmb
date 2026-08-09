#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 201  |  ov060  |  profile @ 0x021734e0
class Object201 : public StageEntity {
public:
	static void *create();
	inline Object201() {};
	inline ~Object201() {};
};

extern ActorProfile Object201_Profile;

