#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 91  |  ov036  |  profile @ 0x02143770
class Object91 : public StageEntity {
public:
	static void *create();
	inline Object91() {};
	inline ~Object91() {};

	void func_ov036_02142204();
	void func_ov036_021422c0();
	void func_ov036_02142420();
	void func_ov036_021425bc();
	void func_ov036_02142724();
	void func_ov036_021428fc();
	void func_ov036_02142ae4();
	void func_ov036_02142bd8();
	void func_ov036_02142c74();
	void func_ov036_02142e9c();
};

extern ActorProfile Object91_Profile;

