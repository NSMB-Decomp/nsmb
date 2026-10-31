#pragma once
#include "Scene.hpp"
#include "../AAA.hpp"

// MainProfileTable slot 17  |  ov007  |  profile @ 0x020cc620
class KeyScene : public Scene {
public:
	s32 _64;
	s32 _68[6];
	static void *create();

	inline KeyScene() {};
	inline ~KeyScene() {};

	s32 onCreate();
	s32 onDestroy();
	s32 onUpdate();
	s32 onRender();
	void pendingDestroy();
};

extern ObjectProfile Object17_Profile;
