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
    REG_DISPCNT = (REG_DISPCNT & 0xFFBFFF9F) | 0x20;
	data_02085a88 = 0x11;
    G2_SetBG0Priority(1); //REG_BG0CNT = (REG_BG0CNT & ~3) | 1;
    G2_SetBG1Priority(2); //REG_BG1CNT = (REG_BG1CNT & ~3) | 2;
    G2_SetBG2Priority(3); //REG_BG2CNT = (REG_BG2CNT & ~3) | 3;
    G2_SetBG3Priority(0); //REG_BG3CNT &= ~3;
    GX_SetBGScrOffset(0x08000000); //REG_DISPCNT = (REG_DISPCNT & ~0x38000000) | 0x08000000;
    GX_SetBGCharOffset(0); //REG_DISPCNT &= ~0x07000000;
    G2_SetBG1Control(3, 0x61, 0, 0, 0); // REG_BG1CNT = (REG_BG1CNT & 0x43) | 0xF080;
    G2_SetBG2Control(2, 0x58, 0, 0, 0); // REG_BG2CNT = (REG_BG2CNT & 0x43) | 0xAC00;
    G2_SetBG3Control(2, 0x68, 0, 0, 0); // REG_BG3CNT = (REG_BG3CNT & 0x43) | 0xB400;
    G2_BG0Mosaic(FALSE); // REG_BG0CNT &= ~0x40;
    G2_BG1Mosaic(FALSE); // REG_BG1CNT &= ~0x40;
    G2_BG2Mosaic(FALSE); // REG_BG2CNT &= ~0x40;
    G2_BG3Mosaic(FALSE); // REG_BG3CNT &= ~0x40;
    *(s32 *)0x04000014 = 0; // TODO: REG_BG1HOFS = 0
    *(s32 *)0x04000018 = 0; // TODO: REG_BG2HOFS = 0
    *(s32 *)0x0400001C = 0; // TODO: REG_BG3HOFS = 0
	MIi_CpuClearFast(0, G2_GetBG1ScrPtr(), 0x800);
	Nitro::func_02060d5c(0);
    GXS_SetVisiblePlane(1); // REG_DISPCNT_SUB = (REG_DISPCNT_SUB & ~0x1F00) | 0x100;
    G2S_SetBG0Priority(0); //REG_BG0CNT_SUB &= ~3;
    G2S_SetBG1Priority(1); //REG_BG1CNT_SUB = (REG_BG1CNT_SUB & ~3) | 1;
    G2S_SetBG2Priority(2); //REG_BG2CNT_SUB = (REG_BG2CNT_SUB & ~3) | 2;
    G2S_SetBG3Priority(3); //REG_BG3CNT_SUB = (REG_BG3CNT_SUB & ~3) | 3;
    G2S_SetBG0Control(0, 0x40, 0, 1, 0); // REG_BG0CNT_SUB = (REG_BG0CNT_SUB & 0x43) | 0x2004;
    G2S_SetBG3Control(0, 0, 1, 2, 0); //REG_BG3CNT_SUB = (REG_BG3CNT_SUB & 0x43) | 0x108;
    G2S_BG0Mosaic(FALSE); // REG_BG0CNT_SUB &= ~0x40;
    G2S_BG1Mosaic(FALSE); // REG_BG1CNT_SUB &= ~0x40;
    G2S_BG2Mosaic(FALSE); // REG_BG2CNT_SUB &= ~0x40;
    G2S_BG3Mosaic(FALSE); // REG_BG3CNT_SUB &= ~0x40;
    GXS_SetOBJVRamModeChar(0); //REG_DISPCNT_SUB &= 0xFFCFFFEF;
    *(s32 *)0x04001010 = 0; // TODO: REG_BG0HOFS_SUB = 0
    *(s32 *)0x0400101C = 0; // TODO: REG_BG3HOFS_SUB = 0
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
