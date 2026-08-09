#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 86  |  ov054  |  profile @ 0x0216dd40
class Object86 : public StageEntity {
public:
	static void *create();
	inline Object86() {};
	inline ~Object86() {};
};

extern ActorProfile Object86_Profile;

