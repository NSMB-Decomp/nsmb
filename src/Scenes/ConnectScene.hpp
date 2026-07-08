#include "Scene.hpp"

class Unknown
{
      public:
	Unknown();
};

class ConnectScene : public Scene
{
      public:
	u8 _pad0[0x80]; 
	Unknown _unknwon;
	u8 _pad[0x20];

	inline ConnectScene();
	inline ~ConnectScene();
	void *create();

	s32 onCreate();
	s32 onDestroy();
	s32 onUpdate();
	s32 onRender();
};
NITRO_SIZE_ASSERT(ConnectScene, 0x108);
