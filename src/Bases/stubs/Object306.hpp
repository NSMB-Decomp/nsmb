#pragma once
#include "../StageEntity.hpp"
#include "../../graphics/3d/modelanm.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 306  |  ov009  |  profile @ 0x020dac58
class Object306 : public Actor {
public:
	ModelAnm _120;
	u8 _pad0[0x1c];
	static void *create();
	inline Object306() {};
	inline ~Object306() {};

	void func_ov009_020d5390();
	void func_ov009_020d5424();
	void func_ov009_020d5480();
	void func_ov009_020d5504();
	void func_ov009_020d5578();
	void func_ov009_020d55b0();
	void func_ov009_020d5634();
	void func_ov009_020d570c();
};

extern ActorProfile Object306_Profile;

