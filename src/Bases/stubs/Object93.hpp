#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 93  |  ov040  |  profile @ 0x021469b0
class Object93 : public StageEntity {
public:
	static void *create();
	inline Object93() {};
	inline ~Object93() {};

	void func_ov040_021455f0();
	void func_ov040_0214560c();
	void func_ov040_02145dec();
};

extern ActorProfile Object93_Profile;

