#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 118  |  ov080  |  profile @ 0x0217d968
class Object118 : public StageEntity {
public:
	static void *create();
	inline Object118() {};
	inline ~Object118() {};

	void func_ov080_0217c2bc();
	void func_ov080_0217c32c();
	void func_ov080_0217c450();
	void func_ov080_0217c5f8();
	void func_ov080_0217c9e4();
	void func_ov080_0217cad0();
	void func_ov080_0217cb80();
};

extern ActorProfile Object118_Profile;

