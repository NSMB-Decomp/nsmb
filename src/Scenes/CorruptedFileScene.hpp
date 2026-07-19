#include "Scene.hpp"

class UnknownClass {
	public:
	u32 _pad0;
	UnknownClass();
	~UnknownClass();

	void func_020144bc(u32, u32, u32);
	u32 func_020141c0(u32);
	void func_020145f8(u32, u32);
	void func_020144a8();
	void func_0201443c();
	u32 func_020141b8();
};

class CorruptedFileScene : public Scene
{
      public:
	static ObjectProfile Profile;

	UnknownClass _64;
    u8 _pad0[0x74];
	void* bmg;
    u8 _pad1[0x4];
	u32 _e4;
	i32 _e8;
	u32 _ec;
	u32 _f0;
	u32 _f4;

	CorruptedFileScene();
	~CorruptedFileScene();
	static void *create();

	s32 onCreate();
	s32 onDestroy();
	s32 onUpdate();
	s32 onRender();
	void pendingDestroy();

	void func_ov005_020cc77c();
	void func_ov005_020cc75c();
	void func_ov005_020cc664();
	void func_ov005_020cc5bc();
	void func_ov005_020cc4a4();
	void func_ov005_020cc314();
	void func_ov005_020cc3a4(u32);
	void func_ov005_020cc2e0();
};

ObjectProfile CorruptedFileScene::Profile = {
	CorruptedFileScene::create,
	0x0b,
	0x12
};