#include "MPLevelSelectScene.hpp"

extern u8 data_ov052_0215c888;
extern u8 data_ov052_0215c884;
extern u8 data_ov052_0215c88c;
extern u8 data_ov052_0215c890;
extern u8 data_ov052_0215c894;
extern u8 data_ov052_0215c898;
extern u8 data_ov052_0215c8a0[];
u32 data_ov052_0215c8ac[2];
u32 data_ov052_0215c8b4[3];
extern u8 data_ov052_0215aee8[];
extern u8 data_ov052_0215c89c;
extern u32 data_ov052_0215af0c[];
extern u8 data_ov052_0215b864[];
extern u8 data_ov052_0215b904[];
extern u8 data_ov052_0215b914[];
extern u8 data_ov052_0215b9d4[];
extern u8 data_ov052_0215ba84[];
extern u8 data_ov052_0215b87c[];
extern u8 data_ov052_0215b85c[];
extern u8 data_ov052_0215b874[];
extern u8 data_ov052_0215bae4[];
extern u8 data_ov052_0215ba54[];
extern u8 data_ov052_0215b964[];
extern u8 data_ov052_0215b86c[];
extern u8 data_ov052_0215b8b4[];
extern u8 data_ov052_0215b8c4[];
extern u8 data_ov052_0215bab4[];
extern u8 data_ov052_0215b924[];
extern u8 data_ov052_0215b8d4[];
extern u8 data_ov052_0215b8f4[];
extern u8 data_ov052_0215b934[];
extern u8 data_ov052_0215b954[];
extern u8 data_ov052_0215b974[];
extern u8 data_ov052_0215b884[];
extern u8 data_ov052_0215b894[];
extern u8 data_ov052_0215b944[];
extern u8 data_ov052_0215b8a4[];
extern u8 data_ov052_0215b8e4[];
extern u8 data_ov052_0215ba34[];
extern u8 data_ov052_0215ba14[];
extern u8 data_ov052_0215b9f4[];
extern u8 data_ov052_0215b994[];
extern u8 data_ov052_0215b9b4[];
extern u8 data_020887f0;
extern u8 data_0208ae54[];
extern u8 data_02085a58;
extern u16 data_0203bd2c;
extern u8 data_0208b4e8;
extern u8 data_0208b4ec;
extern u8 data_0208b4f0;
extern u8 data_0208b4f4;

u32 data_ov052_0215b618[] = { 10, 11 };
u32 data_ov052_0215b628[] = {
	(u32)data_ov052_0215b85c,
	(u32)data_ov052_0215b874,
};
u32 data_ov052_0215b6a0[] = { 16, 17 };
u32 data_ov052_0215b6b0[] = {
	(u32)data_ov052_0215bae4,
	(u32)data_ov052_0215ba54,
};
u32 data_ov052_0215b728[] = {
	(u32)data_ov052_0215b964,
	(u32)data_ov052_0215b86c,
};
u32 data_ov052_0215b788[] = { 12, 13, 14 };
u32 data_ov052_0215b794[] = {
	(u32)data_ov052_0215b8b4,
	(u32)data_ov052_0215b8c4,
	(u32)data_ov052_0215bab4,
};
u32 data_ov052_0215b7a0[] = {
	(u32)data_ov052_0215b924,
	(u32)data_ov052_0215b8d4,
	(u32)data_ov052_0215b8f4,
};
u32 data_ov052_0215b7ac[] = { 7, 8, 9 };
u32 data_ov052_0215b7b8[] = {
	(u32)data_ov052_0215b934,
	(u32)data_ov052_0215b954,
	(u32)data_ov052_0215b974,
};
u32 data_ov052_0215b7c4[] = {
	(u32)data_ov052_0215b884,
	(u32)data_ov052_0215b894,
	(u32)data_ov052_0215b944,
	(u32)data_ov052_0215b8a4,
	(u32)data_ov052_0215b8e4,
};
u32 data_ov052_0215b7d8[] = {
	(u32)data_ov052_0215ba34,
	(u32)data_ov052_0215ba14,
	(u32)data_ov052_0215b9f4,
	(u32)data_ov052_0215b994,
	(u32)data_ov052_0215b9b4,
};
u32 data_ov052_0215b7ec[] = { 18, 19, 20, 21, 22, 23, 24, 25 };

namespace Object_4 {
	ObjectProfile profile = {
		MPLevelSelectScene::create,
		5,
		13,
	};
}

extern u32 func_0200696c__(u32, u16, u8, u8, u8, u32, u32, u32, u32,
	u8, u8, u8, u8, u8, u8, u8, u32);

namespace System {
	void setupSubBGVBlank();
	void resetSubBGVBlank();
	void setSubBGPosition(u32, s32, s32);
}

namespace Layout {
	void initSub(void *, void *, void *);
}

namespace Nitro {
	u32 func_0206202c();
	u32 func_020620ac();
	u32 func_020621b8();
	u32 func_02062244();
	u32 func_02055a0c(const BNBL *, u8, u8);
}

