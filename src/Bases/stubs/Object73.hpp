#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 73  |  ov034  |  profile @ 0x02145388
class Object73 : public StageEntity {
public:
	static void *create();
	inline Object73() {};
	inline ~Object73() {};

	void func_ov034_021437f4();
	void func_ov034_021438b4();
	void func_ov034_021439a8();
	void func_ov034_02143ad0();
	void func_ov034_02143c40();
	void func_ov034_02143d08();
	void func_ov034_02143db0();
	void func_ov034_02143f0c();
	void func_ov034_02144030();
	void func_ov034_021441b0();
	void func_ov034_02144278();
	void func_ov034_021443b8();
	void func_ov034_021444b0();
};

extern ActorProfile Object73_Profile;

