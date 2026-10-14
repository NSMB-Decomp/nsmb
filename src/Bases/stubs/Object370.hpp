#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 370  |  ov129  |  profile @ 0x0211ab44
class Object370 : public StageEntity {
public:
	static void *create();
	inline Object370() {};
	inline ~Object370() {};
};

extern ObjectProfile Object370_Profile;

