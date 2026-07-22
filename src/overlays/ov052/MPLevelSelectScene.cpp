#include "MPLevelSelectScene.hpp"
#include <nsmb/arm9/symbols.hpp>
#include <nsmb/overlays/ov052/dependencies.hpp>
#include <nsmb/overlays/ov052/symbols.hpp>
#include <nds/graphics.hpp>
#include <nds/memory.hpp>

u32 data_ov052_0215c8ac[2];
u32 data_ov052_0215c8b4[3];

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

void *MPLevelSelectScene::create()
{
	return new MPLevelSelectScene();
}

void MPLevelSelectScene::func_ov052_02155cf8()
{
	void *uVar1 = NDS::Graphics::mainBackground2Tiles();
	FS::loadFileLZ77(0xc90d, uVar1);
	uVar1 = NDS::Graphics::subBackground1Tiles();
	FS::loadFileLZ77(0xc90d, uVar1);
	FS::loadFileLZ77(0xc920, (void *)0x6600000);
}

void MPLevelSelectScene::func_ov052_02155c9c()
{
	// TODO, these are paletes, how best to define them?
	FS::loadFileLZ77(0xc90e, (void *)0x05000000);
	FS::loadFileLZ77(0xc910, (void *)0x05000200);
	NDS::Memory::copyFast((void *)0x05000000, (void *)0x05000400, 0xe0);
	NDS::Memory::copyFast((void *)0x05000200, (void *)0x05000600, 0x1a0);
}

void MPLevelSelectScene::func_ov052_02155ba8()
{
	FS::loadFileLZ77(0xc916, (void *)NDS::Graphics::mainBackground2Map());
	FS::loadFileLZ77(0xc90c, (void *)NDS::Graphics::mainBackground3Map());
	FS::loadFileLZ77(0xc913, NDS::Graphics::subBackground0Map());
	tilesetData = FS::Cache::loadFile(0xc912, true);
	tilesetSize = func_02009acc(0xc912);
	NDS::Memory::copy8(
		tilesetData,
		(void *)NDS::Graphics::subBackground1Map(),
		tilesetSize
	);
	FS::loadFileLZ77(0xc915, (void *)(NDS::Graphics::subBackground1Map() + 0x800));
	NDS::Memory::fill8((void *)(NDS::Graphics::subBackground1Map() + 0x1000), 0, 0x1000);
	FS::loadFileLZ77(0xc911, (void *)NDS::Graphics::subBackground2Map());
	FS::loadFileLZ77(0xc914, (void *)(NDS::Graphics::subBackground2Map() + 0x800));
	NDS::Memory::fill8((void *)(NDS::Graphics::subBackground2Map() + 0x1000), 0, 0x1000);
	FS::loadFileLZ77(0xc90f, (void *)NDS::Graphics::subBackground3Map());
}

void MPLevelSelectScene::func_ov052_02155b00() {
  if ((this->state == 0) || (this->state == 0x10)) {
    void* uVar1 = FS::Cache::loadFile(0xc91c, false);
    void* uVar2 = FS::Cache::loadFile(0xc91d, false);
    Layout::initSub((void *)nullptr,uVar2,uVar1);
  }
  else {
    void* uVar1 = FS::Cache::loadFile(0xc91e, false);
    void* uVar2 = FS::Cache::loadFile(0xc91f, false);
    Layout::initSub((void *)nullptr, uVar2,uVar1);
  }
  this->subCellData = (u32)Layout::bncl[1] + 8;
  return;
}

MPLevelSelectScene::MPLevelSelectScene() : initializedState(0)
{
}

MPLevelSelectScene::~MPLevelSelectScene()
{
}

