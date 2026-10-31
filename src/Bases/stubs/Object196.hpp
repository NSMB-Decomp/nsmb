#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 196  |  ov107  |  profile @ 0x0218a870
class Object196 : public StageEntity {
public:
	static void *create();
	inline Object196() {};
	inline ~Object196() {};

	void func_ov107_02189d84();
	void func_ov107_02189fe4();
};

extern ActorProfile Object196_Profile;

