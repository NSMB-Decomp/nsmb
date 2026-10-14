#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 220  |  ov120  |  profile @ 0x0218de98
class Object220 : public StageEntity {
public:
	static void *create();
	inline Object220() {};
	inline ~Object220() {};
};

extern ActorProfile Object220_Profile;

