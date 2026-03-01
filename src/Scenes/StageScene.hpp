#include "Scene.hpp"

class StageScene : public Scene
{
      public:
	Vec3_32 _3f0;
	u8 _pad0[0x63bc];
	static void *create();
	StageScene();
};
