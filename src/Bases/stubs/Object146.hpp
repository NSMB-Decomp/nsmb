#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 146  |  ov025  |  profile @ 0x02141ce4
class Object146 : public StageEntity {
public:
	static void *create();
	inline Object146() {};
	inline ~Object146() {};
};

extern ActorProfile Object146_Profile;