s32 MPLevelSelectScene::onCreate()
{
	func_02006ca4();
	NDS::Graphics::resetMainBackgroundBank();
	NDS::Graphics::resetMainObjectBank();
	NDS::Graphics::resetMainBackgroundPaletteBank();
	NDS::Graphics::resetMainObjectPaletteBank();
	NDS::Graphics::resetTextureBank();
	NDS::Graphics::resetTexturePaletteBank();
	NDS::Graphics::resetClearImageBank();
	NDS::Graphics::resetSubBackgroundBank();
	NDS::Graphics::resetSubObjectBank();
	NDS::Graphics::resetSubBackgroundPaletteBank();
	NDS::Graphics::resetSubObjectPaletteBank();
	NDS::Graphics::assignTextureBank(6);
	NDS::Graphics::assignMainBackgroundBank(8);
	NDS::Graphics::assignTexturePaletteBank(0x10);
	NDS::Graphics::assignMainObjectBank(1);
	NDS::Graphics::assignMainBackgroundPaletteBank(0x40);
	NDS::Graphics::assignMainObjectPaletteBank(0x20);
	NDS::Graphics::assignSubBackgroundBank(0x80);
	NDS::Graphics::assignSubObjectBank(0x100);
	NDS::Graphics::setMainDisplayMode(1, 0, 0);
	NDS::Graphics::setSubDisplayMode(0);

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
	transitionTimer = 0x1e;
	mainBackgroundPosition.x = 0;
	mainBackgroundPosition.y = 0x100000;
	selectionBackgroundPosition.x = mainBackgroundPosition.x;
	selectionBackgroundPosition.y = mainBackgroundPosition.y;
	i32 y = mainBackgroundPosition.y;
	i32 x = mainBackgroundPosition.x;
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
	func_020180c0(&textLabel, 4);
	u32 value = func_02046c78() ? 0xa : 0xb;
	func_02017e14(&textLabel, &value);

	if (data_0203bd2c == 6 || data_0203bd2c == 1 || data_0203bd2c == 10) {
		selection = 0;
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
		state = 0;
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
		state = 5;
		func_ov052_02155b00();
	}

	System::setupSubBGVBlank();
	func_02011e7c(0x1f, 0);
	wifiIconOBJIndex = 0x20;
	return 1;
}

