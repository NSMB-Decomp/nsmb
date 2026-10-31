#pragma once
#include "MGDebugScene.hpp"

class MGDebugMenuScene : public MGDebugScene
{
      public:
	inline MGDebugMenuScene() {};
	inline ~MGDebugMenuScene() {};
	static void *create();
	void virt_18();
	char *virt_19(u32);
	void virt_20(u32);
};
