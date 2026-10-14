#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 210  |  ov118  |  profile @ 0x0218feec
class Object210 : public StageEntity {
public:
	static void *create();
	inline Object210() {};
	inline ~Object210() {};
};

extern ActorProfile Object210_Profile;

