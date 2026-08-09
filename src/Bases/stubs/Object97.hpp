#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 97  |  ov017  |  profile @ 0x02133d08
class Object97 : public StageEntity {
public:
	static void *create();
	inline Object97() {};
	inline ~Object97() {};
};

extern ActorProfile Object97_Profile;