extern "C" {
	u32 func_0200e7ac(u32);
	void func_0200e7b8(u32);
	void func_0200e7c4(u32);
	u32 func_02009acc(u32);
	void func_0200419c(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, s32);
	void func_02006ca4();
	void func_02018060(void *);
	void func_020180c0(void *, u32);
	void func_0201df50();
	void func_02020628();
	bool func_02007c68(Fader *);
	bool func_02007cb0(Fader *);
	bool func_02046c78();
	void func_02007c44(Fader *);
	void func_02017e14(void *, const u32 *);
	void func_ov052_02153a1c(MPLevelSelectScene *);
	u8 func_ov052_02153a80();
	void func_ov052_02153760(MPLevelSelectScene *);
	void func_ov052_02153780(MPLevelSelectScene *);
	void func_ov052_021539c8(MPLevelSelectScene *);
}

void *MPLevelSelectScene::create()
{
	return new MPLevelSelectScene();
}

void MPLevelSelectScene::func_ov052_02155cf8()
{
	void *uVar1 = Nitro::func_02061f2c();
	FS::loadFileLZ77(0xc90d, uVar1);
	uVar1 = Nitro::func_02061f84();
	FS::loadFileLZ77(0xc90d, uVar1);
	FS::loadFileLZ77(0xc920, (void *)0x6600000);
}

void MPLevelSelectScene::func_ov052_02155c9c()
{
	// TODO, these are paletes, how best to define them?
	FS::loadFileLZ77(0xc90e, (void *)0x05000000);
	FS::loadFileLZ77(0xc910, (void *)0x05000200);
	Nitro::func_02066f28((void *)0x05000000, (void *)0x05000400, 0xe0);
	Nitro::func_02066f28((void *)0x05000200, (void *)0x05000600, 0x1a0);
}

void MPLevelSelectScene::func_ov052_02155ba8()
{
	FS::loadFileLZ77(0xc916, (void *)Nitro::func_020621b8());
	FS::loadFileLZ77(0xc90c, (void *)Nitro::func_020620ac());
	FS::loadFileLZ77(0xc913, G2S_GetBG0ScrPtr());
	*(u32 *)&_pad1[0xaf] = (u32)FS::Cache::loadFile(0xc912, true);
	*(u32 *)&_pad1[0xb3] = func_02009acc(0xc912);
	MI_CpuCopy8(
		(void *)*(u32 *)&_pad1[0xaf],
		(void *)Nitro::func_02062244(),
		*(u32 *)&_pad1[0xb3]
	);
	FS::loadFileLZ77(0xc915, (void *)(Nitro::func_02062244() + 0x800));
	Nitro::func_02066fe8((void *)(Nitro::func_02062244() + 0x1000), 0, 0x1000);
	FS::loadFileLZ77(0xc911, (void *)Nitro::func_02062138());
	FS::loadFileLZ77(0xc914, (void *)(Nitro::func_02062138() + 0x800));
	Nitro::func_02066fe8((void *)(Nitro::func_02062138() + 0x1000), 0, 0x1000);
	FS::loadFileLZ77(0xc90f, (void *)Nitro::func_0206202c());
}

void MPLevelSelectScene::func_ov052_02155b00() {
  if ((this->_64 == 0) || (this->_64 == 0x10)) {
    void* uVar1 = FS::Cache::loadFile(0xc91c, false);
    void* uVar2 = FS::Cache::loadFile(0xc91d, false);
    Layout::initSub((void *)nullptr,uVar2,uVar1);
  }
  else {
    void* uVar1 = FS::Cache::loadFile(0xc91e, false);
    void* uVar2 = FS::Cache::loadFile(0xc91f, false);
    Layout::initSub((void *)nullptr, uVar2,uVar1);
  }
  this->_70 = (u32)Layout::bncl[1] + 8;
  return;
}

MPLevelSelectScene::MPLevelSelectScene()
{
}

MPLevelSelectScene::~MPLevelSelectScene()
{
}

