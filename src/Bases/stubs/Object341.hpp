#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 341  |  ov128  |  profile @ 0x020ff560
class Object341 : public StageEntity {
public:
	static void *create();
	inline Object341() {};
	inline ~Object341() {};
};

extern ObjectProfile Object341_Profile;

