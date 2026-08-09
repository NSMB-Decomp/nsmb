#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 92  |  ov054  |  profile @ 0x0216d4dc
class Object92 : public StageEntity {
public:
	u8 _pad0[0x1c];

	static void *create();
	inline Object92() {};
	inline ~Object92() {};
};

extern ActorProfile Object92_Profile;

