#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 41  |  ov071  |  profile @ 0x02179378
class Object41 : public StageEntity {
public:
	static void *create();
	inline Object41() {};
	inline ~Object41() {};

	void func_ov071_02176184();
	void func_ov071_02176298();
	void func_ov071_021763ac();
};

extern ActorProfile Object41_Profile;

// MainProfileTable slot 42  |  ov071  |  profile @ 0x02179384
class Object42 : public StageEntity {
public:
	static void *create();
	inline Object42() {};
	inline ~Object42() {};
};

extern ActorProfile Object42_Profile;

