#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 80  |  ov054  |  profile @ 0x0216cec8
class Object80 : public StageEntity {
public:
	static void *create();
	inline Object80() {};
	inline ~Object80() {};

	void func_ov054_02153db4();
	void func_ov054_02153ff8();
	void func_ov054_02154090();
};

extern ActorProfile Object80_Profile;

