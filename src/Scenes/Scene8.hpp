#include "Scene.hpp"

class Scene8 : public Scene
{
      public:
	u8 _pad[0x4];

	inline Scene8();
	~Scene8();
	static void *create();

	bool onCreate();
	bool onDestroy();
	bool onUpdate();
	bool onRender();
	void pendingDestroy();
};
