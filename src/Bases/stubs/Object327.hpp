#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 327  |  arm9  |  profile @ 0x0203d320
class Object327 : public StageEntity {
public:
	static void *create();
	inline Object327() {};
	inline ~Object327() {};
};

extern ObjectProfile Object327_Profile;