s32 MPLevelSelectScene::onCreate()
{
	func_02006ca4();
	Nitro::func_02061274();
	Nitro::func_02061260();
	Nitro::func_0206123c();
	Nitro::func_02061218();
	Nitro::func_02061204();
	Nitro::func_020611f0();
	Nitro::func_020611dc();
	Nitro::func_020611c8();
	Nitro::func_020611b4();
	Nitro::func_0206118c();
	Nitro::func_02061164();
	Nitro::func_02061588(6);
	Nitro::func_02061ac4(8);
	Nitro::func_02061494(0x10);
	Nitro::func_02061958(1);
	Nitro::func_02061844(0x40);
	Nitro::func_0206178c(0x20);
	Nitro::func_020613c8(0x80);
	Nitro::func_0206134c(0x100);
	Nitro::func_02060d78(1, 0, 0);
	Nitro::func_02060d5c(0);

	data_02085a88 = 0x1c;
	REG_DISPCNT = (REG_DISPCNT & ~0x1f00) | 0x1c00;
	if (func_02046c78() == 0)
		goto primary_display;
	REG_DISPCNT_SUB = (REG_DISPCNT_SUB & ~0x1f00) | 0x1e00;
	goto display_configured;

primary_display:
	REG_DISPCNT_SUB = (REG_DISPCNT_SUB & ~0x1f00) | 0x1c00;

display_configured:

	REG_DISPCNT = (REG_DISPCNT & 0xffcfffef) | 0x200010;
	REG_DISPCNT_SUB = (REG_DISPCNT_SUB & 0xffcfffef) | 0x10;
	REG_DISPCNT &= ~0x07000000;
	REG_DISPCNT = (REG_DISPCNT & ~0x38000000) | 0x08000000;

	vu16 *bg0Main = (vu16 *)0x0400000c;
	vu16 *bg1Main = (vu16 *)0x0400000e;
	vu16 *bg0Sub = (vu16 *)0x04001008;
	vu16 *bg1Sub = (vu16 *)0x0400100a;
	vu16 *bg2Sub = (vu16 *)0x0400100c;
	vu16 *bg3Sub = (vu16 *)0x0400100e;
	*bg0Main = *bg0Main & ~3;
	*bg1Main = (*bg1Main & ~3) | 1;
	*bg0Sub = *bg0Sub & ~3;
	*bg1Sub = (*bg1Sub & ~3) | 1;
	*bg2Sub = (*bg2Sub & ~3) | 2;
	*bg3Sub = (*bg3Sub & ~3) | 3;
	*bg0Main = (*bg0Main & 0x43) | 4;
	*bg1Main = (*bg1Main & 0x43) | 0x104;
	*bg0Sub = (*bg0Sub & 0x43) | 0x600;
	*bg1Sub = (*bg1Sub & 0x43) | 0xc700;
	*bg2Sub = (*bg2Sub & 0x43) | 0xcb00;
	*bg3Sub = (*bg3Sub & 0x43) | 0xf00;
	*bg0Main &= ~0x40;
	*bg1Main &= ~0x40;
	*bg0Sub &= ~0x40;
	*bg1Sub &= ~0x40;
	*bg2Sub &= ~0x40;
	*bg3Sub &= ~0x40;

	func_ov052_02155cf8();
	func_ov052_02155ba8();
	func_ov052_02155b00();
	_144 = 0x1e;
	_12c.x = 0;
	_12c.y = 0x100000;
	_138.x = _12c.x;
	_138.y = _12c.y;
	i32 y = _12c.y;
	i32 x = _12c.x;
	i32 yShift = y >> 12;
	REG_BG1OFS = 0;
	REG_BG2OFS = 0;
	REG_BG0OFS_SUB = 0;
	u32 position = (0x1ff & (x >> 12)) | (0x1ff0000 & (yShift << 16));
	REG_BG1OFS_SUB = position;
	REG_BG2OFS_SUB = position;
	REG_BG3OFS_SUB = 0;

	func_02020628();
	func_0201df50();
	func_ov052_02155c9c();
	func_020180c0(&a, 4);
	u32 value = func_02046c78() ? 0xa : 0xb;
	func_02017e14(&a, &value);

	if (data_0203bd2c == 6 || data_0203bd2c == 1 || data_0203bd2c == 10) {
		_pad0[0] = 0;
		data_ov052_0215c890 = 0;
		if (data_0203bd2c != 10) {
			data_ov052_0215c894 = 1;
			data_ov052_0215c88c = 1;
			data_ov052_0215c89c = 2;
			data_ov052_0215c888 = 1;
		}
		data_ov052_0215c884 = 0;
		data_ov052_0215c8a0[0] = 0;
		data_ov052_0215c8a0[1] = 0;
		data_ov052_0215c898 = 0;
		_64 = 0;
	} else if (data_0203bd2c == 3) {
		if (data_ov052_0215c888 == 0) {
			u8 start = data_ov052_0215c884;
			u8 count = data_ov052_0215aee8[data_ov052_0215c894];
			u32 range = ((count * 2 - 1) - start) & 0xff;
			u32 random = Wifi::random();
			u8 target = range * (random & 0x7fff) >> 15;
			u32 i;
			u32 available = 0;
			i = available;
			do {
				if ((data_ov052_0215c898 & (1 << i)) == 0) {
					if (available == target)
						break;
					available++;
				}
				i++;
			} while ((s32)i < 5);
			data_ov052_0215c890 = i;
			func_ov052_02153a1c(this);
			return 1;
		}
		_64 = 5;
		func_ov052_02155b00();
	}

	System::setupSubBGVBlank();
	func_02011e7c(0x1f, 0);
	_5c = 0x20;
	return 1;
}

s32 MPLevelSelectScene::onDestroy() {
	func_020180a4(&this->a);
	System::resetSubBGVBlank();
	return true;
}

void MPLevelSelectScene::pendingDestroy() {
}

