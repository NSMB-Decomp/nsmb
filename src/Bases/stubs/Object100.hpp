#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 100  |  ov081  |  profile @ 0x0217b708
class Object100 : public StageEntity {
public:
	static void *create();
	inline Object100() {};
	inline ~Object100() {};
};

extern ActorProfile Object100_Profile;

