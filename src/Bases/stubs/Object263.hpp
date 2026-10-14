#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 263  |  ov118  |  profile @ 0x0218fc30
class Object263 : public StageEntity {
public:
	u8 _pad0[0xc];

	static void *create();
	inline Object263() {};
	inline ~Object263() {};
};

extern ActorProfile Object263_Profile;

