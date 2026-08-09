#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 124  |  ov110  |  profile @ 0x0218a800
class Object124 : public StageEntity {
public:
	static void *create();
	inline Object124() {};
	inline ~Object124() {};
};

extern ActorProfile Object124_Profile;

