#include "_StageController.hpp"

class Object19 : public StageController
{
      public:
	static ActorProfile Profile;
    u8 _pad0[0x8];
    u16 _1;

	Object19() {};
	~Object19();

	static void *create();

    bool onCreate();
    bool onDestroy();
    bool onUpdate();
    bool onRender();
    void pendingDestroy();
};
ActorProfile Object19::Profile = {
    Object19::create,
    0x13,
    0x1a,
};