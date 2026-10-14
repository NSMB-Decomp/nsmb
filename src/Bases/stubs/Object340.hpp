#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 340  |  ov128  |  profile @ 0x020ff76c
class Object340 : public StageEntity {
public:
	static void *create();
	inline Object340() {};
	inline ~Object340() {};
};

extern ObjectProfile Object340_Profile;

