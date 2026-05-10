#include "Scene.hpp"

class Unknwon {
	public:
	Unknwon();
	~Unknwon();
};

class MPLevelSelectScene : public Scene
{
      public:
	u8 _64;
	u8 _pad0[0x7];
	u32 _6c;
	u32 _70;
	Unknwon a;
	u8 _pad1[0xb4];
	Vec2_32 _12c;
	Vec2_32 _138;
    i16 _pad3;

	MPLevelSelectScene();
	MPLevelSelectScene(u32);
	~MPLevelSelectScene();
	void func_ov052_02155cf8();
	void func_ov052_02155c9c();
	void func_ov052_02155ba8();
	void func_ov052_02155b00();
	u32 func_ov052_02155540();
	bool func_ov052_0215552();
	void func_ov052_02155210();
	void func_ov052_021551e4();
	void func_ov052_0215515c();
	void func_ov052_02154c9c();
	void func_ov052_02154bb4();
	void func_ov052_02154a60();
	void func_ov052_0215476c();
	void func_ov052_021546d0();
	void func_ov052_02154698();
	void func_ov052_0215459c();
	void func_ov052_02155178();
	void func_ov052_02154b64();
	void func_ov052_02154af4();
	void func_ov052_02154a24();
	void func_ov052_0215454c();
	void func_ov052_021544a0();
	void func_ov052_02154c68();
	void func_ov052_02154c34();
	void func_ov052_021549f8();
	void *create();

	bool onCreate();
	bool onDestroy();
	bool onUpdate();
	bool onRender();
	void pendingDestroy();
};

struct T__ {
	u32 a;
	u32 b;
};
struct TTTTTTTTT {
	T__ _[20];
};