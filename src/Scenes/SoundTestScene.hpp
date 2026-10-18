#include "Scene.hpp"

class SoundTestScene : public Scene
{
      public:
	u32 _64;
	i32 _68;
	i32 _6c;

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

NTR_SIZE_GUARD(SoundTestScene, 0x70);
NTR_OFFSET_GUARD(SoundTestScene, _68, 0x68);
NTR_OFFSET_GUARD(SoundTestScene, _6c, 0x6c);
