#include "Scene.hpp"

class MPLevelSelectScene : public Scene
{
      public:
	u8 _pad0[0xc8];
	Vec2_32 _12c;
	Vec2_32 _138;
    u32 _pad1;

	MPLevelSelectScene();
	inline ~MPLevelSelectScene();
	void *create();

	bool onCreate();
	bool onDestroy();
	bool onUpdate();
	bool onRender();
};
