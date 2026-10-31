#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 79  |  ov047  |  profile @ 0x02148284
class Object79 : public StageEntity {
public:
	static void *create();
	inline Object79() {};
	inline ~Object79() {};

	void func_ov047_02147488();
	void func_ov047_02147840();
	void func_ov047_021478a0();
	void func_ov047_0214793c();
};

extern ActorProfile Object79_Profile;

