#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 202  |  ov010  |  profile @ 0x02127478
class Object202 : public StageEntity {
public:
	static void *create();
	inline Object202() {};
	inline ~Object202() {};
};

extern ActorProfile Object202_Profile;