s32 MPLevelSelectScene::onDestroy() {
	func_020180a4(&this->textLabel);
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
	if (this->transitionTimer > 0) {
		this->transitionTimer -= 1;
	}
	(this->*ptmfs[this->state])();
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
	(this->*ptmfs[this->state])();
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
	i32 offset = -(mainBackgroundPosition.y >> 12);
	func_02018060(&textLabel);
	func_0200419c(
		1, data_ov052_0215b7c4[data_ov052_0215c884],
		0, 0, 0, 0, 0, 0, 0, 0, offset
	);
	func_0200419c(0, (u32)data_ov052_0215ba84, 0, 0, 0, 0, 0, 0, 0, 0, offset);

	for (s32 i = 0; i < 5; i++) {
		u32 selected;
		if (i == data_ov052_0215c890 && state >= 7 && state <= 10 && confirmationVisible == 0) {
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
		u32 selected = confirmationVisible == 1 ? 1 : 0;
		func_0200419c(0xb, (u32)data_ov052_0215b87c, 0, selected, 0, 0, 0, 0, 0, 0, -offset);
	}

	System::setSubBGPosition(1, selectionBackgroundPosition.x >> 12, selectionBackgroundPosition.y >> 12);
	System::setSubBGPosition(2, mainBackgroundPosition.x >> 12, -offset);
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
	i32 mainY = -(mainBackgroundPosition.y >> 12);
	i32 subX = -(selectionBackgroundPosition.x >> 12);
	i32 subY = -(selectionBackgroundPosition.y >> 12);
	func_02018060(&textLabel);

	u32 style = selection == 0 ? 0 : 2;
	func_0200419c(2, (u32)data_ov052_0215b864, 0, style, 0, 0, 0, 0, 0, 0, mainY);
	func_0200419c(
		3, data_ov052_0215b7a0[data_ov052_0215c894],
		0, style, 0, 0, 0, 0, 0, 0, mainY
	);

	style = selection == 1 ? 0 : 2;
	func_0200419c(6, (u32)data_ov052_0215b904, 0, style, 0, 0, 0, 0, 0, 0, mainY);
	func_0200419c(
		data_ov052_0215b7ac[data_ov052_0215c88c],
		data_ov052_0215b7b8[data_ov052_0215c88c],
		0, style, 0, 0, 0, 0, 0, 0, mainY
	);

	style = selection == 2 ? 0 : 2;
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

	style = selection == 3 ? 0 : 2;
	func_0200419c(0xf, (u32)data_ov052_0215b914, 0, style, 0, 0, 0, 0, 0, 0, mainY);
	func_0200419c(
		data_ov052_0215b6a0[data_ov052_0215c888],
		data_ov052_0215b6b0[data_ov052_0215c888],
		0, style, 0, 0, 0, 0, 0, 0, mainY
	);

	if (func_02046c78() == 1) {
		u32 action = Layout::bnbl[1]->getBox(data_0208b4e8, data_0208b4f4);
		u32 inactive0 = 0;
		u32 inactive1 = 0;
		u32 inactive2 = 0;
		u32 inactive3 = 0;
		for (s32 i = 0; i < 8; i++) {
			u32 itemStyle;
			if (i == action - 2 ||
				((i >> 1) == selection &&
				 (((i & 1) == 0 && (data_02087650[Input::localConsoleID][0] & 0x20) != 0) ||
				  ((i & 1) == 1 && (data_02087650[Input::localConsoleID][0] & 0x10) != 0)))) {
				itemStyle = 1;
			} else {
				itemStyle = 2;
				switch (i) {
				case 0:
				case 1:
					if (selection == 0)
						itemStyle = inactive0;
					break;
				case 2:
				case 3:
					if (selection == 1)
						itemStyle = inactive1;
					break;
				case 4:
				case 5:
					if (selection == 2)
						itemStyle = inactive2;
					break;
				case 6:
				case 7:
					if (selection == 3)
						itemStyle = inactive3;
					break;
				}
			}
			func_0200419c(
				data_ov052_0215b7ec[i], data_ov052_0215b728[i & 1],
				0, itemStyle, 0, 0, 0, 0, 0, 0, mainY
			);
		}

		if (selection == 4) {
			u8 currentState = state;
			if (currentState == 4 || currentState == 0x12 || currentState == 0x11 || (u8)(currentState + 0xf4) <= 1)
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
	System::setSubBGPosition(2, mainBackgroundPosition.x >> 12, -mainY);
}

void MPLevelSelectScene::func_ov052_0215515c()
{
	state = 3;
	selectionBackgroundPosition.x = mainBackgroundPosition.x;
	selectionBackgroundPosition.y = mainBackgroundPosition.y;
}

void MPLevelSelectScene::func_ov052_021551e4()
{
	if (func_0200e7ac(1) != 0) {
		func_0200e7b8(1);
		state = 11;
	}
}

void MPLevelSelectScene::func_ov052_021549f8()
{
	REG_DISPCNT_SUB = (REG_DISPCNT_SUB & ~0x1f00) | 0x1e00;
	state = 6;
	func_ov052_021539c8(this);
}

void MPLevelSelectScene::func_ov052_02154698()
{
	if (GlobalFader.fadedOut() != 0) {
		if (state == 8) {
			state = 9;
		} else {
			state = 0;
		}
	}
}

void MPLevelSelectScene::func_ov052_021546d0()
{
	s8 timer = selectionTimer;
	if (timer != 0)
		goto decrement_timer;
	if (confirmationVisible == 0)
		goto no_selection;
	REG_DISPCNT_SUB = (REG_DISPCNT_SUB & ~0x1f00) | 0x1c00;
	selection = 0;
	data_ov052_0215c890 = 0;
	state = 0xf;
	u32 value = func_02046c78() ? 0xa : 0xb;
	func_02017e14(&textLabel, &value);
	return;

no_selection:
	func_ov052_02153a1c(this);
	return;

decrement_timer:
	selectionTimer = timer - 1;
}

void MPLevelSelectScene::func_ov052_0215476c()
{
	u8 previousState;
	u32 previousSelection = data_ov052_0215c890;
	previousState = state;
	BOOL connected = data_0208b4f0 != 0 && data_0208b4ec != 0;

	if (connected != FALSE) {
		u32 selection = Layout::bnbl[1]->getBox(data_0208b4e8, data_0208b4f4);
		switch (selection) {
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
			data_ov052_0215c890 = selection;
			state = 7;
			func_ov052_02153760(this);
			break;
		case 5:
			if (data_ov052_0215c884 == 0) {
				confirmationVisible = 1;
				state = 7;
			}
			break;
		}
	} else {
		u16 input = data_02087650[0][1];
		if ((input & 2) != 0) {
			if (data_ov052_0215c884 == 0) {
				confirmationVisible = 1;
				state = 7;
			}
		} else if ((input & 1) != 0) {
			state = 7;
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
	if (previousState != state) {
		selectionTimer = 0x1e;
		if (confirmationVisible != 0) {
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
	if (mainBackgroundPosition.y != 0) {
		selectionBackgroundPosition.x = mainBackgroundPosition.x;
		selectionBackgroundPosition.y = mainBackgroundPosition.y;
		return;
	}
	func_ov052_021539c8(this);
	state = 0x13;
}

void MPLevelSelectScene::func_ov052_02154a60()
{
	func_ov052_02155ba8();
	REG_DISPCNT_SUB = (REG_DISPCNT_SUB & ~0x1f00) | 0x1c00;
	u32 size = tilesetSize;
	void *address = (void *)NDS::Graphics::subBackground1Map();
	NDS::Memory::fill8(address, 0, size);
	mainBackgroundPosition.x = 0x100000;
	func_ov052_02153780(this);
	state = 0xe;
	confirmationVisible = 0;
	u32 value = func_02046c78() ? 0xc : 0xd;
	func_02017e14(&textLabel, &value);
	selectionBackgroundPosition.x = mainBackgroundPosition.x;
	selectionBackgroundPosition.y = mainBackgroundPosition.y;
}

void MPLevelSelectScene::func_ov052_021554dc()
{
	if (transitionTimer == 0) {
		Math::expLerp(&mainBackgroundPosition.y, 0, 0x400, 0x28000, 0x5000);
	}
}

void MPLevelSelectScene::func_ov052_0215454c()
{
	if (Math::expLerp(&mainBackgroundPosition.y, -0xa000, 0x400, 0x28000, 0x1000) == 0) {
		state = 0x10;
	}
	selectionBackgroundPosition.x = mainBackgroundPosition.x;
	selectionBackgroundPosition.y = mainBackgroundPosition.y;
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
	GlobalFader.enableMainScreenFading();
	GlobalFader.func_02007bfc();
	data_02085a58 = 0;
	func_02011e3c(0x1e);
}

void MPLevelSelectScene::func_ov052_021544a0()
{
	if (Math::expLerp(&mainBackgroundPosition.y, 0x100000, 0x300, 0x28000, 0x3000) == 0) {
		func_ov052_02155b00();
		mainBackgroundPosition.x = 0;
		NDS::Memory::copy8(
			tilesetData,
			(void *)NDS::Graphics::subBackground1Map(),
			tilesetSize
		);
		if (func_02046c78() == 0)
			goto primary_display;
		REG_DISPCNT_SUB = (REG_DISPCNT_SUB & ~0x1f00) | 0x1e00;
		goto display_configured;

	primary_display:
		REG_DISPCNT_SUB = (REG_DISPCNT_SUB & ~0x1f00) | 0x1c00;

	display_configured:
		state = 0xb;
	}
	selectionBackgroundPosition.x = mainBackgroundPosition.x;
	selectionBackgroundPosition.y = mainBackgroundPosition.y;
}

void MPLevelSelectScene::func_ov052_02154b64()
{
	if (Math::expLerp(&mainBackgroundPosition.y, -0xa000, 0x300, 0x28000, 0x3000) == 0) {
		state = 0xd;
	}
	selectionBackgroundPosition.x = mainBackgroundPosition.x;
	selectionBackgroundPosition.y = mainBackgroundPosition.y;
}

void MPLevelSelectScene::func_ov052_02154bb4()
{
	s8 timer = selectionTimer;
	if (timer == 0) {
		if (data_ov052_0215c888 == 0) {
			data_ov052_0215c890 = (Wifi::random() & 0x7fff) * 5 >> 15;
			func_ov052_02153a1c(this);
		} else {
			state = 0xc;
		}
	} else {
		selectionTimer = timer - 1;
	}
	selectionBackgroundPosition.x = mainBackgroundPosition.x;
	selectionBackgroundPosition.y = mainBackgroundPosition.y;
}

void MPLevelSelectScene::func_ov052_02154af4()
{
	if (Math::expLerp(&mainBackgroundPosition.y, 0x100000, 0x300, 0x28000, 0x3000) == 0) {
		NDS::Memory::copy8((void *)0x050004ba, (void *)0x050004b4, 6);
		state = 5;
		func_ov052_02155b00();
	}
	selectionBackgroundPosition.x = mainBackgroundPosition.x;
	selectionBackgroundPosition.y = mainBackgroundPosition.y;
}

void MPLevelSelectScene::func_ov052_02155178()
{
	func_ov052_021554dc();
	selectionBackgroundPosition.x = mainBackgroundPosition.x;
	selectionBackgroundPosition.y = mainBackgroundPosition.y;
	if (mainBackgroundPosition.y != 0) {
		return;
	}
	state = 2;
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
	selectionBackgroundPosition.x = mainBackgroundPosition.x;
	selectionBackgroundPosition.y = mainBackgroundPosition.y;
	if (GlobalFader.fadedIn() == 0) {
		return;
	}
	if (data_02085a84 == 0) {
		state = 0xb;
		return;
	}
	func_0200e7c4(1);
	state = 1;
}

void MPLevelSelectScene::func_ov052_02154c34()
{
	i32 offset = -transitionTimer << 12;
	selectionBackgroundPosition.x = offset;
	selectionBackgroundPosition.y = offset;
	if (transitionTimer == 0) {
		state = 4;
		selectionTimer = 0x1e;
	}
}

void MPLevelSelectScene::func_ov052_02154c68()
{
	i32 offset = (transitionTimer - 3) << 12;
	selectionBackgroundPosition.x = offset;
	selectionBackgroundPosition.y = offset;
	if (transitionTimer == 0) {
		state = 0x12;
		transitionTimer = 3;
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
	oldState = state;
	oldSelection = selection;
	BOOL connected = data_0208b4f0 != 0 && data_0208b4ec != 0;

	if (connected != FALSE) {
		u32 action = Layout::bnbl[1]->getBox(data_0208b4e8, data_0208b4f4);
		switch (action) {
		case 0:
			break;
		case 2:
			selection = 0;
			if (data_ov052_0215c894 == 0)
				data_ov052_0215c894 = 2;
			else
				data_ov052_0215c894--;
			break;
		case 3:
			selection = 0;
			if (data_ov052_0215c894 == 2)
				data_ov052_0215c894 = 0;
			else
				data_ov052_0215c894++;
			break;
		case 4:
			selection = 1;
			if (data_ov052_0215c88c == 0)
				data_ov052_0215c88c = 2;
			else
				data_ov052_0215c88c--;
			break;
		case 5:
			selection = 1;
			if (data_ov052_0215c88c == 2)
				data_ov052_0215c88c = 0;
			else
				data_ov052_0215c88c++;
			break;
		case 6:
			selection = 2;
			if (data_ov052_0215c89c == 0)
				data_ov052_0215c89c = 2;
			else
				data_ov052_0215c89c--;
			break;
		case 7:
			selection = 2;
			if (data_ov052_0215c89c == 2)
				data_ov052_0215c89c = 0;
			else
				data_ov052_0215c89c++;
			break;
		case 8:
		case 9:
			selection = 3;
			data_ov052_0215c888 ^= 1;
			break;
		case 1:
			state = 0x11;
			selection = 4;
			break;
		}
	} else {
		u16 input = data_02087650[0][1];
		if ((input & 1) != 0) {
			if (oldSelection == 4)
				state = 0x11;
			else
				selection++;
		} else if ((input & 0x80) != 0) {
			if (oldSelection != 4)
				selection++;
		} else if ((input & 0x40) != 0) {
			if (oldSelection != 0)
				selection--;
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

	if (oldState != state) {
		transitionTimer = 3;
		NDS::Memory::copy8((void *)0x05000474, (void *)0x050004b4, 6);
		func_02012398(0xe9, nullptr);
	} else {
		if (oldOption0 != data_ov052_0215c894 ||
			oldOption1 != data_ov052_0215c88c ||
			oldOption2 != data_ov052_0215c89c ||
			oldToggle != data_ov052_0215c888 ||
			oldSelection != selection) {
			func_02012398(0xe5, nullptr);
		}
	}

	if (selection >= 4)
		System::setSubBGPosition(0, 0, 0x40);
	else
		System::setSubBGPosition(0, 0, selection * -0x24);

	if (oldSelection != selection) {
		if (selection == 4)
			NDS::Memory::copy8((void *)0x05000454, (void *)0x050004b4, 6);
		else if (oldSelection == 4)
			NDS::Memory::copy8((void *)0x050004ba, (void *)0x050004b4, 6);
	}

	selectionBackgroundPosition.x = mainBackgroundPosition.x;
	selectionBackgroundPosition.y = mainBackgroundPosition.y;
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
