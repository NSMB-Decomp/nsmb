#pragma once

#include "../../../src/nsmb_nitro.hpp"

struct NicknameInfo
{
	u8 data[0x1d];
	u8 valid;
};
NTR_SIZE_GUARD(NicknameInfo, 0x1e);
NTR_OFFSET_GUARD(NicknameInfo, valid, 0x1d);

class PlayerBase;
struct MinigamesSave;

struct PlayerControlState
{
	u16 heldButtons;
	u8 reserved_02_13[0x12];
	u16 pressedButtons;
	u8 reserved_16_17[2];
};

NTR_SIZE_GUARD(PlayerControlState, 0x18);
NTR_OFFSET_GUARD(PlayerControlState, heldButtons, 0x0);
NTR_OFFSET_GUARD(PlayerControlState, pressedButtons, 0x14);

struct StageRuntimeInfo
{
	u8 reserved_00_01[2];
	u16 value02;
	u8 reserved_04_1b[0x18];
	u16 value1C;
	u8 reserved_1e_33[0x16];
	u32 value34;
};
NTR_OFFSET_GUARD(StageRuntimeInfo, value02, 0x2);
NTR_OFFSET_GUARD(StageRuntimeInfo, value1C, 0x1c);
NTR_OFFSET_GUARD(StageRuntimeInfo, value34, 0x34);

struct StageRuntimeEntry
{
	u16 id;
	u16 x;
	u16 y;
	u16 eventIDs;
	u32 settings;
};
NTR_SIZE_GUARD(StageRuntimeEntry, 0xc);
NTR_OFFSET_GUARD(StageRuntimeEntry, id, 0x0);
NTR_OFFSET_GUARD(StageRuntimeEntry, x, 0x2);
NTR_OFFSET_GUARD(StageRuntimeEntry, y, 0x4);
NTR_OFFSET_GUARD(StageRuntimeEntry, eventIDs, 0x6);
NTR_OFFSET_GUARD(StageRuntimeEntry, settings, 0x8);

struct StageRuntimeRoot
{
	StageRuntimeInfo *info;
	u8 reserved_04_17[0x14];
	StageRuntimeEntry *entries;
};
NTR_SIZE_GUARD(StageRuntimeRoot, 0x1c);
NTR_OFFSET_GUARD(StageRuntimeRoot, info, 0x0);
NTR_OFFSET_GUARD(StageRuntimeRoot, entries, 0x18);

struct Unk0201ef94Input
{
	i16 x;
	i16 y;
	i16 width;
	i16 height;
};
NTR_SIZE_GUARD(Unk0201ef94Input, 0x8);
NTR_OFFSET_GUARD(Unk0201ef94Input, x, 0x0);
NTR_OFFSET_GUARD(Unk0201ef94Input, y, 0x2);
NTR_OFFSET_GUARD(Unk0201ef94Input, width, 0x4);
NTR_OFFSET_GUARD(Unk0201ef94Input, height, 0x6);

// Unresolved main-ARM9/autoload data. Keep address names until binary evidence
// supports semantic names; each declaration is authoritative for its address.
extern "C" u8 func_0201ef94(const Unk0201ef94Input *input);
extern u16 data_0203bd2c;
extern u16 data_0203bd34;
extern u8 data_02026ce0[];
extern u8 data_0203267c[];
extern u8 data_02085a58;
extern u8 data_02085a0c;
extern u8 data_02085a20;
extern u32 data_02085a7c;
extern i32 data_02085aa4;
extern u32 data_02085abc;
extern u64 data_0208af3c;
extern u8 data_0208af44[64];
extern i32 data_0208af84[64];
extern u32 data_02085a84;
extern u32 data_02085a9c;
extern u32 data_02085acc;
extern u32 data_02085a8c;
extern u32 data_02085c28;
extern u32 data_0203996c;
extern u32 data_02039678;
extern MinigamesSave data_02088e24;
extern u8 data_02085e30[];
extern u8 data_02086a30[];
extern u8 data_02087630;
extern u8 data_020887f0;
extern u8 data_020887f8;
extern u8 data_02088800;
extern u8 data_02088804;
extern u8 data_0208884c[4];
extern NicknameInfo *data_02088850;
extern u8 data_02088f2c;
extern u8 data_02088f30;
extern u8 data_0208adcc[];
extern u8 data_0208ae54[2];
extern u32 data_0208ae58;
extern StageRuntimeRoot data_0208b168;
extern StageRuntimeEntry *data_0208b1a0[];
extern u32 data_0208b220[];
extern u32 data_0208b2a0[];
extern u8 data_0208b4c4;
extern u8 data_0208b4c8[];
extern u8 data_0208b4c9[];
extern u8 data_0208b4ca[];
extern u8 data_0208b4cb[];
extern u8 data_0208b4e8;
extern u8 data_0208b4ec;
extern u8 data_0208b4f0;
extern u8 data_0208b4f4;
extern PlayerControlState data_020876b2[2];
extern u16 data_0208b344[2];
extern s16 data_0208b350[2];
extern PlayerBase *data_0208b35c[2];
extern u32 data_0208b3d4[2][4];
extern u8 data_02089508[2];
extern void *(*data_0208b690)(u16 fileID);

extern "C" BOOL func_0201301c(void *);
extern "C" void func_02044418(void *object, u16 fileID);
u32 func_0200696c__(u32, u16, u8, u8, u8, u32, u32, u32, u32,
	u8, u8, u8, u8, u8, u8, u8, u32);
u8 func_020204e0(i8 playerID);
void func_02006fac();
bool func_02006fb8();
