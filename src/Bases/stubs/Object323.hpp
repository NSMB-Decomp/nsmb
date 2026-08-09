#pragma once
#include "../Base.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 323  |  ov009  |  profile @ 0x020daadc
class Object323 : public Base {
public:
	static void *create();
	inline Object323() {};
	inline ~Object323() {};
};

extern ActorProfile Object323_Profile;

