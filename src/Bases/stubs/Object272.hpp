#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slots 272, 273 share this class.
// ov010  |  vtable @ 0x0212480c
class Object272 : public StageEntity {
public:
	static void *create();
	static void *create2();
	inline Object272() {};
	inline ~Object272() {};
};

extern ActorProfile Object273_Profile;
extern ActorProfile Object272_Profile;
