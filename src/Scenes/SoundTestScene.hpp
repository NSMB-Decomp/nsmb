#include "Scene.hpp"

class SoundTestScene : public Scene
{
      public:
	u8 _pad9[8];
	u32 _64;
	u32 _68;
	u32 _6c;

	static ObjectProfile Profile;
	inline SoundTestScene() {};
	inline ~SoundTestScene() {};

	static void *create();

	bool onRender();
	void pendingDestroy();
	bool onCreate();
	bool onDestroy();
	bool onUpdate();
};

ObjectProfile SoundTestScene::Profile = {SoundTestScene::create, 0x10, 0x17};
