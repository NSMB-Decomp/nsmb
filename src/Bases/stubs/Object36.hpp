#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 36  |  ov012  |  profile @ 0x021320a0
class Object36 : public StageEntity {
public:
	static void *create();
	inline Object36() {};
	inline ~Object36() {};

	void func_ov012_021300bc();
	void func_ov012_02130104();
	void func_ov012_021301e0();
	void func_ov012_0213029c();
};

extern ActorProfile Object36_Profile;

