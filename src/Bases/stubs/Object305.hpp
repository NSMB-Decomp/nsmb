#pragma once
#include "../Actor.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 305  |  ov009  |  profile @ 0x020dabb4
class Object305 : public Actor {
public:
	u8 _120;
	u8 _121;
	u8 _pad0[0x3a];
	static void *create();
	Object305();
	inline ~Object305() {};
};

extern ActorProfile Object305_Profile;

