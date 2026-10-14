#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 343  |  ov128  |  profile @ 0x020ffda8
class Object343 : public StageEntity {
public:
	static void *create();
	inline Object343() {};
	inline ~Object343() {};
};

extern ObjectProfile Object343_Profile;

