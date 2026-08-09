#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 62  |  ov054  |  profile @ 0x0216d60c
class Object62 : public StageEntity {
public:
	static void *create();
	inline Object62() {};
	inline ~Object62() {};
};

extern ActorProfile Object62_Profile;

