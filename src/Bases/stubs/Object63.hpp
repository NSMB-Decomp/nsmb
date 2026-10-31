#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 63  |  ov080  |  profile @ 0x0217d810
class Object63 : public StageEntity {
public:
	static void *create();
	inline Object63() {};
	inline ~Object63() {};

	void func_ov080_0217bad0();
};

extern ActorProfile Object63_Profile;

