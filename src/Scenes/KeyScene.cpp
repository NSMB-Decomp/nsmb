#include "KeyScene.hpp"
#include "nitro/pad.h"

u16 data_ov007_020cc628[6] = {PAD_BUTTON_A, PAD_BUTTON_B, PAD_BUTTON_X, PAD_BUTTON_Y, PAD_BUTTON_L, PAD_BUTTON_R};
u32 data_ov007_020cc634[6] = {0, 1, 10, 11, 9, 8};

void *KeyScene::create()
{
	return new KeyScene();
}

s32 KeyScene::onCreate()
{
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
	GX_SetBankForTex(3);
	GX_SetBankForTexPltt(0x10);
	Nitro::func_02061ac4(4);
	GX_SetBankForOBJ(0x60);
	Nitro::func_02061474(8);
	GX_SetGraphicsMode(1, 0, 1);
	data_02085a88 = 0x12;
	GX_SetBGCharOffset(0);		    // REG_DISPCNT &= ~0x07000000;
	GX_SetBGScrOffset(0x08000000);	    // REG_DISPCNT = (REG_DISPCNT & ~0x38000000) | 0x08000000;
	G2_SetBG1Priority(0);		    // REG_BG1CNT &= ~3;
	G2_SetBG1Control(0, 0, 0x28, 4, 0); // REG_BG1CNT = (REG_BG1CNT & 0x43) | 0x2810;
	G2_BG1Mosaic(FALSE);		    // REG_BG1CNT &= ~0x40;
	*(s32 *)0x04000014 = 0;		    // TODO: REG_BG1HOFS = 0
	Nitro::func_02066edc(0, G2_GetBG1ScrPtr(), 0x800);

	this->_64 = 0;
	for (s32 i = 0; i < 6; i++) {
		s32 j;
		u16 key = data_020876b0[data_ov007_020cc634[i]];
		for (j = 0; j < 6; j++) {
			if (key == data_ov007_020cc628[j]) {
				break;
			}
		}
		if (j == 6) {
			j = 0;
		}
		this->_68[i] = j;
	}
	return 1;
}

s32 KeyScene::onDestroy()
{
	return 1;
}

void KeyScene::pendingDestroy()
{
}

s32 KeyScene::onRender()
{
	return 1;
}

s32 KeyScene::onUpdate()
{
	if (!GlobalFader.isComplete()) {
		return 1;
	}

	if ((u16)(data_02087650[Input::localConsoleID][0] & 0xc) == 0xc) {
		for (s32 i = 0; i < 6; i++) {
			data_020876b0[data_ov007_020cc634[i]] = data_ov007_020cc628[this->_68[i]];
		}
		func_020131fc(2, 0);
	}

	func_0200a42c(&this->_64, 6);
	func_0200a3d0(&this->_68[this->_64], 6);

	s32 j;
	u16 keys = Input::consoleKeys[Input::localConsoleID][0];
	if (keys & 0xf03) {
		for (j = 0; j < 6; j++) {
			if (keys == data_ov007_020cc628[j]) {
				break;
			}
		}
		if (j < 6) {
			this->_68[this->_64] = j;
		}
	}
	return 1;
}

// 0x020cc620
ObjectProfile Object17_Profile = {KeyScene::create, 17, 24};
