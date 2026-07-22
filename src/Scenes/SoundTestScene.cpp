#include "SoundTestScene.hpp"


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
	u32 local_r0;
	u32 local_r1;
	if ((GlobalFader.fadedIn() == 0x0)) {
		return 0x1;
	}
	local_r0 = ((((*rcast<u16 *>(((u32)&data_02087650 + ((*rcast<u8 *>(&Input::localConsoleID)) << 0x2)))) & 0xc) << 0x10) >> 0x10);
	if ((local_r0 == 0xc)) {
		func_02011e3c(0x1e);
		func_020131fc(0x2, 0x0);
	}
	func_0200a42c(this->_64, 0x2);

	if ((this->_64 != 0x0)) {
		func_0200a3d0(this->_68, 0x70);
		local_r0 = ((*rcast<u8 *>(&Input::localConsoleID)) << 0x2);
		local_r1 = (*rcast<u16 *>(((u32)&Input::consoleKeys + local_r0)));
		local_r0 = (local_r1 & 0x2);
		if (((local_r1 & 0x2) != 0x0)) {
			local_r0 = func_02011d40();
		} else {
			local_r0 = (local_r1 & 0x1);
			if (((local_r1 & 0x1) != 0x0)) {
				local_r0 = func_02011e7c(this->_68, 0x0);
			}
		}
	} else {
		if ((local_r0 != 0x1)) {
			func_0200a3d0(this->_6c, 0x1c3);
			local_r0 = ((*rcast<u8 *>(&Input::localConsoleID)) << 0x2);
			local_r1 = (*rcast<u16 *>(((u32)&Input::consoleKeys + local_r0)));
			local_r0 = (local_r1 & 0x2);
			if (((local_r1 & 0x2) != 0x0)) {
				func_02011d40();
			} else {
				local_r0 = (local_r1 & 0x1);
				if (((local_r1 & 0x1) != 0x0)) {
					func_02012398(this->_6c, 0x0);
				} else {
					local_r0 = (local_r1 & 0x400);
					if (((local_r1 & 0x400) != 0x0)) {
						func_02012290(this->_6c, 0x0);
					}
				}
			}
		}
	}
	return 0x1;
}
