#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 260  |  ov054  |  profile @ 0x0216dec4
class Object260 : public StageEntity {
public:
	static void *create();
	inline Object260() {};
	inline ~Object260() {};
};

extern ActorProfile Object260_Profile;

