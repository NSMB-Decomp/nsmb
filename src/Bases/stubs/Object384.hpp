#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 384  |  ov129  |  profile @ 0x0211a2ac
class Object384 : public StageEntity {
public:
	static void *create();
	inline Object384() {};
	inline ~Object384() {};
};

extern ObjectProfile Object384_Profile;

