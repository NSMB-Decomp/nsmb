#pragma once
#include "Scene.hpp"
#include "../AAA.hpp"

// MainProfileTable slot 7  |  ov008  |  profile @ 0x020e5820
class SaveScene : public Scene {
public:
	u32 _64; // appears to be unused
	s32 index;
	static void *create();

	inline SaveScene() {};
	inline ~SaveScene() {};

	s32 onCreate();
	s32 onDestroy();
	s32 onUpdate();
	s32 onRender();
	void pendingDestroy();
};

extern ObjectProfile Object7_Profile;
