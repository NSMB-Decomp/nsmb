#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 360  |  ov129  |  profile @ 0x0211a01c
class Object360 : public StageEntity {
public:
	static void *create();
	inline Object360() {};
	inline ~Object360() {};
};

extern ObjectProfile Object360_Profile;

