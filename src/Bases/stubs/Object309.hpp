#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"
#include "../../graphics/3d/modelanm.hpp"

// MainProfileTable slot 309  |  ov009  |  profile @ 0x020daf4c
class Object309 : public Actor {
public:
	ModelAnm model;
	u8 _pad0[0x14];
	static void *create();
	inline Object309() {};
	inline ~Object309() {};

	void func_ov009_020d77a0();
	void func_ov009_020d77bc();
	void func_ov009_020d7858();
	void func_ov009_020d78f0();
	void func_ov009_020d7964();
	void func_ov009_020d79b0();
	void func_ov009_020d7a1c();
	void func_ov009_020d7a68();
	void func_ov009_020d7abc();
};

extern ActorProfile Object309_Profile;

