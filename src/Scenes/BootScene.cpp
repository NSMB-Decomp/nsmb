#include "BootScene.hpp"
#include "../system/app.hpp"
#include <nds/graphics_controls.hpp>
#include <nds/input_buttons.hpp>
#include <nsmb/arm9/symbols.hpp>

ObjectProfile BootScene::profile = {
	BootScene::create,
	0,
	7,
};

BootScene::BootScene()
{
}
void *BootScene::create()
{
	return new BootScene();
}

i32 BootScene::onCreate() {
	u32 param_r0;
	u32 local_r1;
	u32 local_r2;
	u32 local_r3;
	u32 tmp_call0;
	u32 tmp_call1;

	GlobalFader.setupSceneFading(Fader::FadeOnly, 0x1, 0x0);
	if ((App::getBootScene() == 0x0)) {
		func_0201325c();
		NDS::Graphics::assignMainBackgroundBank(0x1);
		NDS::Graphics::assignMainObjectBank(0x2);
		NDS::Graphics::assignSubBackgroundBank(0x4);
		NDS::Graphics::assignSubObjectBank(0x8);
		REG_DISPCNT &= 0xffcfffef;
		REG_DISPCNT_SUB &= 0xffcfffef;
		NDS::Graphics::setMainDisplayMode(0x1, 0x0, 0x0);
		NDS::Graphics::setSubDisplayMode(0x0);
		REG_DISPCNT = ((REG_DISPCNT & ~0x38000000) | 0x8000000);
		REG_POWER_CNT = ((REG_POWER_CNT & 0xfffffdf1) | 0x20e);
		NDS::Graphics::enableDisplays();
		REG_DISPCNT_SUB |= 0x10000;
		REG_BG0CNT = (REG_BG0CNT & (~0x3)) | 0x1;
		REG_BG0CNT = (REG_BG0CNT & 0x43) | 0x1700;
		REG_BG0CNT &= ~0x40;
		REG_BG0OFS = 0x0;
		NDS::Memory::decompressLz16((u32)&data_ov001_020cd144, NDS::Graphics::mainBackground0Tiles());
		NDS::Graphics::uploadMainBackgroundPalette((u16*)&data_ov001_020cd734, 0x0, 0x200);
		NDS::Memory::decompressLz16((u32)&data_ov001_020cd934, NDS::Graphics::mainBackground0Map());
		REG_BG3CNT &= ~0x03;
		REG_BG3CNT = (REG_BG3CNT & 0x43) | 0x1100;
		REG_BG3CNT &= ~0x40;
		REG_BG3OFS = 0x0;
		REG_BG0CNT_SUB &= ~0x3;
		REG_BG0CNT_SUB &= ~0x40;
		REG_BG0CNT_SUB = (REG_BG0CNT_SUB & 0x43) | 0x18;
		REG_BG0OFS = 0x0;
		REG_BG1CNT_SUB &= ~0x03;
		REG_BG1CNT_SUB &= ~0x40;
		REG_BG1CNT_SUB = (REG_BG1CNT_SUB & 0x43) | 0x118;
		REG_BG1OFS = 0x0;
		REG_BG2CNT_SUB = (REG_BG2CNT_SUB & ~0x3);
		REG_BG2CNT_SUB &= ~0x40;
		REG_BG2CNT_SUB = (REG_BG2CNT_SUB & 0x43) | 0x310;
		REG_BG2OFS = 0x0;
		NDS::Memory::decompressLz16((u32)&data_ov001_020cdb24, NDS::Graphics::subBackground2Tiles());
		NDS::Graphics::uploadSubBackgroundPalette((u32)&data_ov001_020ce84c, 0x0, 0x20);
		NDS::Memory::decompressLz16((u32)&data_ov001_020ce86c, NDS::Graphics::subBackground2Map());
		data_02085a88 = 0x1;
		REG_DISPCNT_SUB = ((REG_DISPCNT_SUB & ~0x1f00) | 0x400);
	}

	if (App::getBootScene() == 0x0) {
		this->_78 = 0x78;
	} else {
		this->_78 = 0;
	}
	this->_7a = 0x0;
	this->_7c = 0x0;
	this->_7d = 0x0;

	func_02006674(0x1);
	if ((App::getBootScene() == 0x0)) {
		func_02011c34(~0x0);
		func_02012398(0xe8, 0x0);
	}

	data_ov001_020cebc0 = func_02004cb8((u32)&App::initBoot, 0x0, 0xf, 0x0, 0x1000);
	if (App::getBootScene() == 0x0) {
		GlobalFader.brightnessFactor[0] = 0x1000;
		GlobalFader.brightnessFactor[1] = 0x1000;
	}

	return true;
}

