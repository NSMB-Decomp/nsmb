#include "Scene.hpp"

class Unknwon2 {
	public:
	u32 a;
	inline Unknwon2() {this->a = 0;};
	~Unknwon2();
};

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
	Unknwon2 b;
	u32 _70;
	Unknwon a;
	u8 _pad1[0xb4];
	Vec2_32 _12c;
	Vec2_32 _138;
    i16 _144;

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

	void func_ov052_02154244();
	void func_ov052_02154238();
	void func_ov052_02154220();
	void func_ov052_02153d5c();
	void func_ov052_02153d14();
	void func_ov052_02153d08();
	void func_ov052_02153b44();
	void func_ov052_02153b38();
	void func_ov052_02153ad0();
	void func_ov052_02153b04();
	void func_ov052_0215422c();
	void func_ov052_02153d2c();
	void func_ov052_02153d20();
	void func_ov052_02153cfc();
	void func_ov052_02153ac4();
	void func_ov052_02153ab8();
	void func_ov052_02153d50();
	void func_ov052_02153d44();
	void func_ov052_02153d38();
	void *create();

	s32 onCreate();
	s32 onDestroy();
	s32 onUpdate();
	s32 onRender();
	void pendingDestroy();
};

struct T__ {
	u32 a;
	u32 b;
};
struct TTTTTTTTT {
	T__ _[20];
};
