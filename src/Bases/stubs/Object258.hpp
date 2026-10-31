#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 258  |  ov098  |  profile @ 0x021895d4
class Object258 : public StageEntity {
public:
	static void *create();
	inline Object258() {};
	inline ~Object258() {};

	void func_ov098_02187120();
	void func_ov098_02187144();
	void func_ov098_021871f4();
};

extern ActorProfile Object258_Profile;

