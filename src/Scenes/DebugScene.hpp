#include "Scene.hpp"

class DebugScene : public Scene
{
      public:
	u8 _pad0[304];
	u32 _190;
	u32 _194;
	u32 _198;
	u32 _19c;
	u32 _1a0;
	u32 _1a4;
	u32 _1a8;
	u32 _1ac;
	u8 _pad1[16];
	u32 _1c4;
	u32 _1c8;
	u32 _1cc;
	u32 _1d0;
	u32 _1d4;
	u32 _1d8;
	u32 _1dc;
	u32 _1e0;
	u32 _1e4;
	u32 _1e8;
	u32 _1f0;
	u32 _1f4;
	u32 _1f8;
	u32 _1fc;
	u32 _200;
	u32 _204;
	u8 _pad2[0x2c];

	inline DebugScene();
	inline ~DebugScene();
	static void *create();

	void func_ov002_020cc328();
	void func_ov002_020cc514();

	s32 onCreate();
	s32 onDestroy();
	s32 onUpdate();
	s32 onRender();
	void pendingDestroy();
	bool onHeapCreated();
};
