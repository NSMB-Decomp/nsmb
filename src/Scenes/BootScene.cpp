#include "BootScene.hpp"
#include "../system/app.hpp"

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
		REG_POWER_CNT = ((REG_POWER_CNT & 0xfffffdf1) | 0x20e);
		Nitro::EnableDisplay();
		REG_DISPCNT_SUB |= 0x10000;
		REG_BG0CNT = (REG_BG0CNT & (~0x3)) | 0x1;
		REG_BG0CNT = (REG_BG0CNT & 0x43) | 0x1700;
		REG_BG0CNT &= ~0x40;
		REG_BG0OFS = 0x0;
		Nitro::func_02067258((u32)&data_ov001_020cd144, Nitro::func_02061ff8());
		Nitro_::func_02063af0((u16*)&data_ov001_020cd734, 0x0, 0x200);
		Nitro::func_02067258((u32)&data_ov001_020cd934, Nitro::func_020622b8());
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
		Nitro::func_02067258((u32)&data_ov001_020cdb24, Nitro::func_02061ee4());
		Nitro::func_02063a88((u32)&data_ov001_020ce84c, 0x0, 0x20);
		Nitro::func_02067258((u32)&data_ov001_020ce86c, Nitro::func_02062138());
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
}

i32 BootScene::func_ov001_020cc4b4() {
	u32 local_r0;
	u32 local_r1;
	u32 local_r2;
	u32 local_r4;
	u32 local_r5;
	u32 local_r6;
	u32 local_r7;
	u32 local_r8;
	u32 local_r9;
	u32 local_r10;
	u32 local_r11;
	local_r9 = 0x0;
	local_r10 = (u32)this;
	local_r7 = 0x0;
	local_r11 = 0x0;
	local_r5 = 0x1000;
	local_r6 = 0x2000;
	local_r4 = 0x3ff;
	while (true) {
		u32 tmp_call0;
		local_r0 = (*rcast<u8*>((local_r10 + 0x7b)));
		if ((local_r9 != local_r0)) {
			local_r0 = local_r5;
		} else {
			bool tmp_cond0;
			local_r0 = ((tmp_cond0 = ((*rcast<u8*>((local_r10 + 0x7c))) == 0x0)) ? local_r6 : (*rcast<u8*>((local_r10 + 0x7c))));
			if (tmp_cond0) {
			} else {
				local_r0 = local_r5;
			}
		}
		local_r0 = (local_r0 << 0x10);
		local_r8 = (local_r0 >> 0x10);
		(tmp_call0 = Nitro::func_02062244(local_r0));
		local_r0 = (tmp_call0 + 0x4c0);
		local_r1 = local_r11;
		local_r2 = (local_r0 + (local_r7 << 0x1));
		do {
			u32 frozen_r1 = local_r1;
			local_r0 = (local_r2 + (local_r1 << 0x1));
			local_r1 = (local_r1 + 0x1);
			(*rcast<u16*>((local_r2 + (frozen_r1 << 0x1)))) = (local_r8 + ((*rcast<u16*>((local_r2 + (frozen_r1 << 0x1)))) & local_r4));
			(*rcast<u16*>((local_r0 + 0x40))) = (local_r8 + ((*rcast<u16*>((local_r0 + 0x40))) & local_r4));
			(*rcast<u16*>((local_r0 + 0x80))) = (local_r8 + ((*rcast<u16*>((local_r0 + 0x80))) & local_r4));
			(*rcast<u16*>((local_r0 + 0xc0))) = (local_r8 + ((*rcast<u16*>((local_r0 + 0xc0))) & local_r4));
		} while ((local_r1 < 0x10));
		local_r9 = (local_r9 + 0x1);
		local_r7 = (local_r7 + 0x10);
		if ((local_r9 < 0x2)) {
		} else {
			break;
		}
	}
	return local_r0;
}

BootScene::~BootScene()
{
}
