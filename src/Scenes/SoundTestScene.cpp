#include "SoundTestScene.hpp"

void func_02011b64();

void *SoundTestScene::create()
{
	return new SoundTestScene();
}

s32 SoundTestScene::onCreate()
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
	// TODO: Turn these into macros?
	REG_DISPCNT &= ~0x7000000;
	REG_DISPCNT = REG_DISPCNT & ~0x38000000 | 0x8000000;
	REG_BG1CNT = (REG_BG1CNT & ~0x3);
	REG_BG1CNT = (REG_BG1CNT & 0x43) | 0x2810;
	REG_BG1CNT &= ~0x40;
	REG_BG1OFS = 0;
	Nitro::func_02066edc(0, G2_GetBG1ScrPtr(), 0x800);
	this->_64 = 0;
	this->_68 = 0;
	this->_6c = 0;
	func_02011b64();
	return true;
}

s32 SoundTestScene::onDestroy()
{
	func_02011d40();
	return true;
}
void SoundTestScene::pendingDestroy()
{
}

s32 SoundTestScene::onRender()
{
	return true;
}

s32 SoundTestScene::onUpdate()
{
	if (!GlobalFader.isComplete()) {
		return 1;
	}

	if ((u16)(data_02087650[Input::localConsoleID][0] & 0xc) == 0xc) {
		func_02011e3c(0x1e);
		func_020131fc(2, 0);
	}

	func_0200a42c(&this->_64, 2);

	switch (this->_64) {
	case 0: {
		func_0200a3d0(&this->_68, 0x70);
		u16 keys = Input::consoleKeys[Input::localConsoleID][0];
		if (keys & 0x2) {
			func_02011d40();
		} else if (keys & 0x1) {
			func_02011e7c(this->_68, 0);
		}
		break;
	}
	case 1: {
		func_0200a3d0(&this->_6c, 0x1c3);
		u16 keys = Input::consoleKeys[Input::localConsoleID][0];
		if (keys & 0x2) {
			func_02011d40();
		} else if (keys & 0x1) {
			func_02012398(this->_6c, NULL);
		} else if (keys & 0x400) {
			func_02012290(this->_6c, 0);
		}
		break;
	}
	}
	return 1;
}

ObjectProfile SoundTestScene::Profile = {SoundTestScene::create, 0x10, 0x17};
