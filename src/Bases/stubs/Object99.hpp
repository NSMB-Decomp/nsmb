#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 99  |  ov081  |  profile @ 0x0217b714
class Object99 : public StageEntity {
public:
	static void *create();
	inline Object99() {};
	inline ~Object99() {};
};

extern ActorProfile Object99_Profile;

