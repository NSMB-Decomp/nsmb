#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 318  |  ov008  |  profile @ 0x020e58d0
class Object318 : public StageEntity {
public:
	static void *create();
	inline Object318() {};
	inline ~Object318() {};
};

extern ActorProfile Object318_Profile;