//void (Object229::*data_ov099_02186614[4])() = {
//    Object229::func_ov099_021860f0,
//    Object229::func_ov099_02186080,
//    Object229::func_ov099_02186028,
//    Object229::func_ov099_02185fb4,
//};

s32 MPLevelSelectScene::onUpdate() {
	static void (MPLevelSelectScene::*ptmfs[20])() = {
		MPLevelSelectScene::func_ov052_02155210,
		MPLevelSelectScene::func_ov052_021551e4,
		MPLevelSelectScene::func_ov052_0215515c,
		MPLevelSelectScene::func_ov052_02154c9c,
		MPLevelSelectScene::func_ov052_02154bb4,
		MPLevelSelectScene::func_ov052_02154a60,
		MPLevelSelectScene::func_ov052_0215476c,
		MPLevelSelectScene::func_ov052_021546d0,
		MPLevelSelectScene::func_ov052_02154698,
		MPLevelSelectScene::func_ov052_0215459c,
		MPLevelSelectScene::func_ov052_02154698,
		MPLevelSelectScene::func_ov052_02155178,
		MPLevelSelectScene::func_ov052_02154b64,
		MPLevelSelectScene::func_ov052_02154af4,
		MPLevelSelectScene::func_ov052_02154a24,
		MPLevelSelectScene::func_ov052_0215454c,
		MPLevelSelectScene::func_ov052_021544a0,
		MPLevelSelectScene::func_ov052_02154c68,
		MPLevelSelectScene::func_ov052_02154c34,
		MPLevelSelectScene::func_ov052_021549f8
	};
	func_02021808();
	if (this->_144 > 0) {
		this->_144 -= 1;
	}
	(this->*ptmfs[this->_64])();
	return 1;
}

s32 MPLevelSelectScene::onRender() {
	static void (MPLevelSelectScene::*ptmfs[20])() = {
		MPLevelSelectScene::func_ov052_02154244,
		MPLevelSelectScene::func_ov052_02154238,
		MPLevelSelectScene::func_ov052_02154220,
		MPLevelSelectScene::func_ov052_02153d5c,
		MPLevelSelectScene::func_ov052_02153d14,
		MPLevelSelectScene::func_ov052_02153d08,
		MPLevelSelectScene::func_ov052_02153b44,
		MPLevelSelectScene::func_ov052_02153b38,
		MPLevelSelectScene::func_ov052_02153b04,
		MPLevelSelectScene::func_ov052_02153ad0,
		MPLevelSelectScene::func_ov052_02153b04,
		MPLevelSelectScene::func_ov052_0215422c,
		MPLevelSelectScene::func_ov052_02153d2c,
		MPLevelSelectScene::func_ov052_02153d20,
		MPLevelSelectScene::func_ov052_02153cfc,
		MPLevelSelectScene::func_ov052_02153ac4,
		MPLevelSelectScene::func_ov052_02153ab8,
		MPLevelSelectScene::func_ov052_02153d50,
		MPLevelSelectScene::func_ov052_02153d44,
		MPLevelSelectScene::func_ov052_02153d38
	};
	(this->*ptmfs[this->_64])();
	return true;
}

void MPLevelSelectScene::func_ov052_02153ab8()
{
	func_ov052_02153b44();
}

void MPLevelSelectScene::func_ov052_02153ac4()
{
	func_ov052_02153b44();
}

void MPLevelSelectScene::func_ov052_02153ad0()
{
	if (data_ov052_0215c888 == 0) {
		func_ov052_02153d5c();
	} else {
		func_ov052_02153b44();
	}
}

void MPLevelSelectScene::func_ov052_02153b04()
{
	if (data_ov052_0215c888 == 0) {
		func_ov052_02153d5c();
	} else {
		func_ov052_02153b44();
	}
}

void MPLevelSelectScene::func_ov052_02153b38()
{
	func_ov052_02153b44();
}

void MPLevelSelectScene::func_ov052_02153b44()
{
	i32 offset = -(_12c.y >> 12);
	func_02018060(&a);
	func_0200419c(
		1, data_ov052_0215b7c4[data_ov052_0215c884],
		0, 0, 0, 0, 0, 0, 0, 0, offset
	);
	func_0200419c(0, (u32)data_ov052_0215ba84, 0, 0, 0, 0, 0, 0, 0, 0, offset);

	for (s32 i = 0; i < 5; i++) {
		u32 selected;
		if (i == data_ov052_0215c890 && _64 >= 7 && _64 <= 10 && _pad0[3] == 0) {
			selected = 1;
		} else {
			selected = 0;
		}
		func_0200419c(
			i + 6, data_ov052_0215b7d8[i],
			0, selected, 0, 0, 0, 0, 0, 0, offset
		);
	}

	if (func_02046c78() == 1 && data_ov052_0215c884 == 0) {
		u32 selected = _pad0[3] == 1 ? 1 : 0;
		func_0200419c(0xb, (u32)data_ov052_0215b87c, 0, selected, 0, 0, 0, 0, 0, 0, -offset);
	}

	System::setSubBGPosition(1, _138.x >> 12, _138.y >> 12);
	System::setSubBGPosition(2, _12c.x >> 12, -offset);
}

