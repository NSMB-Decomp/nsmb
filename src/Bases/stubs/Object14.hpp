#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 14  |  ov004  |  profile @ 0x020cccc0
class Object14 : public StageEntity {
public:
	static void *create();
	inline Object14() {};
	inline ~Object14() {};
};

extern ObjectProfile Object14_Profile;

