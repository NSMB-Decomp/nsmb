#include "Scene.hpp"

class BootScene : public Scene
{
      public:
	u8 _pad0[0x14];
	u16 _78;
	u8 _7a;
	u8 _7b;
	u8 _7c;
	u8 _7d;

	inline BootScene();
	inline ~BootScene();
	void *create();

	s32 onCreate();
	s32 onDestroy();
	s32 onUpdate();
	s32 onRender();
	i32 func_ov001_020cc4b4();
	void pendingDestroy();
};
