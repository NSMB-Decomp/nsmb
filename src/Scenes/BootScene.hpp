#include "Scene.hpp"

class BootScene : public Scene
{
      public:
	u8 _pad0[0x1c];

	inline BootScene();
	~BootScene();
	void *create();

	bool onCreate();
	bool onDestroy();
	bool onUpdate();
	bool onRender();
	void pendingDestroy();
};
