#include "Scene.hpp"

class BootScene : public Scene
{
      public:
	u8 _pad0[0x1c];

	inline BootScene();
	inline ~BootScene();
	void *create();

	s32 onCreate();
	s32 onDestroy();
	s32 onUpdate();
	s32 onRender();
	void pendingDestroy();
};
