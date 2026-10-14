#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 111  |  ov033  |  profile @ 0x021446d0
class Object111 : public StageEntity {
public:
	static void *create();
	inline Object111() {};
	inline ~Object111() {};
};

extern ActorProfile Object111_Profile;

