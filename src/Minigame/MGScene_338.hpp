#pragma once
#include "MGDebugScene.hpp"

class MGScene_338 : public MGDebugScene
{
      public:
	static ObjectProfile profile;

	inline ~MGScene_338() {};
	inline MGScene_338() {};
	static void *create();

	s32 onCreate();
	s32 onDestroy();
	void virt_18();
	char *virt_19(u32);
	void virt_20(u32);
};
