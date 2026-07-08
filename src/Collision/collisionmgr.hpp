#pragma once
#include "../Bases/Base.hpp"
#include "../Vec.hpp"

class StageActor;

class CollisionMgr
{
      public:
	u8 _pad0[0x1f];
	void *__1;
	u8 _pad1[0x8];
	CollisionMgr *__2;
	u8 _pad2[0x46];
	u32 _rawr;
	u8 _pad3[0xe];
	i8 _25e;
	u8 _pad4[40];
	u8 _b7;

	CollisionMgr();
	~CollisionMgr();

	void func_ov000_020ab9ac();
	void func_ov000_020ab350();
	void func_ov000_020ab010(Base *, void *, void *, void *, u32);
	bool func_ov000_020aa990(u32);
	static u32 getSolidTileType(fx32 x, fx32 y);
	bool func_01ffe778(i32*, u32);
	virtual void _TEMP(); // To make sure size is correct
};
NTR_SIZE_GUARD(CollisionMgr, 0xb8);
