#pragma once
#include "../Actor.hpp"
#include "../../AAA.hpp"
#include "../../graphics/3d/model.hpp"

// MainProfileTable slot 317  |  ov008  |  profile @ 0x020e59a8
class Object317 : public Actor {
public:
	static void *create();
	inline Object317() {};
	inline ~Object317() {};

	BOOL onCreate();
	bool onHeapCreated();
	BOOL onDestroy();
	void pendingDestroy();
	BOOL onRender();
	BOOL onUpdate();

	void func_ov008_020cd520(u32);
	bool func_ov008_020cd478();
	void func_ov008_020cd4ac();
	void func_ov008_020cd664();
	void func_ov008_020cd5e8();

	Model models[8];
	u8 _pad0[0x14];
	u32 _5b4;
	u16 _5b8;
	u8 _5ba;
	u8 _5bb;
};


extern ActorProfile Object317_Profile;

