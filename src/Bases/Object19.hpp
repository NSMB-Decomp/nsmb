#include "_StageController.hpp"

class Object19 : public StageController
{
      public:
	static ActorProfile Profile;
    u8 _pad0[0x8];
    u16 _1;

	Object19() {};
	inline ~Object19();

	static void *create();

    s32 onCreate();
    s32 onDestroy();
    s32 onUpdate();
    s32 onRender();
    void pendingDestroy();
};
ActorProfile Object19::Profile = {
    Object19::create,
    0x13,
    0x1a,
};