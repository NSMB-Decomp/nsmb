#include "Scene.hpp"

class ConnectScene : public Scene
{
      public:
    u8 _pad[0xa4];

	inline ConnectScene();
	inline ~ConnectScene();
	void *create();

	s32 onCreate();
	s32 onDestroy();
	s32 onUpdate();
	s32 onRender();
};
