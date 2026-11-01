#include "BootScene.hpp"
#include "../system/app.hpp"

void func_02018ac0();
void func_02006444(u32);
u16 func_02043398(u16 *);
u8 func_02004c30();
bool func_020130b4();
extern u32 data_0203996c;
extern u8 data_0208b4c4;
extern u8 data_0208b4c8[][4];

struct BGScreen {
	u16 tiles[32][32];
};

BootScene::BootScene()
{
}
void *BootScene::create()
{
	return new BootScene();
}

s32 BootScene::onCreate()
{
	u32 param_r0;
	u32 local_r1;
	u32 local_r2;
	u32 local_r3;
	u32 tmp_call0;
	u32 tmp_call1;

	GlobalFader.setupSceneFading(0x0, 0x1, 0x0);
	if ((App::getBootScene() == 0x0)) {
		func_0201325c();
		Nitro::func_02061ac4(0x1);
		Nitro::func_02061958(0x2);
		Nitro::func_020613c8(0x4);
		Nitro::func_0206134c(0x8);
		REG_DISPCNT &= 0xffcfffef;
		REG_DISPCNT_SUB &= 0xffcfffef;
		Nitro::func_02060d78(0x1, 0x0, 0x0);
		Nitro::func_02060d5c(0x0);
		REG_DISPCNT = ((REG_DISPCNT & ~0x38000000) | 0x8000000);
		REG_POWER_CNT = ((REG_POWER_CNT & ~0x20e) | 0x20e);
		Nitro::EnableDisplay();
		GXS_DispOn();	      // REG_DISPCNT_SUB |= 0x10000
		G2_SetBG0Priority(1); // REG_BG0CNT = (REG_BG0CNT & (~0x3)) | 0x1;
		REG_BG0CNT = (REG_BG0CNT & 0x43) | 0x1700;
		REG_BG0CNT = REG_BG0CNT & ~0x40;
		REG_BG0OFS = 0x0;
		Nitro::func_02067258(&data_ov001_020cd144, (void *)Nitro::func_02061ff8());
		Nitro_::func_02063af0((u16 *)&data_ov001_020cd734, 0x0, 0x200);
		Nitro::func_02067258(&data_ov001_020cd934, (void *)Nitro::func_020622b8());
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
		Nitro::func_02067258(&data_ov001_020cdb24, (void *)Nitro::func_02061ee4());
		Nitro::func_02063a88((u32)&data_ov001_020ce84c, 0x0, 0x20);
		Nitro::func_02067258(&data_ov001_020ce86c, (void *)Nitro::func_02062138());
		data_02085a88 = 0x1;
		REG_DISPCNT_SUB = ((REG_DISPCNT_SUB & ~0x1f00) | 0x400);
	}

	if (App::getBootScene() == 0x0) {
		this->_78 = 0x78;
	} else {
		this->_78 = 0;
	}
	this->step = 0x0;
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
	u8 id = Input::localConsoleID;
	u16 pressed;
	u32 frames;
	frames = data_0203996c;
	pressed = Input::consoleKeys[id][0];
	func_02043398(&this->_78);

	if (data_ov001_020cebc0 == 0) {
		data_ov001_020cebc0 = func_02004c30();
		if (data_ov001_020cebc0 == 0) {
			return true;
		}
		func_02018ac0();
	}

	if (GlobalFader.isComplete()) {
		if (this->_7c != 0) {
			this->_7c -= frames;
			if (this->_7c == 0) {
				this->func_ov001_020cc4b4();
			}
		}

		if (this->_7d != 0) {
			this->_7d -= frames;
			return true;
		}

		switch (this->step) {
		case 0:
		case 7:
			if (this->_78 == 0) {
				this->func_ov001_020cc328();
				if (this->_68 != 0) {
					Scene::switchToCorruptedSave(6);
				} else if (this->_70 != 0) {
					Scene::switchToCorruptedSave(8);
				} else if (this->_6c != 0) {
					if (this->_6c & 0x1000) {
						Scene::switchToCorruptedSave(this->_6c | 7);
					} else {
						Scene::switchToCorruptedSave(this->_6c | 5);
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
				GlobalFader._5c4 = 0;
				GlobalFader.targetBrightness = -16;
			}
			break;

		case 1:
		case 3: {
			bool touched = false;
			if (data_0208b4c8[data_0208b4c4][0] != 0 && data_0208b4c8[data_0208b4c4][1] != 0) {
				touched = true;
			}
			if (!touched && !(pressed & 0x39)) {
				break;
			}
			bool touched2 = data_0208b4c8[data_0208b4c4][0] != 0 && data_0208b4c8[data_0208b4c4][1] != 0;
			if ((touched2 && (u8)(data_0208b4c8[data_0208b4c4][2] - 0x28) < 0x50 && (u8)(data_0208b4c8[data_0208b4c4][3] - 0x98) < 0x20) || (pressed & 0x20)) {
				if (this->_7b == 0) {
					this->_7c = 0x10;
				}
				this->_7b = 0;
				this->func_ov001_020cc4b4();
				func_02012398(0xe5, NULL);
				if ((u8)(data_0208b4c8[data_0208b4c4][2] - 0x28) < 0x50 && (u8)(data_0208b4c8[data_0208b4c4][3] - 0x98) < 0x20) {
					this->_7d = 0x20;
					if (this->step == 1) {
						this->step = 2;
					} else {
						this->step = 4;
					}
				}
				break;
			}
			bool touched3 = data_0208b4c8[data_0208b4c4][0] != 0 && data_0208b4c8[data_0208b4c4][1] != 0;
			if ((touched3 && (u8)(data_0208b4c8[data_0208b4c4][2] - 0x88) < 0x50 && (u8)(data_0208b4c8[data_0208b4c4][3] - 0x98) < 0x20) || (pressed & 0x10)) {
				if (this->_7b == 1) {
					this->_7c = 0x10;
				}
				this->_7b = 1;
				this->func_ov001_020cc4b4();
				func_02012398(0xe5, NULL);
				if ((u8)(data_0208b4c8[data_0208b4c4][2] - 0x88) < 0x50 && (u8)(data_0208b4c8[data_0208b4c4][3] - 0x98) < 0x20) {
					this->_7d = 0x20;
					this->step = 6;
				}
			} else if (pressed & 0x9) {
				this->_7c = 0x10;
				this->_7d = 0x20;
				this->func_ov001_020cc4b4();
				func_02012398(0xe5, NULL);
				if (this->_7b == 0) {
					if (this->step == 1) {
						this->step = 2;
					} else {
						this->step = 4;
					}
				} else {
					this->step = 6;
				}
			}
			break;
		}

		case 2:
			this->_7b = 1;
			this->func_ov001_020cc4b4();
			this->step = 3;
			break;

		case 4:
			G2S_SetBG1Control(0, 0, 2, 6, 0); // REG_BG1CNT_SUB = (REG_BG1CNT_SUB & 0x43) | 0x218;
			this->_7e = 0x78;
			this->step = 5;
			break;

		case 5:
			if (this->_7e != 0) {
				this->_7e -= frames;
				if (this->_7e == 0x3c) {
				} else if (this->_7e == 0) {
					u32 plane = ((REG_DISPCNT_SUB & 0x1f00) >> 8);
					plane &= ~0x3;
					plane |= 0x4;
					GXS_SetVisiblePlane(plane);
					this->_78 = 0x3c;
					this->step = 7;
				}
			}
			break;

		case 6: {
			u32 plane = ((REG_DISPCNT_SUB & 0x1f00) >> 8);
			plane &= ~0x3;
			plane |= 0x4;
			GXS_SetVisiblePlane(plane);
			this->_78 = 0x3c;
			this->step = 0;
			break;
		}

		case 9:
			break;

		case 8:
			this->_78 -= frames;
			if (this->_78 == 0) {
				if (!func_020130b4()) {
					this->step = 9;
				} else {
					GlobalFader._5c4 = 0;
					GlobalFader.targetBrightness = -16;
					func_020131fc(4, 0);
				}
			}
			break;
		}
	}

	return true;
}

void BootScene::func_ov001_020cc4b4()
{
	for (s32 i = 0; i < 2; i++) {
		u16 palette = (i == this->_7b && this->_7c == 0) ? 0x2000 : 0x1000;

		// Each option is a 16x4 tile box starting at row 19 of the sub BG0 screen
		u32 column = i * 16;
		BGScreen *screen = (BGScreen *)Nitro::func_02062244();
		u16 *row = &screen->tiles[19][column];
		for (s32 x = 0; x < 16; x++) {
			row[x] = palette + (row[x] & 0x3ff);
			row[x + 32] = palette + (row[x + 32] & 0x3ff);
			row[x + 64] = palette + (row[x + 64] & 0x3ff);
			row[x + 96] = palette + (row[x + 96] & 0x3ff);
		}
	}
}

BootScene::~BootScene()
{
}
