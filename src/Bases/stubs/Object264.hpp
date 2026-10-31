#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 264  |  ov123  |  profile @ 0x0218f550
class Object264 : public StageEntity {
public:
	static void *create();
	inline Object264() {};
	inline ~Object264() {};

	void func_ov123_0218deb8();
	void func_ov123_0218df24();
	void func_ov123_0218e09c();
	void func_ov123_0218e414();
	void func_ov123_0218e5c8();
	void func_ov123_0218e690();
	void func_ov123_0218e850();
	void func_ov123_0218e8f4();
};

extern ActorProfile Object264_Profile;

