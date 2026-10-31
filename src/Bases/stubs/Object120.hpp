#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 120  |  ov108  |  profile @ 0x0218aef0
class Object120 : public StageEntity {
public:
	static void *create();
	inline Object120() {};
	inline ~Object120() {};

	void func_ov108_02189de0();
	void func_ov108_02189ec0();
	void func_ov108_0218a150();
	void func_ov108_0218a278();
	void func_ov108_0218a524();
	void func_ov108_0218a5ec();
};

extern ActorProfile Object120_Profile;

