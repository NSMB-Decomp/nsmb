#pragma once

#include "../../../src/nsmb_nitro.hpp"

struct NicknameInfo;
class PlayerBase;

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

// Unresolved main-ARM9/autoload data. Keep address names until binary evidence
// supports semantic names; each declaration is authoritative for its address.
extern u16 data_0203bd2c;
extern u16 data_0203bd34;
extern u8 data_02085a58;
extern u8 data_02085a0c;
extern u8 data_02085a20;
extern u32 data_02085a7c;
extern u32 data_02085a84;
extern u32 data_02085a9c;
extern u32 data_02085acc;
extern u32 data_02085a8c;
extern u32 data_02085c28;
extern u8 data_02085e30[];
extern u8 data_02086a30[];
extern u8 data_020887f0;
extern u8 data_02088800;
extern u8 data_02088804;
extern u16 data_0208883c;
extern NicknameInfo *data_02088850;
extern u8 data_02088f30;
extern u8 data_0208adcc[];
extern u8 data_0208ae54[2];
extern u32 data_0208ae58;
extern u8 data_0208b168[];
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
extern u16 data_0208b350[2];
extern PlayerBase *data_0208b35c[2];
extern u32 data_0208b3d4[2][4];
extern u8 data_02089508[2];

extern "C" BOOL func_0201301c(void *);
u32 func_0200696c__(u32, u16, u8, u8, u8, u32, u32, u32, u32,
	u8, u8, u8, u8, u8, u8, u8, u32);
u8 func_020204e0(i8 playerID);
void func_02006fac();
bool func_02006fb8();