s32 BootScene::onDestroy()
{
	return true;
}

void BootScene::pendingDestroy()
{
}

s32 BootScene::onRender()
{
	return true;
}

s32 BootScene::onUpdate()
{
	u16 keys;
	u32 step = data_0203996c;
	keys = Input::consoleKeys[Input::localConsoleID][0];

	func_02043398(&_78);

	if (data_ov001_020cebc0 == 0) {
		data_ov001_020cebc0 = func_02004c30();
		if (data_ov001_020cebc0 == 0) {
			return true;
		}

		func_02018ac0();
	}

	if (!GlobalFader.fadedIn()) {
		goto returnTrue;
	}

	if (_7c != 0) {
		_7c -= step;
		if (_7c == 0) {
			func_ov001_020cc4b4();
		}
	}

	if (_7d != 0) {
		_7d -= step;
		return true;
	}

	switch (_7a) {
	case 0:
	case 7:
		if (_78 == 0) {
			func_ov001_020cc328();

			if (_64[1] != 0) {
				Scene::switchToCorruptedSave(6);
			} else if (_64[3] != 0) {
				Scene::switchToCorruptedSave(8);
			} else if (_64[2] != 0) {
				if ((_64[2] & 0x1000) != 0) {
					Scene::switchToCorruptedSave(_64[2] | 7);
				} else {
					Scene::switchToCorruptedSave(_64[2] | 5);
				}
			} else {
				data_02085ad4[0] = save.options.controlOptions;
				func_02006444(save.options.soundMode);

				if (data_02087650[Input::localConsoleID][0] == 0xf03) {
					Scene::switchToCorruptedSave(0xb);
				} else {
					func_020131fc(4, 0);
				}
			}

			GlobalFader.reserved_5c4 = 0;
			GlobalFader.targetBrightness = -16;
		}
		break;

	case 1:
	case 3:
		{
			u32 touchIndex = data_0208b4c4;
			bool touchActive = false;
			u8 touchDown = data_0208b4c8[touchIndex * 4];
			if (touchDown != 0 && data_0208b4c9[touchIndex * 4] != 0) {
				touchActive = true;
			}

			if (touchActive ||
				(keys & (NDS_PAD_BUTTON_A | NDS_PAD_BUTTON_START |
					NDS_PAD_BUTTON_RIGHT | NDS_PAD_BUTTON_LEFT)) != 0) {
				if (touchDown != 0 && data_0208b4c9[touchIndex * 4] != 0) {
					touchActive = true;
				} else {
					touchActive = false;
				}

				if ((touchActive &&
					 (u8)(data_0208b4ca[touchIndex * 4] - 0x28) < 0x50 &&
					 (u8)(data_0208b4cb[touchIndex * 4] - 0x98) < 0x20) ||
					(keys & NDS_PAD_BUTTON_LEFT) != 0) {
					if (_7b == 0) {
						_7c = 0x10;
					}
					_7b = 0;
					func_ov001_020cc4b4();
					func_02012398(0xe5, nullptr);

					if ((u8)(data_0208b4ca[data_0208b4c4 * 4] - 0x28) < 0x50 &&
						(u8)(data_0208b4cb[data_0208b4c4 * 4] - 0x98) < 0x20) {
						_7d = 0x20;
						if (_7a == 1) {
							_7a = 2;
						} else {
							_7a = 4;
						}
					}
				} else {
					if (touchDown != 0 && data_0208b4c9[touchIndex * 4] != 0) {
						touchActive = true;
					} else {
						touchActive = false;
					}

					if ((touchActive &&
						 (u8)(data_0208b4ca[touchIndex * 4] - 0x88) < 0x50 &&
						 (u8)(data_0208b4cb[touchIndex * 4] - 0x98) < 0x20) ||
						(keys & NDS_PAD_BUTTON_RIGHT) != 0) {
						if (_7b == 1) {
							_7c = 0x10;
						}
						_7b = 1;
						func_ov001_020cc4b4();
						func_02012398(0xe5, nullptr);

						if ((u8)(data_0208b4ca[data_0208b4c4 * 4] - 0x88) < 0x50 &&
							(u8)(data_0208b4cb[data_0208b4c4 * 4] - 0x98) < 0x20) {
							_7d = 0x20;
							_7a = 6;
						}
					} else if ((keys & (NDS_PAD_BUTTON_A |
						NDS_PAD_BUTTON_START)) != 0) {
						_7c = 0x10;
						_7d = 0x20;
						func_ov001_020cc4b4();
						func_02012398(0xe5, nullptr);

						if (_7b == 0) {
							if (_7a == 1) {
								_7a = 2;
							} else {
								_7a = 4;
							}
						} else {
							_7a = 6;
						}
					}
				}
			}
		}
		break;

	case 2:
		_7b = 1;
		func_ov001_020cc4b4();
		_7a = 3;
		break;

	case 4:
		NDS::Graphics::configureSubTextBackground1(0, 0, 2, 6, 0);
		_7e = 0x78;
		_7a = 5;
		break;

	case 5:
		if (_7e != 0) {
			_7e -= step;
			if (_7e == 0x3c) {
				break;
			}

			if (_7e == 0) {
				NDS::Graphics::setSubVisiblePlanes(
					(NDS::Graphics::getSubVisiblePlanes() &
						~(NDS_VISIBLE_PLANE_BACKGROUND0 |
							NDS_VISIBLE_PLANE_BACKGROUND1)) |
					NDS_VISIBLE_PLANE_BACKGROUND2);
				_78 = 0x3c;
				_7a = 7;
			}
		}
		break;

	case 6:
		{
			NDS::Graphics::setSubVisiblePlanes(
				(NDS::Graphics::getSubVisiblePlanes() &
					~(NDS_VISIBLE_PLANE_BACKGROUND0 |
						NDS_VISIBLE_PLANE_BACKGROUND1)) |
				NDS_VISIBLE_PLANE_BACKGROUND2);
			_78 = 0x3c;
			_7a = 0;
		}
		break;

	case 8:
		_78 -= step;
		if (_78 == 0) {
			if (func_020130b4() == 0) {
				_7a = 9;
			} else {
				GlobalFader.reserved_5c4 = 0;
				GlobalFader.targetBrightness = -16;
				func_020131fc(4, 0);
			}
		}
		break;

	case 9:
		break;
	}

returnTrue:
	return true;
}

