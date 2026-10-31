#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 231  |  ov097  |  profile @ 0x02188830
class Object231 : public StageEntity {
public:
	static void *create();
	inline Object231() {};
	inline ~Object231() {};

	void func_ov097_0218585c();
	void func_ov097_021859b8();
	void func_ov097_021859bc();
	void func_ov097_02185a08();
	void func_ov097_02185a0c();
	void func_ov097_02185b24();
	void func_ov097_02185b28();
	void func_ov097_02185b74();
};

extern ActorProfile Object231_Profile;

