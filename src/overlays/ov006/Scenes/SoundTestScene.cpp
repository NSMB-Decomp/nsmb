#include "../../../Scenes/SoundTestScene.hpp"
#include <nds/input_buttons.hpp>


void *SoundTestScene::create()
{
	return new SoundTestScene();
}

s32 SoundTestScene::onCreate()
{
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
	NDS::Graphics::assignTextureBank(3);
	NDS::Graphics::assignTexturePaletteBank(0x10);
	NDS::Graphics::assignMainBackgroundBank(4);
	NDS::Graphics::assignMainObjectBank(0x60);
	NDS::Graphics::assignLcdcBank(8);
	NDS::Graphics::setMainDisplayMode(1, 0, 1);
	data_02085a88 = 0x12;
	// TODO: Turn these into macros?
	REG_DISPCNT &= ~0x7000000;
	REG_DISPCNT = REG_DISPCNT & ~0x38000000 | 0x8000000;
	REG_BG1CNT = (REG_BG1CNT & ~0x3);
	REG_BG1CNT = (REG_BG1CNT & 0x43) | 0x2810;
	REG_BG1CNT &= ~0x40;
	REG_BG1OFS = 0;
	u32 uVar1 = NDS::Graphics::mainBackground1Map();
	NDS::Memory::clearFast(0, uVar1, 0x800);
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

i32 SoundTestScene::onUpdate()
{
	if (!GlobalFader.fadedIn()) {
		return true;
	}

	if ((u16)(data_02087650[Input::localConsoleID][0] &
			(NDS_PAD_BUTTON_SELECT | NDS_PAD_BUTTON_START)) ==
		(NDS_PAD_BUTTON_SELECT | NDS_PAD_BUTTON_START)) {
		func_02011e3c(0x1e);
		func_020131fc(2, 0);
	}

	func_0200a42c((u32)&this->_64, 2);

	switch (this->_64) {
	case 0: {
		func_0200a3d0((u32)&this->_68, 0x70);
		u16 pressedButtons = Input::consoleKeys[Input::localConsoleID][0];
		if (pressedButtons & NDS_PAD_BUTTON_B) {
			func_02011d40();
		} else if (pressedButtons & NDS_PAD_BUTTON_A) {
			func_02011e7c(this->_68, 0);
		}
		break;
	}
	case 1: {
		func_0200a3d0((u32)&this->_6c, 0x1c3);
		u16 pressedButtons = Input::consoleKeys[Input::localConsoleID][0];
		if (pressedButtons & NDS_PAD_BUTTON_B) {
			func_02011d40();
		} else if (pressedButtons & NDS_PAD_BUTTON_A) {
			func_02012398(this->_6c, 0);
		} else if (pressedButtons & NDS_PAD_BUTTON_X) {
			func_02012290(this->_6c, 0);
		}
		break;
	}
	}

	return true;
}
