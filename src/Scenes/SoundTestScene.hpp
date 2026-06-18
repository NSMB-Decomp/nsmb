#include "Scene.hpp"

class SoundTestScene : public Scene
{
      public:
	u32 _64;
	u32 _68;
	u32 _6c;

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

ObjectProfile SoundTestScene::Profile = {SoundTestScene::create, 0x10, 0x17};
