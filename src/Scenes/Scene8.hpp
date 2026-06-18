#include "Scene.hpp"

class Scene8 : public Scene
{
      public:
	u8 _pad[0x4];

	inline Scene8();
	~Scene8();
	static void *create();

	s32 onCreate();
	s32 onDestroy();
	s32 onUpdate();
	s32 onRender();
	void pendingDestroy();
};
