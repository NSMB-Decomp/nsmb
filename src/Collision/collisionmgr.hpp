#pragma once
#include "../Bases/Base.hpp"
#include "../Vec.hpp"

class StageActor;

class CollisionMgr
{
      public:
	enum LiquidType {
		LIQUID_NONE = 0,
		LIQUID_WATER = 1,
		LIQUID_LAVA = 2,
		LIQUID_JUNGLE_FOREGROUND = 3,
		LIQUID_POISON = 4
	};

	u8 reserved04[0x14];
	void *sensorOwner;
	u8 reserved1C[0x8];
	void *__1;
	u8 _pad1[0x8];
	CollisionMgr *__2;
	u8 reserved34[0x20];
	Vec3_32 surfaceVector;
	u8 reserved64[0x4];
	i32 sideSensorPosition;
	u8 reserved6C[0x10];
	u32 flags;
	u8 reserved80[0x18];
	u16 bottomSensorType;
	u8 reserved9A[0x17];
	s8 sensorState;
	u8 reservedB2[0x5];
	u8 _b7;

	CollisionMgr();
	~CollisionMgr();

	void func_ov000_020ab9ac();
	void func_ov000_020ab350();
	void func_ov000_020ab010(Base *, void *, void *, void *, u32);
	bool func_ov000_020aa990(u32);
	u32 func_ov000_020a915c(i32 *, u32);
	u32 func_ov000_020a917c();
	u16 func_ov000_020a8140();
	static u32 getSolidTileType(fx32 x, fx32 y);
	static LiquidType getLiquidCollision(fx32 x, fx32 y, fx32 *surfaceY, s32 playerID);
	s16 getGroundAngle(u8 direction) const;
	virtual void _TEMP(); // To make sure size is correct
};
extern "C" bool func_01ffe778(CollisionMgr *, i32 *, u32);
NTR_SIZE_GUARD(CollisionMgr, 0xb8);
NTR_OFFSET_GUARD(CollisionMgr, sensorOwner, 0x18);
NTR_OFFSET_GUARD(CollisionMgr, __1, 0x24);
NTR_OFFSET_GUARD(CollisionMgr, surfaceVector, 0x54);
NTR_OFFSET_GUARD(CollisionMgr, sideSensorPosition, 0x68);
NTR_OFFSET_GUARD(CollisionMgr, flags, 0x7c);
NTR_OFFSET_GUARD(CollisionMgr, bottomSensorType, 0x98);
NTR_OFFSET_GUARD(CollisionMgr, sensorState, 0xb1);
NTR_OFFSET_GUARD(CollisionMgr, _b7, 0xb7);
