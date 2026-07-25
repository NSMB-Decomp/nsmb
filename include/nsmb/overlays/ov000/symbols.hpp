#pragma once

#include "../../../../src/Vec.hpp"

class CollisionMgr;
class Actor;
class ActiveCollider;
class PlayerBase;
class StageEntity;
struct ObjectInfo;
struct StageRuntimeEntry;

class StageLayout {
      public:
	void changeTile(u32 x, u32 y, u32 tile, u32 layer);
};

struct Unk020ca4ccEntry {
	u32 unk0;
	u32 unk4;
	u16 unk8;
	u16 padding;
};
NTR_SIZE_GUARD(Unk020ca4ccEntry, 0xc);

struct Unk020ca32cEntry {
	u32 value;
	u8 padding04[0xc];
};
NTR_SIZE_GUARD(Unk020ca32cEntry, 0x10);
NTR_OFFSET_GUARD(Unk020ca32cEntry, value, 0x0);

struct StageEntityTileSweep {
	i32 checkX;
	i32 checkY;
	i32 left;
	i32 right;
	i32 top;
	i32 bottom;
	i32 horizontalDirection;
	i32 verticalDirection;
};
NTR_SIZE_GUARD(StageEntityTileSweep, 0x20);
NTR_OFFSET_GUARD(StageEntityTileSweep, checkX, 0x0);
NTR_OFFSET_GUARD(StageEntityTileSweep, checkY, 0x4);
NTR_OFFSET_GUARD(StageEntityTileSweep, left, 0x8);
NTR_OFFSET_GUARD(StageEntityTileSweep, right, 0xc);
NTR_OFFSET_GUARD(StageEntityTileSweep, top, 0x10);
NTR_OFFSET_GUARD(StageEntityTileSweep, bottom, 0x14);
NTR_OFFSET_GUARD(StageEntityTileSweep, horizontalDirection, 0x18);
NTR_OFFSET_GUARD(StageEntityTileSweep, verticalDirection, 0x1c);

union StageObjectEventIDs {
	u16 value;
	u8 ids[2];
};
NTR_SIZE_GUARD(StageObjectEventIDs, 0x2);

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
void func_ov000_0209aff8(u8 playerID, bool mode);
void func_ov000_0209b040(u8 playerID);
void func_ov000_0209b320(u8 playerID);
void func_ov000_0209b688(u8 playerID);
void func_ov000_0209b764();
void func_ov000_0209b7e8(u32 playerID);
void func_ov000_0209ba94(
	StageEntityTileSweep *sweep, u32 playerID, bool moving);
bool func_ov000_0209bddc(
	const StageRuntimeEntry *entry, const ObjectInfo *objectInfo,
	u32 playerID);
StageEntity *func_ov000_0209bf10(
	StageRuntimeEntry *entry, const ObjectInfo *objectInfo,
	u8 *spawnFlags, u16 *spawnTimer, u8 viewID, u32 playerID);
StageEntity *func_ov000_0209c178(
	u32 spriteID, u32 settings, Vec3_32 *position);
void func_ov000_0209c288();
void func_ov000_0209c2f8(u8 playerID);
void func_ov000_0209c350();
extern "C" PlayerBase *func_ov000_020a3d68(ActiveCollider *);
extern "C" Vec3_32 func_02045bdc(
	const Vec3_32 &left, const Vec3_32s &right);

extern u8 data_ov000_020c4ec0[2];
extern i16 data_ov000_020c4ed4[2];
extern i16 data_ov000_020c4ed0[2];
extern u16 data_ov000_020c4ee0[];
extern const i16 data_ov000_020c1f40[2];
extern const fx32 data_ov000_020c1f9c[3];
extern const u32 data_ov000_020c1ff0[8];
extern StageObjectEventIDs data_ov000_020ca2a4;
extern u8 *data_ov000_020ca2ac;
extern u64 data_ov000_020ca2cc;
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
extern u32 data_ov000_020ca2dc[2];
extern u32 data_ov000_020ca2e4[2];
extern u32 data_ov000_020ca2ec[2];
extern u32 data_ov000_020ca2f4[2];
extern u8 data_ov000_020ca280;
extern u8 data_ov000_020ca288;
extern u8 data_ov000_020ca294;
extern i8 data_ov000_020ca298;
extern u8 data_ov000_020ca29c;
extern u8 data_ov000_020ca2a0;
extern u16 data_ov000_020ca2a8;
extern u32 data_ov000_020ca2b0;
extern u32 data_ov000_020ca2b4;
extern u32 data_ov000_020ca2b8;
extern u8 data_ov000_020ca2d4[8];
extern u16 data_ov000_020ca2fc[24];
extern Unk020ca32cEntry data_ov000_020ca32c[10];
extern i32 data_ov000_020cada4[2];
extern i32 data_ov000_020cadb4[2];
extern i32 data_ov000_020cae1c[2];
extern u16 data_ov000_020c22b8[];
extern ObjectInfo data_ov000_020c529c[];
extern u8 data_ov000_020ca3cc[];
extern Unk020ca4ccEntry data_ov000_020ca4cc[32];
extern u16 data_ov000_020ca64c[];
extern u8 data_ov000_020c1fb8[];
extern u16 data_ov000_020c1f48[2];
extern u16 data_ov000_020c1f4c[2];
extern u32 data_ov000_020c1f68[2];
extern i8 data_ov000_020c1f78[];
extern i8 data_ov000_020c1f84[];
extern i8 data_ov000_020c1f90[];
extern i32 data_ov000_020c1fd8[];
extern u32 data_ov000_020c2050[];
extern u32 data_ov000_020c2078[];
extern u32 data_ov000_020c20c8[];
extern const fx32 data_ov000_020c20a0[2][5];