void MPLevelSelectScene::func_ov052_02153cfc()
{
	func_ov052_02153b44();
}

void MPLevelSelectScene::func_ov052_02153d08()
{
	func_ov052_02153b44();
}

void MPLevelSelectScene::func_ov052_02153d14()
{
	func_ov052_02153d5c();
}

void MPLevelSelectScene::func_ov052_02153d20()
{
	func_ov052_02153d5c();
}

void MPLevelSelectScene::func_ov052_02153d2c()
{
	func_ov052_02153d5c();
}

void MPLevelSelectScene::func_ov052_02153d38()
{
	func_ov052_02153b44();
}

void MPLevelSelectScene::func_ov052_02153d44()
{
	func_ov052_02153d5c();
}

void MPLevelSelectScene::func_ov052_02153d50()
{
	func_ov052_02153d5c();
}

void MPLevelSelectScene::func_ov052_02153d5c()
{
	i32 mainY = -(_12c.y >> 12);
	i32 subX = -(_138.x >> 12);
	i32 subY = -(_138.y >> 12);
	func_02018060(&a);

	u32 style = _pad0[0] == 0 ? 0 : 2;
	func_0200419c(2, (u32)data_ov052_0215b864, 0, style, 0, 0, 0, 0, 0, 0, mainY);
	func_0200419c(
		3, data_ov052_0215b7a0[data_ov052_0215c894],
		0, style, 0, 0, 0, 0, 0, 0, mainY
	);

	style = _pad0[0] == 1 ? 0 : 2;
	func_0200419c(6, (u32)data_ov052_0215b904, 0, style, 0, 0, 0, 0, 0, 0, mainY);
	func_0200419c(
		data_ov052_0215b7ac[data_ov052_0215c88c],
		data_ov052_0215b7b8[data_ov052_0215c88c],
		0, style, 0, 0, 0, 0, 0, 0, mainY
	);

	style = _pad0[0] == 2 ? 0 : 2;
	u8 character = data_0208ae54[data_020887f0];
	func_0200419c(
		data_ov052_0215b618[character], data_ov052_0215b628[character],
		0, style, 0, 0, 0, 0, 0, 0, mainY
	);
	func_0200419c(
		data_ov052_0215b788[data_ov052_0215c89c],
		data_ov052_0215b794[data_ov052_0215c89c],
		0, style, 0, 0, 0, 0, 0, 0, mainY
	);

	style = _pad0[0] == 3 ? 0 : 2;
	func_0200419c(0xf, (u32)data_ov052_0215b914, 0, style, 0, 0, 0, 0, 0, 0, mainY);
	func_0200419c(
		data_ov052_0215b6a0[data_ov052_0215c888],
		data_ov052_0215b6b0[data_ov052_0215c888],
		0, style, 0, 0, 0, 0, 0, 0, mainY
	);

	if (func_02046c78() == 1) {
		u32 action = Nitro::func_02055a0c(
			Layout::bnbl[1], data_0208b4e8, data_0208b4f4
		);
		u32 inactive0 = 0;
		u32 inactive1 = 0;
		u32 inactive2 = 0;
		u32 inactive3 = 0;
		for (s32 i = 0; i < 8; i++) {
			u32 itemStyle;
			if (i == action - 2 ||
				((i >> 1) == _pad0[0] &&
				 (((i & 1) == 0 && (data_02087650[Input::localConsoleID][0] & 0x20) != 0) ||
				  ((i & 1) == 1 && (data_02087650[Input::localConsoleID][0] & 0x10) != 0)))) {
				itemStyle = 1;
			} else {
				itemStyle = 2;
				switch (i) {
				case 0:
				case 1:
					if (_pad0[0] == 0)
						itemStyle = inactive0;
					break;
				case 2:
				case 3:
					if (_pad0[0] == 1)
						itemStyle = inactive1;
					break;
				case 4:
				case 5:
					if (_pad0[0] == 2)
						itemStyle = inactive2;
					break;
				case 6:
				case 7:
					if (_pad0[0] == 3)
						itemStyle = inactive3;
					break;
				}
			}
			func_0200419c(
				data_ov052_0215b7ec[i], data_ov052_0215b728[i & 1],
				0, itemStyle, 0, 0, 0, 0, 0, 0, mainY
			);
		}

		if (_pad0[0] == 4) {
			u8 state = _64;
			if (state == 4 || state == 0x12 || state == 0x11 || (u8)(state + 0xf4) <= 1)
				style = 1;
			else
				style = 0;
		} else {
			style = 2;
		}
		func_0200419c(
			1, (u32)data_ov052_0215b9d4, 0, style,
			0, 0, 0, 0, 0, subX, subY
		);
	}

	System::setSubBGPosition(1, -subX, -subY);
	System::setSubBGPosition(2, _12c.x >> 12, -mainY);
}

