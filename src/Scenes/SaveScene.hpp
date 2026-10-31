#pragma once
#include "Scene.hpp"
#include "../AAA.hpp"

// MainProfileTable slot 7  |  ov008  |  profile @ 0x020e5820
class SaveScene : public Scene {
public:
	u32 _64;
	u32 _68;
	static void *create();

	inline SaveScene() {};
	~SaveScene();

	s32 onCreate();
	s32 onDestroy();
	s32 onUpdate();
	s32 onRender();
	void pendingDestroy();
};

extern ObjectProfile Object7_Profile;
