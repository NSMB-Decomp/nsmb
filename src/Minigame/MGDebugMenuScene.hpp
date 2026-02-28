#include "MGDebugScene.hpp"

class MGDebugMenuScene : MGDebugScene
{
	u8 _pad[0x8];
	u32 _64;
	u32 _68;

	MGDebugMenuScene();
	~MGDebugMenuScene();
	void virt_18();
	char *virt_19(u32);
	void virt_20(u32);
};