void MPLevelSelectScene::func_ov052_0215515c()
{
	_64 = 3;
	_138.x = _12c.x;
	_138.y = _12c.y;
}

void MPLevelSelectScene::func_ov052_021551e4()
{
	if (func_0200e7ac(1) != 0) {
		func_0200e7b8(1);
		_64 = 11;
	}
}

void MPLevelSelectScene::func_ov052_021549f8()
{
	REG_DISPCNT_SUB = (REG_DISPCNT_SUB & ~0x1f00) | 0x1e00;
	_64 = 6;
	func_ov052_021539c8(this);
}

void MPLevelSelectScene::func_ov052_02154698()
{
	if (func_02007c68(&GlobalFader) != 0) {
		if (_64 == 8) {
			_64 = 9;
		} else {
			_64 = 0;
		}
	}
}

void MPLevelSelectScene::func_ov052_021546d0()
{
	s8 timer = _pad0[1];
	if (timer != 0)
		goto decrement_timer;
	if (_pad0[3] == 0)
		goto no_selection;
	REG_DISPCNT_SUB = (REG_DISPCNT_SUB & ~0x1f00) | 0x1c00;
	_pad0[0] = 0;
	data_ov052_0215c890 = 0;
	_64 = 0xf;
	u32 value = func_02046c78() ? 0xa : 0xb;
	func_02017e14(&a, &value);
	return;

no_selection:
	func_ov052_02153a1c(this);
	return;

decrement_timer:
	_pad0[1] = timer - 1;
}

void MPLevelSelectScene::func_ov052_0215476c()
{
	u8 previousState;
	u32 previousSelection = data_ov052_0215c890;
	previousState = _64;
	BOOL connected = data_0208b4f0 != 0 && data_0208b4ec != 0;

	if (connected != FALSE) {
		u32 selection = Nitro::func_02055a0c(
			Layout::bnbl[1], data_0208b4e8, data_0208b4f4
		);
		switch (selection) {
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
			data_ov052_0215c890 = selection;
			_64 = 7;
			func_ov052_02153760(this);
			break;
		case 5:
			if (data_ov052_0215c884 == 0) {
				_pad0[3] = 1;
				_64 = 7;
			}
			break;
		}
	} else {
		u16 input = data_02087650[0][1];
		if ((input & 2) != 0) {
			if (data_ov052_0215c884 == 0) {
				_pad0[3] = 1;
				_64 = 7;
			}
		} else if ((input & 1) != 0) {
			_64 = 7;
			func_ov052_02153760(this);
		} else {
			switch (previousSelection) {
			case 0:
				if ((input & 0x10) != 0)
					data_ov052_0215c890 = 1;
				else if ((input & 0x80) != 0)
					data_ov052_0215c890 = 3;
				break;
			case 1:
				if ((input & 0x20) != 0)
					data_ov052_0215c890 = 0;
				else if ((input & 0x10) != 0)
					data_ov052_0215c890 = 2;
				else if ((input & 0x80) != 0)
					data_ov052_0215c890 = 4;
				break;
			case 2:
				if ((input & 0x20) != 0)
					data_ov052_0215c890 = 1;
				else if ((input & 0x80) != 0)
					data_ov052_0215c890 = 4;
				break;
			case 3:
				if ((input & 0x10) != 0)
					data_ov052_0215c890 = 4;
				else if ((input & 0x40) != 0)
					data_ov052_0215c890 = 0;
				break;
			case 4:
				if ((input & 0x20) != 0)
					data_ov052_0215c890 = 3;
				else if ((input & 0x40) != 0)
					data_ov052_0215c890 = 1;
				break;
			}
		}
	}

	func_ov052_021539c8(this);
	if (previousState != _64) {
		_pad0[1] = 0x1e;
		if (_pad0[3] != 0) {
			func_02012398(0xea, nullptr);
			return;
		}
		func_02012398(0xe9, nullptr);
		return;
	}
	if (previousSelection != data_ov052_0215c890)
		func_02012398(0xe5, nullptr);
}

void MPLevelSelectScene::func_ov052_02154a24()
{
	func_ov052_021554dc();
	if (_12c.y != 0) {
		_138.x = _12c.x;
		_138.y = _12c.y;
		return;
	}
	func_ov052_021539c8(this);
	_64 = 0x13;
}

void MPLevelSelectScene::func_ov052_02154a60()
{
	func_ov052_02155ba8();
	REG_DISPCNT_SUB = (REG_DISPCNT_SUB & ~0x1f00) | 0x1c00;
	u32 size = *(u32 *)&_pad1[0xb3];
	void *address = (void *)Nitro::func_02062244();
	Nitro::func_02066fe8(address, 0, size);
	_12c.x = 0x100000;
	func_ov052_02153780(this);
	_64 = 0xe;
	_pad0[3] = 0;
	u32 value = func_02046c78() ? 0xc : 0xd;
	func_02017e14(&a, &value);
	_138.x = _12c.x;
	_138.y = _12c.y;
}

