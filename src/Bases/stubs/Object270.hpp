#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slots 270, 271 share this class.
// ov010  |  vtable @ 0x021246e0
class Object270 : public StageEntity {
public:
	static void *create();
	static void *create2();
	inline Object270() {};
	inline ~Object270() {};
};

extern ActorProfile Object270_Profile;
extern ActorProfile Object271_Profile;
