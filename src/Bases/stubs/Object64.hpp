#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 64  |  ov022  |  profile @ 0x0213c548
class Object64 : public StageEntity {
public:
	u8 _pad0[0x10];

	static void *create();
	inline Object64() {};
	inline ~Object64() {};
};

extern ActorProfile Object64_Profile;

