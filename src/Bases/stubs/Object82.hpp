#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 82  |  ov111  |  profile @ 0x0218a518
class Object82 : public StageEntity {
public:
	static void *create();
	inline Object82() {};
	inline ~Object82() {};

	void func_ov111_02189df8();
	void func_ov111_02189e98();
	void func_ov111_0218a124();
};

extern ActorProfile Object82_Profile;

