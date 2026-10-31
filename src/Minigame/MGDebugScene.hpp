#pragma once
#include "MGScene.hpp"

class MGDebugScene : public MGScene
{
      public:
	u8 _pad5c[0x8];
	s32 _64;
	s32 _68;
	s32 _6c;
	s16 _70;
	s16 _72;
	s16 _74;
	s16 _76;
	s16 _78;
	s16 _7a;

	inline ~MGDebugScene() {};
	inline MGDebugScene() {};

	bool preCreate();
	bool preUpdate();

	void func_ov130_02126c7c();
	void func_ov130_02126fc8();
	bool func_ov130_02127050();
	bool func_ov130_02127110();
	void func_ov130_021271d0();

	virtual void virt_18() = 0;
	virtual char *virt_19(u32) = 0;
	virtual void virt_20(u32) = 0;
};
