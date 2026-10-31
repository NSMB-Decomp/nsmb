#include "SaveScene.hpp"

void *SaveScene::create()
{
	return new SaveScene();
}

// 0x020ee340
u32 data_ov008_020ee340;

s32 SaveScene::onCreate() {
	func_0200f3d8();
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
	GX_SetBankForTex(6);
	GX_SetBankForTexPltt(0x10);
	Nitro::func_02061ac4(8);
	GX_SetBankForOBJ(1);
	GX_SetBankForBGExtPltt(0x40);
	Nitro::func_0206178c(0x20);
	GX_SetGraphicsMode(1,0,1);
	data_02085a88 = 0x12;
	REG_POWER_CNT |= 0x8000;
	GX_SetOBJVRamModeChar(0); // REG_DISPCNT &= 0xffcfffef;
	GX_SetBGCharOffset(0); // REG_DISPCNT &= ~0x07000000;
	GX_SetBGScrOffset(0x08000000); // REG_DISPCNT = (REG_DISPCNT & ~0x38000000) | 0x08000000;
	G2_SetBG1Priority(0); // REG_BG1CNT &= ~3;
	G2_SetBG1Control(0, 0, 0x28, 4, 0); // REG_BG1CNT = (REG_BG1CNT & 0x43) | 0x2810;
	G2_BG1Mosaic(FALSE); // REG_BG1CNT &= ~0x40;
	*(s32 *)0x04000014 = 0; // TODO: REG_BG1HOFS = 0
	Nitro::func_02066edc(0, G2_GetBG1ScrPtr(), 0x800);
	REG_DISPCNT_SUB &= 0xffffe0ff;
	Nitro::func_02063a88((u32)&data_ov008_020ee340, 0, 2);
	Nitro::func_020622ec(&REG_BLDCNT_SUB,0x3f,0xfffffff0);
	this->_64 = 0;
	this->index = 0;
	func_02011c34(0xffffffff);
	return 1;
}

// TODO: 0x020cc478
s32 SaveScene::onDestroy() {
	return 1;
}

// TODO: 0x020cc474
void SaveScene::pendingDestroy() {

}

s32 SaveScene::onRender() {
	return 1;
}

s32 SaveScene::onUpdate() {
	if (!GlobalFader.isComplete()) {
		return 1;
	}

	if ((u16)(data_02087650[Input::localConsoleID][0] & 0xc) == 0xc) {
		func_020131fc(2, 0);
	} else if (Input::consoleKeys[Input::localConsoleID][0] & 1) {
		if (this->index < 3) {
			func_02012e08(this->index, 0, &save);
			func_020131fc(func_02012934(this->index), save.game.currentWorld);
		} else {
			for (s32 i = 0; i < 3; i++) {
				func_02012ee0(i, &save);
				func_02012ee0(i + 3, &save);
			}
		}
	} else if (Input::consoleKeysRepeated[0] & 0x80) {
		this->index++;
		if (this->index > 3) {
			this->index = 0;
		}
	} else if (Input::consoleKeysRepeated[0] & 0x40) {
		this->index--;
		if (this->index < 0) {
			this->index = 3;
		}
	}
	return 1;
}

// 0x020e5820
ObjectProfile Object7_Profile = { SaveScene::create, 7, 15 };
