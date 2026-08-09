#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 87  |  ov054  |  profile @ 0x0216d284
class Object87 : public StageEntity {
public:
	u8 _pad0[0x30];

	static void *create();
	inline Object87() {};
	inline ~Object87() {};
};

extern ActorProfile Object87_Profile;

