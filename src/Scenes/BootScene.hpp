#include "Scene.hpp"

class BootScene : public Scene
{
      public:
	static ObjectProfile profile;

	u32 _64[5];
	u16 _78;
	u8 _7a;
	u8 _7b;
	u8 _7c;
	u8 _7d;
	u8 _7e;
	u8 _7f;

	inline BootScene();
	inline ~BootScene();
	static void *create();

	s32 onCreate();
	s32 onDestroy();
	s32 onUpdate();
	s32 onRender();
	void func_ov001_020cc328();
	void func_ov001_020cc4b4();
	void pendingDestroy();
};

NTR_SIZE_GUARD(BootScene, 0x80);
NTR_OFFSET_GUARD(BootScene, _64, 0x64);
NTR_OFFSET_GUARD(BootScene, _78, 0x78);
NTR_OFFSET_GUARD(BootScene, _7a, 0x7a);
NTR_OFFSET_GUARD(BootScene, _7b, 0x7b);
NTR_OFFSET_GUARD(BootScene, _7c, 0x7c);
NTR_OFFSET_GUARD(BootScene, _7d, 0x7d);
NTR_OFFSET_GUARD(BootScene, _7e, 0x7e);
