#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 125  |  ov117  |  profile @ 0x0218dee0
class Object125 : public StageEntity {
public:
	u8 _pad0[0x18];

	static void *create();
	inline Object125() {};
	inline ~Object125() {};
};

extern ActorProfile Object125_Profile;

