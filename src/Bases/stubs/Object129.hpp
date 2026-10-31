#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 129  |  ov017  |  profile @ 0x02133bd0
class Object129 : public StageEntity {
public:
	static void *create();
	inline Object129() {};
	inline ~Object129() {};

	void func_ov017_0212fd14();
	void func_ov017_0213027c();
	void func_ov017_0213040c();
	void func_ov017_021306b4();
	void func_ov017_0213087c();
	void func_ov017_0213093c();
	void func_ov017_02130de0();
	void func_ov017_02131008();
	void func_ov017_02131124();
	void func_ov017_021311e4();
	void func_ov017_021314dc();
	void func_ov017_021315c0();
	void func_ov017_021317dc();
	void func_ov017_021319b0();
};

extern ActorProfile Object129_Profile;

