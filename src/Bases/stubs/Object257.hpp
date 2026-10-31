#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 257  |  ov054  |  profile @ 0x0216d744
class Object257 : public StageEntity {
public:
	static void *create();
	inline Object257() {};
	inline ~Object257() {};

	void func_ov054_02157e38();
	void func_ov054_02157fc4();
	void func_ov054_02158150();
};

extern ActorProfile Object257_Profile;

