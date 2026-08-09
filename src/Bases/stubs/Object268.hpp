#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 268  |  ov010  |  profile @ 0x021271dc
class Object268 : public StageEntity {
public:
	u8 _pad0[0x20];

	static void *create();
	inline Object268() {};
	inline ~Object268() {};
};

extern ActorProfile Object268_Profile;

