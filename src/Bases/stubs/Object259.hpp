#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 259  |  ov069  |  profile @ 0x02178438
class Object259 : public StageEntity {
public:
	static void *create();
	inline Object259() {};
	inline ~Object259() {};

	void func_ov069_021762c8();
	void func_ov069_02176424();
	void func_ov069_02176618();
	void func_ov069_021766cc();
	void func_ov069_021767b0();
	void func_ov069_021769ac();
	void func_ov069_02176ad4();
	void func_ov069_02176bd0();
	void func_ov069_02176d0c();
	void func_ov069_02176f84();
	void func_ov069_02177110();
};

extern ActorProfile Object259_Profile;

