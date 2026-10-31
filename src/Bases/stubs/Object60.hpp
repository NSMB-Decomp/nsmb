#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 60  |  ov025  |  profile @ 0x021416b0
class Object60 : public StageEntity {
public:
	static void *create();
	inline Object60() {};
	inline ~Object60() {};

	void func_ov025_0213c13c();
	void func_ov025_0213cb90();
};

extern ActorProfile Object60_Profile;

