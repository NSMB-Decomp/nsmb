#include "Scene.hpp"

class UnknownClass {
	public:
	u32 _pad0;
	UnknownClass();
	~UnknownClass();

	void func_020144bc(u32, u32, u32);
	void func_020145f8(u32, u32);
};

class CorruptedFileScene : public Scene
{
      public:
	static ObjectProfile Profile;

	UnknownClass _64;
    u8 _pad0[0x7a];
	u32 _e4;
    u8 _pad1[0xa];
	u32 _f4;
    
	CorruptedFileScene();
	inline ~CorruptedFileScene();
	static void *create();

	bool onCreate();
	bool onDestroy();
	bool onUpdate();
	bool onRender();
	void pendingDestroy();

	void func_ov005_020cc77c();
	void func_ov005_020cc75c();
	void func_ov005_020cc664();
	void func_ov005_020cc5bc();
	void func_ov005_020cc4a4();
};

ObjectProfile CorruptedFileScene::Profile = {
	CorruptedFileScene::create,
	0x0b, 
	0x12
};