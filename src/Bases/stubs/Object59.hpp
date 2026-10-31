#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 59  |  ov066  |  profile @ 0x02178948
class Object59 : public StageEntity {
public:
	u8 _pad0[0x20];

	static void *create();
	inline Object59() {};
	inline ~Object59() {};

	void func_ov066_02175b64();
};

extern ActorProfile Object59_Profile;

