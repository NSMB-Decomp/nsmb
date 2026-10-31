#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 237  |  ov054  |  profile @ 0x0216d154
class Object237 : public StageEntity {
public:
	static void *create();
	inline Object237() {};
	inline ~Object237() {};

	void func_ov054_02155520();
	void func_ov054_021556c4();
};

extern ActorProfile Object237_Profile;

