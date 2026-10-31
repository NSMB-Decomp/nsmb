#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 126  |  ov077  |  profile @ 0x0217c684
class Object126 : public StageEntity {
public:
	static void *create();
	inline Object126() {};
	inline ~Object126() {};

	void func_ov077_0217a26c();
	void func_ov077_0217a3d8();
	void func_ov077_0217b078();
	void func_ov077_0217b464();
	void func_ov077_0217b5f4();
	void func_ov077_0217b7c8();
	void func_ov077_0217bcdc();
	void func_ov077_0217be28();
};

extern ActorProfile Object126_Profile;

