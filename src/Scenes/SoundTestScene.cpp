#include "SoundTestScene.hpp"

void func_02011d40();
void func_02011b64();
u32 data_02085a88;
namespace Nitro
{
void func_02061274();
void func_02061260();
void func_0206123c();
void func_02061218();
void func_02061204();
void func_020611f0();
void func_020611dc();
void func_020611c8();
void func_020611b4();
void func_0206118c();
void func_02061164();
void func_02061494(u32);
void func_02061958(u32);
void func_02061474(u32);
void func_02060d78(u32, u32, u32);
void func_02066edc(u32, u32, u32);
u32 func_02062264();
} // namespace Nitro

void *SoundTestScene::create()
{
	return new SoundTestScene();
}

bool SoundTestScene::onCreate()
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
	Nitro::func_02061588(3);
	Nitro::func_02061494(0x10);
	Nitro::func_02061ac4(4);
	Nitro::func_02061958(0x60);
	Nitro::func_02061474(8);
	Nitro::func_02060d78(1, 0, 1);
	data_02085a88 = 0x12;
	REG_DISPCNT = REG_DISPCNT & ~0x7000000 | 0x8000000;
	REG_DISPCNT = REG_DISPCNT & ~0x38000000 | 0x8000000;
	REG_BG1CNT = 0x2810;
	REG_BG1HOFS = 0;
	u32 uVar1 = Nitro::func_02062264();
	Nitro::func_02066edc(0, uVar1, 0x800);
	this->_64 = 0;
	this->_68 = 0;
	this->_6c = 0;
	func_02011b64();
	return true;
}

bool SoundTestScene::onDestroy()
{
	func_02011d40();
	return true;
}
void SoundTestScene::pendingDestroy()
{
}

bool SoundTestScene::onRender()
{
	return true;
}

bool SoundTestScene::onUpdate()
{
	return true;
}
