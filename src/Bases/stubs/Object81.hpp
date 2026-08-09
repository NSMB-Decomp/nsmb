#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 81  |  ov035  |  profile @ 0x02143af0
class Object81 : public StageEntity {
public:
	static void *create();
	inline Object81() {};
	inline ~Object81() {};
};

extern ActorProfile Object81_Profile;

