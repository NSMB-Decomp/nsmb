#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 6  |  ov052  |  profile @ 0x0215bdec
class Object6 : public StageEntity {
public:
	static void *create();
	inline Object6() {};
	inline ~Object6() {};
};

extern ActorProfile Object6_Profile;

