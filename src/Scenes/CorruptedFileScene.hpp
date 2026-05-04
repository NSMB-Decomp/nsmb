#include "Scene.hpp"

class CorruptedFileScene : public Scene
{
      public:
	u32 _64;
    u8 _pad0[0x7a];
	u32 _e4;
    u8 _pad1[0xa];
	u32 _f4;
    
	CorruptedFileScene();
	inline ~CorruptedFileScene();
	void *create();

	bool onCreate();
	bool onDestroy();
	bool onUpdate();
	bool onRender();
	void pendingDestroy();
};
