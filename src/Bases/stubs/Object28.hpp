#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 28  |  ov025  |  profile @ 0x02141800
class Object28 : public StageEntity {
public:
	static void *create();
	inline Object28() {};
	inline ~Object28() {};

	void func_ov025_0213d98c();
	void func_ov025_0213db80();
	void func_ov025_0213dc38();
	void func_ov025_0213ddf0();
	void func_ov025_0213df5c();
	void func_ov025_0213e398();
};

extern ActorProfile Object28_Profile;

// MainProfileTable slot 30  |  ov025  |  profile @ 0x0214180c
class Object30 : public StageEntity {
public:
	static void *create();
	inline Object30() {};
	inline ~Object30() {};
};

extern ActorProfile Object30_Profile;

