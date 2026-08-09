#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 12  |  ov008  |  profile @ 0x020e9b88
class Object12 : public StageEntity {
public:
	static void *create();
	inline Object12() {};
	inline ~Object12() {};
};

extern ObjectProfile Object12_Profile;

