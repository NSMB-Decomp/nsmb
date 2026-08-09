#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slots 47, 48 share this class.
// ov100  |  vtable @ 0x02189798
class Object47 : public StageEntity {
public:
	static void *create();
	static void *create2();
	inline Object47() {};
	inline ~Object47() {};
};

extern ActorProfile Object48_Profile;
extern ActorProfile Object47_Profile;
