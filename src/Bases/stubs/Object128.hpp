#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 128  |  ov016  |  profile @ 0x02133a88
class Object128 : public StageEntity {
public:
	static void *create();
	inline Object128() {};
	inline ~Object128() {};

	void func_ov016_02130434();
	void func_ov016_02130840();
	void func_ov016_02130a1c();
	void func_ov016_02130c44();
	void func_ov016_02130d0c();
	void func_ov016_02130eb8();
	void func_ov016_02130ff4();
	void func_ov016_02131128();
	void func_ov016_02131258();
	void func_ov016_0213131c();
	void func_ov016_02131560();
	void func_ov016_0213173c();
	void func_ov016_0213198c();
	void func_ov016_02131b38();
	void func_ov016_02131e70();
	void func_ov016_02131f74();
	void func_ov016_021320d8();
};

extern ActorProfile Object128_Profile;

