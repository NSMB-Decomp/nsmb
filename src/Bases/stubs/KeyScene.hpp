#pragma once
#include "../../Scenes/Scene.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 17  |  ov007  |  profile @ 0x020cc620
class KeyScene : public Scene {
public:
	u8 _pad0[0x1c];
	static void *create();
	inline KeyScene() {};
	~KeyScene();

	virtual s32 onCreate();
	virtual s32 onDestroy();
	virtual s32 onUpdate();
	virtual s32 onRender();
	virtual void pendingDestroy();
};

extern ObjectProfile KeyScene_Profile;

