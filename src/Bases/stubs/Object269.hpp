#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 269  |  ov089  |  profile @ 0x0217fcf0
class Object269 : public StageEntity {
public:
	static void *create();
	inline Object269() {};
	inline ~Object269() {};

	void func_ov089_0217f0fc();
	void func_ov089_0217f14c();
	void func_ov089_0217f304();
	void func_ov089_0217f3c4();
	void func_ov089_0217f4f8();
	void func_ov089_0217f5a4();
};

extern ActorProfile Object269_Profile;

