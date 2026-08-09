#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 7  |  ov008  |  profile @ 0x020e5820
class Object7 : public StageEntity {
public:
	static void *create();
	inline Object7() {};
	inline ~Object7() {};
};

extern ObjectProfile Object7_Profile;

