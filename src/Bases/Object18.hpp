#include "_StageController.hpp"

class Object18 : public StageController
{
      public:
	u8 _pad0[0x4c];
	Object18() {};
	~Object18();

	s32 onCreate();
	s32 onDestroy();
	s32 onUpdate();
	s32 onRender();
	void pendingDestroy();

	static void *create();
};