#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 74  |  ov078  |  profile @ 0x0217b390
class Object74 : public StageEntity {
public:
	static void *create();
	inline Object74() {};
	inline ~Object74() {};

	void func_ov078_02179f74();
	void func_ov078_0217a430();
};

extern ActorProfile Object74_Profile;

