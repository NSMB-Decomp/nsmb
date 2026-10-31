#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 58  |  ov042  |  profile @ 0x02151c38
class Object58 : public StageEntity {
public:
	u8 _pad0[0x1c];

	static void *create();
	inline Object58() {};
	inline ~Object58() {};

	void func_ov042_02146e48();
	void func_ov042_02146f7c();
	void func_ov042_021470b0();
};

extern ActorProfile Object58_Profile;

