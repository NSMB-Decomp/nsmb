#include "Scene8.hpp"

Scene8::Scene8() {};
void *Scene8::create()
{
	return new Scene8();
}

s32 Scene8::onCreate() {
	u32 settings = this->settings;
	data_02085ac4 = settings;
	save.game.currentWorldNode = 0;
	func_0200f3d8();
	data_02085a7c = 0;
	data_02085abc &= ~0x80000000;
	func_02006c7c();
	REG_POWER_CNT = REG_POWER_CNT & 0xfffffdf1 | 0x20e;  // TODO: Unknown Macro
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
  	Nitro::func_02061ac4(8);
  	GX_SetBankForTexPltt(0x10);
  	GX_SetBankForOBJ(0x20);
  	GX_SetBankForBGExtPltt(0x40);
  	GX_SetBankForSubBG(4);
  	Nitro::func_0206134c(0x100);
  	Nitro::func_020612c0(0x80);
	PTR_02085b18 = NULL;
	GX_SetGraphicsMode(1,5,1);
	GX_SetDispSelect(0); // TODO: This may be incorrect - REG_POWER_CNT &= 0x7fff;
	GX_SetOBJVRamModeChar(0x200010); // REG_DISPCNT = REG_DISPCNT & 0xffcfffef | 0x200010;
	Nitro::func_02056f40(2,1);
  	Nitro::func_020571c4(0x10000,1);
    *(s32 *)0x04000000 = (*(s32 *)0x04000000 & 0xFFBFFF9F) | 0x20;
	data_02085a88 = 0x11;
    *(u16 *)0x04000008 = (*(u16 *)0x04000008 & ~3) | 1;
    *(u16 *)0x0400000A = (*(u16 *)0x0400000A & ~3) | 2;
    *(u16 *)0x0400000C = (*(u16 *)0x0400000C & ~3) | 3;
    *(u16 *)0x0400000E &= ~3;
    *(s32 *)0x04000000 = (*(s32 *)0x04000000 & ~0x38000000) | 0x08000000;
    *(s32 *)0x04000000 &= ~0x07000000;
    *(u16 *)0x0400000A = (*(u16 *)0x0400000A & 0x43) | 0xF080;
    *(u16 *)0x0400000C = (*(u16 *)0x0400000C & 0x43) | 0xAC00;
    *(u16 *)0x0400000E = (*(u16 *)0x0400000E & 0x43) | 0xB400;
    *(u16 *)0x04000008 &= ~0x40;
    *(u16 *)0x0400000A &= ~0x40;
    *(u16 *)0x0400000C &= ~0x40;
    *(u16 *)0x0400000E &= ~0x40;
    *(s32 *)0x04000014 = 0;
    *(s32 *)0x04000018 = 0;
    *(s32 *)0x0400001C = 0;
	MIi_CpuClearFast(0, G2_GetBG1ScrPtr(), 0x800);
	Nitro::func_02060d5c(0);
    *(s32 *)0x04001000 = (*(s32 *)0x04001000 & ~0x1F00) | 0x100;
    *(u16 *)0x04001008 &= ~3;
    *(u16 *)0x0400100A = (*(u16 *)0x0400100A & ~3) | 1;
    *(u16 *)0x0400100C = (*(u16 *)0x0400100C & ~3) | 2;
    *(u16 *)0x0400100E = (*(u16 *)0x0400100E & ~3) | 3;
    *(u16 *)0x04001008 = (*(u16 *)0x04001008 & 0x43) | 0x2004;
    *(u16 *)0x0400100E = (*(u16 *)0x0400100E & 0x43) | 0x108;
    *(u16 *)0x04001008 &= ~0x40;
    *(u16 *)0x0400100A &= ~0x40;
    *(u16 *)0x0400100C &= ~0x40;
    *(u16 *)0x0400100E &= ~0x40;
    *(s32 *)0x04001000 &= 0xFFCFFFEF;
    *(s32 *)0x04001010 = 0;
    *(s32 *)0x0400101C = 0;
	MIi_CpuClearFast(0,G2S_GetBG0ScrPtr(),0x800);
	data_02085e0c = 0;
	func_ov008_020cd478();
	func_02009a30(0xc0080787,0,0);
	u32 address = 0x6400000;
	u8 array = 0xff;
	for (s32 i = 0; i < 0x80; i++) {
		MI_CpuCopy8(&array, (void*) address, 1);
		address++;
	}

	data_02085c24 = 0x10;
	data_02085c34 = 0x37;
	data_02085c30 = 0x10;
	data_02085c2c = 0x10;

	address = (u32)G2S_GetBG0ScrPtr();
	array = 0;
	for (s32 i = 0; i < 0x20; i++) {
		MI_CpuCopy8(&array, (void*) address, 1);
		address++;
	}
	DAT_020caa38 = Object::spawnObject(0x13e,(Base*)this,0,0);
	Actor::spawnActor(0x13d,settings,0,0,0,0);
	func_02011c34(0xffffffff);
	return true;
};

s32 Scene8::onDestroy() {
	FS::Cache::clear();
	func_02011d40();
	return true;
}


void Scene8::pendingDestroy()
{
}

s32 Scene8::onRender()
{
	return true;
};

void func_02011e3c(u32);
void func_020131fc(u32, u32);
u16 data_02087650[2][2];
s32 Scene8::onUpdate()
{
	if ((u16)(data_02087650[Input::localConsoleID][0] & 0xc) == 0xc) {
		func_02011e3c(0x1e);
		func_020131fc(2, 0);
		return true;
	}
	return true;
};

Scene8::~Scene8() {

};
