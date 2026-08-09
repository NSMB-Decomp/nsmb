#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 172  |  ov106  |  profile @ 0x0218ad60
class Object172 : public StageEntity {
public:
	static void *create();
	inline Object172() {};
	inline ~Object172() {};
};

extern ActorProfile Object172_Profile;

