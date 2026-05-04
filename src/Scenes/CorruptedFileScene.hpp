#include "Scene.hpp"

class CorruptedFileScene : public Scene
{
      public:
	u32 a;
    u8 _pad[0x90];
    
	CorruptedFileScene();
	inline ~CorruptedFileScene();
	void *create();

	bool onCreate();
	bool onDestroy();
	bool onUpdate();
	bool onRender();
	void pendingDestroy();
};
