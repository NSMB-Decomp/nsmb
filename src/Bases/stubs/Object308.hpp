#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"
#include "../../graphics/3d/model.hpp"

class Object308_Model : public Model { // TODO: Is this in a seperate file?
	public:
	Object308_Model();
};

// MainProfileTable slot 308  |  ov009  |  profile @ 0x020daea0
class Object308 : public Actor {
public:
	Object308_Model model;
	u8 _pad0[0x368];
	static void *create();
	inline Object308() {};
	inline ~Object308() {};

	void func_ov009_020d5e1c();
	void func_ov009_020d5eb0();
	void func_ov009_020d5f14();
	void func_ov009_020d5fa8();
	void func_ov009_020d6014();
	void func_ov009_020d60a4();
	void func_ov009_020d6128();
	void func_ov009_020d6168();
	void func_ov009_020d61b0();
	void func_ov009_020d61e4();
	void func_ov009_020d6218();
	void func_ov009_020d62d0();
	void func_ov009_020d632c();
	void func_ov009_020d6388();
	void func_ov009_020d63e4();
	void func_ov009_020d6434();
	void func_ov009_020d6470();
	void func_ov009_020d65a0();
	void func_ov009_020d6614();
	void func_ov009_020d66b0();
	void func_ov009_020d6724();
	void func_ov009_020d67a8();
	void func_ov009_020d6808();
	void func_ov009_020d6880();
	void func_ov009_020d6904();
	void func_ov009_020d6998();
	void func_ov009_020d6a04();
	void func_ov009_020d6a80();
	void func_ov009_020d6ae0();
	void func_ov009_020d6b58();
	void func_ov009_020d6bb8();
	void func_ov009_020d6c74();
	void func_ov009_020d6cec();
	void func_ov009_020d6d88();
	void func_ov009_020d6e70();
	void func_ov009_020d6f00();
	void func_ov009_020d6f5c();
	void func_ov009_020d6fd0();
	void func_ov009_020d702c();
	void func_ov009_020d70e8();
	void func_ov009_020d71b8();
	void func_ov009_020d7238();
	void func_ov009_020d7298();
	void func_ov009_020d72f8();
};

extern ActorProfile Object308_Profile;

