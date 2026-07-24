#pragma once

#include "../../../../src/Vec.hpp"

class CollisionMgr;
class Actor;
class ActiveCollider;
class PlayerBase;

class StageLayout {
      public:
	void changeTile(u32 x, u32 y, u32 tile, u32 layer);
};

namespace Stage {
	extern StageLayout *stageLayout;
}

void func_ov000_020aba48(CollisionMgr *);
void func_ov000_020af844(StageLayout *, u16, u16);
bool func_ov000_020af790(StageLayout *, u16, u16);
void func_ov000_0209e5a8(u32, u32, s32);
extern "C" u32 func_ov000_020a6d18(fx32, fx32);
extern "C" bool func_ov000_020a6c9c(CollisionMgr *);
void func_ov000_020a189c(u32);
void func_ov000_020a183c(u32, u32);
extern "C" PlayerBase *func_ov000_020a3d68(ActiveCollider *);
extern "C" Vec3_32 func_02045bdc(
	const Vec3_32 &left, const Vec3_32s &right);

extern u8 data_ov000_020c4ec0[2];
extern i16 data_ov000_020c4ed4[2];
extern i16 data_ov000_020c4ed0[2];
extern const i16 data_ov000_020c1f40[2];
extern const fx32 data_ov000_020c1f9c[3];
extern u8 *data_ov000_020ca2ac;
extern u8 data_ov000_020ca880;
extern u8 data_ov000_020ca898;
extern u32 data_ov000_020ca8d0;
extern u8 data_ov000_020ca290;
extern Actor *(*data_ov000_020ca858)(i32, i32, i32 *, i32 *);
extern u8 data_ov000_020cacd0[2];
extern u8 data_ov000_020cace0[2];
extern i32 data_ov000_020cae0c[2];
extern i32 data_ov000_020cadac[2];
extern Vec3_32 data_ov000_020caeb8[2];
extern Vec3_32 data_ov000_020caed8[2];
extern u8 data_ov000_020c1fb8[];
extern u16 data_ov000_020c1f48[2];
extern u16 data_ov000_020c1f4c[2];
extern i8 data_ov000_020c1f78[];
extern i8 data_ov000_020c1f84[];
extern i8 data_ov000_020c1f90[];
extern i32 data_ov000_020c1fd8[];
extern u32 data_ov000_020c2050[];
extern u32 data_ov000_020c2078[];
extern u32 data_ov000_020c20c8[];
extern const fx32 data_ov000_020c20a0[2][5];
