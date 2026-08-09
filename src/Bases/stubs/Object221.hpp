#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 221  |  ov120  |  profile @ 0x0218de8c
class Object221 : public StageEntity {
public:
	static void *create();
	inline Object221() {};
	inline ~Object221() {};
};

extern ActorProfile Object221_Profile;

