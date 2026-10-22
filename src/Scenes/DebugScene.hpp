#include "Scene.hpp"

class DebugScene : public Scene
{
      public:
	u8 _64[8]; // TODO: What is this actual size?
	u8 _pad0[296];
	u32 _190;
	u32 _194;
	u32 _198;
	u32 _19c;
	s32 _1a0;
	u32 _1a4;
	u32 _1a8;
	s32 _1ac;
	u8 _pad1[16];
	u32 _1c4;
	u32 _1c8;
	u32 _1cc;
	s32 _1d0;
	u32 _1d4;
	u32 _1d8;
	s32 _1dc;
	s32 _1e0;
	s32 _1e4;
	s32 _1e8;
	s32 _1ec;
	u32 _1f0;
	s32 _1f4;
	u32 _1f8;
	s32 _1fc;
	u32 _200;
	s32 _204;
	s32 _208;
	s32 _20c;
	s32 _210;
	s32 _214;
	s32 _218;
	s32 _21c;
	s32 _220;
	s32 _224;
	s32 _228;
	s32 _22c;

	inline DebugScene();
	inline ~DebugScene();
	static void *create();

#if !defined(VER_Y7QJ)
	void func_ov002_020cc328();
	void func_ov002_020cc514();
#endif

	s32 onCreate();
	s32 onDestroy();
	s32 onUpdate();
	s32 onRender();
	void pendingDestroy();
	bool onHeapCreated();
};
