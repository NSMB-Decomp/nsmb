#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slots 285, 286 share this class.
// ov054  |  vtable @ 0x0217040c
class Object285 : public StageEntity {
public:
	static void *create();
	static void *create2();
	inline Object285() {};
	inline ~Object285() {};
};

extern ActorProfile Object286_Profile;
extern ActorProfile Object285_Profile;
