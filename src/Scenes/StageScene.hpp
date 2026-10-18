#include "Scene.hpp"
#include "../Vec.hpp"

class StageScene : public Scene
{
      public:
	Vec3_32 _3f0;
	u8 _pad0[0x63bc];
	static void *create();
	static void func_ov000_020a2eec();
	StageScene();
};
