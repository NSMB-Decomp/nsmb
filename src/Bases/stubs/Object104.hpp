#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 104  |  ov121  |  profile @ 0x0218e1f0
class Object104 : public StageEntity {
public:
	u8 _pad0[0x4];

	static void *create();
	inline Object104() {};
	inline ~Object104() {};
};

extern ActorProfile Object104_Profile;