void BootScene::func_ov001_020cc4b4() {
	const u16 BackgroundTileIndexMask = 0x3ff;

	for (s32 blockIndex = 0; blockIndex < 2; blockIndex++) {
		const u16 paletteOffset =
			(blockIndex == _7b && _7c == 0) ? 0x2000 : 0x1000;
		u16 *block = rcast<u16 *>(NDS::Graphics::subBackground1Map()
			+ 0x4c0 + ((blockIndex * 0x10) << 1));

		for (s32 column = 0; column < 0x10; column++) {
			block[column] = paletteOffset + (block[column] & BackgroundTileIndexMask);
			block[column + 0x20] = paletteOffset + (block[column + 0x20] & BackgroundTileIndexMask);
			block[column + 0x40] = paletteOffset + (block[column + 0x40] & BackgroundTileIndexMask);
			block[column + 0x60] = paletteOffset + (block[column + 0x60] & BackgroundTileIndexMask);
		}
	}
}

void BootScene::func_ov001_020cc328()
{
	enum {
		SlotBitBase = 0x100,
		MinigamesBit = 0x800,
		OptionsBit = 0x1000,
	};

	for (s32 clearIndex = 0; clearIndex < 5; clearIndex++) {
		_64[clearIndex] = 0;
	}

	for (s32 slot = 0; slot < 3; slot++) {
		u32 result = func_02012f64(slot, &save);

		if (result == 0) {
			_64[0] |= SlotBitBase << slot;
		} else if (result == 3) {
			if (func_02012ee0(save.options.currentSlot, &save) == 0) {
				_64[3] |= SlotBitBase << slot;
			} else {
				_64[0] |= SlotBitBase << slot;
			}
		} else if (result == 2) {
			_64[2] |= SlotBitBase << slot;
		} else {
			_64[1] |= SlotBitBase << slot;
		}
	}

	u32 result = func_020128c4(&data_02088e24);
	if (result == 0) {
		_64[0] |= MinigamesBit;
	} else if (result == 3) {
		if (func_020128fc() == 0) {
			_64[3] |= MinigamesBit;
		} else {
			_64[0] |= MinigamesBit;
		}
	} else if (result == 2) {
		_64[2] |= MinigamesBit;
	} else {
		_64[1] |= MinigamesBit;
	}

	result = func_02013050(&save.options);
	if (result == 0) {
		_64[0] |= OptionsBit;
	} else if (result == 3) {
		if (func_02013090() == 0) {
			_64[3] |= OptionsBit;
		} else {
			_64[0] |= OptionsBit;
		}
	} else if (result == 2) {
		_64[2] |= OptionsBit;
	} else {
		_64[1] |= OptionsBit;
	}
}

BootScene::~BootScene()
{
}
