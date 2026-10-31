#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 57  |  ov048  |  profile @ 0x02148a48
class Object57 : public StageEntity {
public:
	static void *create();
	inline Object57() {};
	inline ~Object57() {};

	void func_ov048_02147fd0();
};

extern ActorProfile Object57_Profile;

