#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 134  |  ov123  |  profile @ 0x0218f3e8
class Object134 : public StageEntity {
public:
	static void *create();
	inline Object134() {};
	inline ~Object134() {};

	void func_ov123_0218cb5c();
	void func_ov123_0218cbbc();
	void func_ov123_0218cc5c();
	void func_ov123_0218cca4();
	void func_ov123_0218cd00();
	void func_ov123_0218cec8();
	void func_ov123_0218cfa4();
	void func_ov123_0218d028();
	void func_ov123_0218d180();
};

extern ActorProfile Object134_Profile;

