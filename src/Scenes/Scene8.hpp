#include "Scene.hpp"
#include "../Bases/Actor.hpp"

class Scene8 : public Scene
{
      public:
	u8 _pad[0x4];

	inline Scene8();
	inline ~Scene8() {};
	static void *create();

	s32 onCreate();
	s32 onDestroy();
	s32 onUpdate();
	s32 onRender();
	void pendingDestroy();
};

extern ObjectProfile Object8_Profile;
