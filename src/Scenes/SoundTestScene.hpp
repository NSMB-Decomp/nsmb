#pragma once
#include "Scene.hpp"

class SoundTestScene : public Scene
{
      public:
	s32 _64;
	s32 _68;
	s32 _6c;

	static ObjectProfile Profile;
	inline SoundTestScene() {};
	inline ~SoundTestScene() {};

	static void *create();

	s32 onRender();
	void pendingDestroy();
	s32 onCreate();
	s32 onDestroy();
	s32 onUpdate();
};
