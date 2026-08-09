#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 284  |  ov010  |  profile @ 0x02124920
class Object284 : public StageEntity {
public:
	static void *create();
	inline Object284() {};
	inline ~Object284() {};
};

extern ActorProfile Object284_Profile;

