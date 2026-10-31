#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 124  |  ov110  |  profile @ 0x0218a800
class Object124 : public StageEntity {
public:
	static void *create();
	inline Object124() {};
	inline ~Object124() {};

	void func_ov110_02189de0();
	void func_ov110_02189e78();
	void func_ov110_02189efc();
	void func_ov110_02189f90();
};

extern ActorProfile Object124_Profile;

