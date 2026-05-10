#include "Scene.hpp"

class Unknwon {
	public:
	Unknwon();
	~Unknwon();
};

class MPLevelSelectScene : public Scene
{
      public:
	u8 _pad0[0x8];
	u32 _6c;
	u32 _70;
	Unknwon a;
	u8 _pad1[0xb4];
	Vec2_32 _12c;
	Vec2_32 _138;
    u32 _pad3;

	MPLevelSelectScene();
	MPLevelSelectScene(u32);
	~MPLevelSelectScene();
	void func_ov052_02155cf8();
	void func_ov052_02155c9c();
	void *create();

	bool onCreate();
	bool onDestroy();
	bool onUpdate();
	bool onRender();
};