void MPLevelSelectScene::func_ov052_021554dc()
{
	if (_144 == 0) {
		Math::expLerp(&_12c.y, 0, 0x400, 0x28000, 0x5000);
	}
}

void MPLevelSelectScene::func_ov052_0215454c()
{
	if (Math::expLerp(&_12c.y, -0xa000, 0x400, 0x28000, 0x1000) == 0) {
		_64 = 0x10;
	}
	_138.x = _12c.x;
	_138.y = _12c.y;
}

void MPLevelSelectScene::func_ov052_0215459c()
{
	func_02020580(0, data_ov052_0215af0c[data_ov052_0215c89c]);
	func_02020580(1, data_ov052_0215af0c[data_ov052_0215c89c]);
	u32 mode = data_02085a84;
	u8 value = func_ov052_02153a80();
	func_0200696c__(
		0xf, (u8)mode, 9, value, 0,
		data_020887f0, 3, data_0208ae54[0], data_0208ae54[1],
		0, 0xff, 1, 1, 0xff, 0, 0, ~0
	);
	func_02007c44(&GlobalFader);
	GlobalFader.func_02007bfc();
	data_02085a58 = 0;
	func_02011e3c(0x1e);
}

void MPLevelSelectScene::func_ov052_021544a0()
{
	if (Math::expLerp(&_12c.y, 0x100000, 0x300, 0x28000, 0x3000) == 0) {
		func_ov052_02155b00();
		_12c.x = 0;
		MI_CpuCopy8(
			(void *)*(u32 *)&_pad1[0xaf],
			(void *)Nitro::func_02062244(),
			*(u32 *)&_pad1[0xb3]
		);
		if (func_02046c78() == 0)
			goto primary_display;
		REG_DISPCNT_SUB = (REG_DISPCNT_SUB & ~0x1f00) | 0x1e00;
		goto display_configured;

	primary_display:
		REG_DISPCNT_SUB = (REG_DISPCNT_SUB & ~0x1f00) | 0x1c00;

	display_configured:
		_64 = 0xb;
	}
	_138.x = _12c.x;
	_138.y = _12c.y;
}

void MPLevelSelectScene::func_ov052_02154b64()
{
	if (Math::expLerp(&_12c.y, -0xa000, 0x300, 0x28000, 0x3000) == 0) {
		_64 = 0xd;
	}
	_138.x = _12c.x;
	_138.y = _12c.y;
}

void MPLevelSelectScene::func_ov052_02154bb4()
{
	s8 timer = _pad0[1];
	if (timer == 0) {
		if (data_ov052_0215c888 == 0) {
			data_ov052_0215c890 = (Wifi::random() & 0x7fff) * 5 >> 15;
			func_ov052_02153a1c(this);
		} else {
			_64 = 0xc;
		}
	} else {
		_pad0[1] = timer - 1;
	}
	_138.x = _12c.x;
	_138.y = _12c.y;
}

void MPLevelSelectScene::func_ov052_02154af4()
{
	if (Math::expLerp(&_12c.y, 0x100000, 0x300, 0x28000, 0x3000) == 0) {
		MI_CpuCopy8((void *)0x050004ba, (void *)0x050004b4, 6);
		_64 = 5;
		func_ov052_02155b00();
	}
	_138.x = _12c.x;
	_138.y = _12c.y;
}

void MPLevelSelectScene::func_ov052_02155178()
{
	func_ov052_021554dc();
	_138.x = _12c.x;
	_138.y = _12c.y;
	if (_12c.y != 0) {
		return;
	}
	_64 = 2;
	if (func_02046c78() == 0)
		goto primary_display;
	REG_DISPCNT_SUB = (REG_DISPCNT_SUB & ~0x1f00) | 0x1f00;
	return;

primary_display:
	REG_DISPCNT_SUB = (REG_DISPCNT_SUB & ~0x1f00) | 0x1d00;
}

void MPLevelSelectScene::func_ov052_02155210()
{
	func_ov052_021554dc();
	_138.x = _12c.x;
	_138.y = _12c.y;
	if (func_02007cb0(&GlobalFader) == 0) {
		return;
	}
	if (data_02085a84 == 0) {
		_64 = 0xb;
		return;
	}
	func_0200e7c4(1);
	_64 = 1;
}

void MPLevelSelectScene::func_ov052_02154c34()
{
	i32 offset = -_144 << 12;
	_138.x = offset;
	_138.y = offset;
	if (_144 == 0) {
		_64 = 4;
		_pad0[1] = 0x1e;
	}
}

void MPLevelSelectScene::func_ov052_02154c68()
{
	i32 offset = (_144 - 3) << 12;
	_138.x = offset;
	_138.y = offset;
	if (_144 == 0) {
		_64 = 0x12;
		_144 = 3;
	}
}

