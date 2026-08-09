#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 308  |  ov009  |  profile @ 0x020daea0
class Object308 : public StageEntity {
public:
	static void *create();
	inline Object308() {};
	inline ~Object308() {};
};

extern ActorProfile Object308_Profile;

