#include "Scene.hpp"

class ConnectScene : public Scene
{
      public:
    u8 _pad[0xa4];
    
	inline ConnectScene();
	inline ~ConnectScene();
	void *create();

	bool onCreate();
	bool onDestroy();
	bool onUpdate();
	bool onRender();
};
