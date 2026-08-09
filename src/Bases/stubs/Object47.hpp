#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 47  |  ov100  |  profile @ 0x0218978c
class Object47 : public StageEntity {
public:
	static void *create();
	inline Object47() {};
	inline ~Object47() {};
};

extern ActorProfile Object47_Profile;

