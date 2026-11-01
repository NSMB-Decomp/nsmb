#include "Scene.hpp"

class BootScene : public Scene
{
      public:
	u32 _64;
	u32 _68;
	u32 _6c;
	u32 _70;
	u32 _74;
	u16 _78;
	u8 step;
	u8 _7b;
	u8 _7c;
	u8 _7d;
	u8 _7e;

	inline BootScene();
	inline ~BootScene();
	void *create();

	s32 onCreate();
	s32 onDestroy();
	s32 onUpdate();
	s32 onRender();
	void func_ov001_020cc328();
	void func_ov001_020cc4b4();
	void pendingDestroy();
};
