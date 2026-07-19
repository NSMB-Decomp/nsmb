#include "Scene.hpp"

class Unknown
{
      public:
	Unknown();
	~Unknown();
};

class ConnectScene : public Scene
{
      public:
	u32 _64;
	u8 _pad0[0x7c]; 
	Unknown _unknwon;
	u8 _pad[0x20];

	inline ConnectScene();
	~ConnectScene();
	void *create();

	s32 onCreate();
	s32 onDestroy();
	s32 onUpdate();
	s32 onRender();
	static u32 func_020037e4(u32);
	static void func_020037b4();
	static u32 func_0200379c(u32, u32);
	static u32 func_02003250(u32, u32, u32);
	bool func_020032ac(u32);
	bool func_020032a4();
};
NITRO_SIZE_ASSERT(ConnectScene, 0x108);
