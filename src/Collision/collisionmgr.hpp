#pragma once
#include "../Bases/Base.hpp"
#include "../Vec.hpp"

class StageActor;

class CollisionManager
{
      public:
	u8 _pad0[0x1f];
	void *__1;
	u8 _pad1[0x8];
	CollisionManager *__2;
	u8 _pad2[0x20];
	Vec3_32 _54;
	Vec2_32 _64;
	Vec2_32 _70;
	u32 _rawr;
	u8 _pad3[0xe];
	s8 _25e;
	u8 _pad4[40];
	u8 _b7;

	CollisionManager();
	~CollisionManager();

	void func_ov000_020ab9ac();
	void func_ov000_020ab350();
	void func_ov000_020ab010(Base *, void *, void *, void *, u32);
	bool func_ov000_020aa990(u32);
	u32 func_ov000_020a917c();
	bool func_ov000_020a6c9c();
	u32 func_ov000_020a7ea8(u8);
	u32 func_ov000_020a8140();
	u32 func_ov000_020a915c(s32 *, u32);
	static u32 getSolidTileType(fx32 x, fx32 y);
	bool func_01ffe778(s32*, u32);
	virtual void _TEMP(); // To make sure size is correct
};
NTR_SIZE_GUARD(CollisionManager, 0xb8);
