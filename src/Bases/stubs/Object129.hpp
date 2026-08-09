#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 129  |  ov017  |  profile @ 0x02133bd0
class Object129 : public StageEntity {
public:
	static void *create();
	inline Object129() {};
	inline ~Object129() {};
};

extern ActorProfile Object129_Profile;

