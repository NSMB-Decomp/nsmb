#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slots 274, 275, 283, 284 share this class.
// ov010  |  vtable @ 0x02124950
class Object274 : public StageEntity {
public:
	static void *create();
	static void *create2();
	static void *create3();
	static void *create4();
	inline Object274() {};
	inline ~Object274() {};
};

extern ActorProfile Object284_Profile;
extern ActorProfile Object283_Profile;
extern ActorProfile Object275_Profile;
extern ActorProfile Object274_Profile;
