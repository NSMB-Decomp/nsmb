#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 69  |  ov054  |  profile @ 0x0216e16c
class Object69 : public StageEntity {
public:
	static void *create();
	inline Object69() {};
	inline ~Object69() {};
};

extern ActorProfile Object69_Profile;

