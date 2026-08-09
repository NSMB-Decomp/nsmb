#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 15  |  ov052  |  profile @ 0x0215b5c0
class Object15 : public StageEntity {
public:
	static void *create();
	inline Object15() {};
	inline ~Object15() {};
};

extern ObjectProfile Object15_Profile;