void MPLevelSelectScene::func_ov052_02154c9c()
{
	u8 oldToggle;
	u8 oldSelection;
	u8 oldOption0;
	u8 oldOption1;
	u8 oldState;
	u8 oldOption2;
	oldOption0 = data_ov052_0215c894;
	oldOption1 = data_ov052_0215c88c;
	oldOption2 = data_ov052_0215c89c;
	oldToggle = data_ov052_0215c888;
	oldState = _64;
	oldSelection = _pad0[0];
	BOOL connected = data_0208b4f0 != 0 && data_0208b4ec != 0;

	if (connected != FALSE) {
		u32 action = Nitro::func_02055a0c(
			Layout::bnbl[1], data_0208b4e8, data_0208b4f4
		);
		switch (action) {
		case 0:
			break;
		case 2:
			_pad0[0] = 0;
			if (data_ov052_0215c894 == 0)
				data_ov052_0215c894 = 2;
			else
				data_ov052_0215c894--;
			break;
		case 3:
			_pad0[0] = 0;
			if (data_ov052_0215c894 == 2)
				data_ov052_0215c894 = 0;
			else
				data_ov052_0215c894++;
			break;
		case 4:
			_pad0[0] = 1;
			if (data_ov052_0215c88c == 0)
				data_ov052_0215c88c = 2;
			else
				data_ov052_0215c88c--;
			break;
		case 5:
			_pad0[0] = 1;
			if (data_ov052_0215c88c == 2)
				data_ov052_0215c88c = 0;
			else
				data_ov052_0215c88c++;
			break;
		case 6:
			_pad0[0] = 2;
			if (data_ov052_0215c89c == 0)
				data_ov052_0215c89c = 2;
			else
				data_ov052_0215c89c--;
			break;
		case 7:
			_pad0[0] = 2;
			if (data_ov052_0215c89c == 2)
				data_ov052_0215c89c = 0;
			else
				data_ov052_0215c89c++;
			break;
		case 8:
		case 9:
			_pad0[0] = 3;
			data_ov052_0215c888 ^= 1;
			break;
		case 1:
			_64 = 0x11;
			_pad0[0] = 4;
			break;
		}
	} else {
		u16 input = data_02087650[0][1];
		if ((input & 1) != 0) {
			if (oldSelection == 4)
				_64 = 0x11;
			else
				_pad0[0]++;
		} else if ((input & 0x80) != 0) {
			if (oldSelection != 4)
				_pad0[0]++;
		} else if ((input & 0x40) != 0) {
			if (oldSelection != 0)
				_pad0[0]--;
		} else if ((input & 0x20) != 0) {
			switch (oldSelection) {
			case 0:
				if (oldOption0 == 0)
					data_ov052_0215c894 = 2;
				else
					data_ov052_0215c894--;
				break;
			case 1:
				if (oldOption1 == 0)
					data_ov052_0215c88c = 2;
				else
					data_ov052_0215c88c--;
				break;
			case 2:
				if (oldOption2 == 0)
					data_ov052_0215c89c = 2;
				else
					data_ov052_0215c89c--;
				break;
			case 3:
				data_ov052_0215c888 ^= 1;
				break;
			}
		} else if ((input & 0x10) != 0) {
			switch (oldSelection) {
			case 0:
				if (oldOption0 == 2)
					data_ov052_0215c894 = 0;
				else
					data_ov052_0215c894++;
				break;
			case 1:
				if (oldOption1 == 2)
					data_ov052_0215c88c = 0;
				else
					data_ov052_0215c88c++;
				break;
			case 2:
				if (oldOption2 == 2)
					data_ov052_0215c89c = 0;
				else
					data_ov052_0215c89c++;
				break;
			case 3:
				data_ov052_0215c888 ^= 1;
				break;
			}
		}
	}

	if (oldState != _64) {
		_144 = 3;
		MI_CpuCopy8((void *)0x05000474, (void *)0x050004b4, 6);
		func_02012398(0xe9, nullptr);
	} else {
		if (oldOption0 != data_ov052_0215c894 ||
			oldOption1 != data_ov052_0215c88c ||
			oldOption2 != data_ov052_0215c89c ||
			oldToggle != data_ov052_0215c888 ||
			oldSelection != _pad0[0]) {
			func_02012398(0xe5, nullptr);
		}
	}

	if (_pad0[0] >= 4)
		System::setSubBGPosition(0, 0, 0x40);
	else
		System::setSubBGPosition(0, 0, _pad0[0] * -0x24);

	if (oldSelection != _pad0[0]) {
		if (_pad0[0] == 4)
			MI_CpuCopy8((void *)0x05000454, (void *)0x050004b4, 6);
		else if (oldSelection == 4)
			MI_CpuCopy8((void *)0x050004ba, (void *)0x050004b4, 6);
	}

	_138.x = _12c.x;
	_138.y = _12c.y;
}

void MPLevelSelectScene::func_ov052_02154220()
{
	func_ov052_02153d5c();
}

void MPLevelSelectScene::func_ov052_0215422c()
{
	func_ov052_02153d5c();
}

void MPLevelSelectScene::func_ov052_02154238()
{
	func_ov052_02153d5c();
}

void MPLevelSelectScene::func_ov052_02154244()
{
	func_ov052_02153d5c();
}
