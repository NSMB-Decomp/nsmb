#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 213  |  ov117  |  profile @ 0x0218e0b0
class Object213 : public StageEntity {
public:
	static void *create();
	inline Object213() {};
	inline ~Object213() {};
};

extern ActorProfile Object213_Profile;

