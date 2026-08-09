#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 216  |  ov120  |  profile @ 0x0218dec8
class Object216 : public StageEntity {
public:
	static void *create();
	inline Object216() {};
	inline ~Object216() {};
};

extern ActorProfile Object216_Profile;

