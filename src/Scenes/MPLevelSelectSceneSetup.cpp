#include "MPLevelSelectScene.hpp"

extern u8 data_0208b168[];
extern u8 data_02085e30[];
extern u8 data_02086a30[];
extern u8 data_020887f0;
extern u8 data_0208ae54[];
extern u8 data_ov052_0215c3e0[];
extern u8 data_ov052_0215c3f8[];
extern u8 data_ov052_0215c418[];
extern u16 data_ov052_0215c880[];
extern u32 data_02085a8c;
extern u32 data_02085c28;

namespace StageScene {
	void func_ov000_020a2eec();
}

class Overlay52Scene : public Scene {
	public:
	s32 _64;

	Overlay52Scene();
	virtual ~Overlay52Scene();
};

extern "C" {

void func_0200dee0(u32, u32);
void func_02009d30(void *, u32);
void func_02011d60(u32);
bool func_0200ee40(s32);
u32 func_0200e7ac(u32);
void func_0200e7b8(u32);
void func_0200e7c4(u32);
void func_0201dfe8();
u32 func_020090f8(u32);
void *func_020232e8();
void func_ov053_0215cc70();
void func_02008970();
u32 func_02009c64(u32, u32);
void func_02008784(u32, u32);
void func_0200ee9c(void *, u32, u32, u32);
void func_02018b40();

s32 func_ov052_02152840(Overlay52Scene *scene)
{
	if (scene->_64 < 0x70)
		scene->_64++;
	if (func_0200ee40(-1) && scene->_64 >= 0x70)
		func_0200e7c4(0);
	if (func_0200e7ac(0))
		func_020131fc(3, scene->settings);
	return 1;
}

s32 func_ov052_021528a0()
{
	if (data_0208ae54[data_020887f0] == 0) {
		Layout::drawCellMain(0, data_ov052_0215c3f8, 0, 0, 0, nullptr, 0, nullptr, 0, 0, 0);
	} else {
		Layout::drawCellMain(1, data_ov052_0215c418, 0, 0, 0, nullptr, 0, nullptr, 0, 0, 0);
	}
	Layout::drawCellMain(2, data_ov052_0215c3e0, 0, 0, 0, nullptr, 0, nullptr, 0, 0, 0);
	return 1;
}

void func_ov052_02152974()
{
}

s32 func_ov052_02152978()
{
	func_02009d30(data_02085e30, 0x80);
	GlobalFader.func_02007bfc();
	func_0200e7b8(0);
	func_0201dfe8();
	return 1;
}

s32 func_ov052_021529b4(Overlay52Scene *scene)
{
	Nitro::func_02060d78(1, 5, 1);
	*(vu16 *)0x04000304 |= 0x8000;
	REG_DISPCNT = (REG_DISPCNT & ~0x1f00) | 0x1000;
	data_02085a88 = 0x10;

	vu16 *bg0 = (vu16 *)0x04000008;
	vu16 *bg1 = (vu16 *)0x0400000a;
	vu16 *bg2 = (vu16 *)0x0400000c;
	vu16 *bg3 = (vu16 *)0x0400000e;
	*bg0 &= ~3;
	*bg1 = (*bg1 & ~3) | 3;
	*bg2 = (*bg2 & ~3) | 1;
	*bg3 = (*bg3 & ~3) | 2;

	Nitro_::func_02063af0(data_ov052_0215c880, 0, 2);
	Nitro::func_02063a88((u32)data_ov052_0215c880, 0, 2);
	data_02085e0c = 1;
	Layout::bncl[0] = (BNCL *)FS::Cache::loadFile(0xc00a078e, false);
	FS::loadFileLZ77(0xc009078d, (void *)0x06400000);
	func_02009a30(0xc015075e, 0, 1);
	Nitro::func_0206134c(0x100);
	Nitro::func_02060d5c(0);

	REG_DISPCNT_SUB &= 0xffcfffef;
	REG_DISPCNT_SUB = (REG_DISPCNT_SUB & ~0x1f00) | 0x1000;
	data_02085a8c = 0x10;
	GlobalFader.func_02007bfc();
	scene->_64 = 0;
	data_02085c28 = 0x10;
	func_0200ee9c((void *)func_02018b40, 0, 10, 2);
	return 1;
}

}

Overlay52Scene::~Overlay52Scene()
{
}

Overlay52Scene::Overlay52Scene()
{
}

extern "C" {

void *func_ov052_02152bc8()
{
	return new Overlay52Scene();
}

void func_ov052_02152bf0()
{
	func_02009d30(data_02086a30, 0x80);
	func_020090f8(0);
	func_020090f8(7);
	void *resource = func_020232e8();
	if (resource != nullptr)
		FS::unloadFile(resource);
	func_020090f8(9);
	func_ov053_0215cc70();
	Nitro::FS_Overlays_unload(0x16);
	Nitro::FS_Overlays_unload(0x20);
	Nitro::FS_Overlays_unload(0x2a);
	Nitro::FS_Overlays_unload(0x14);
	Nitro::FS_Overlays_unload(0x35);
	func_02008970();
}

void func_ov052_02152c7c()
{
	StageScene::func_ov000_020a2eec();
	func_0200dee0(*(u32 *)(data_0208b168 + 0x34), 0);
	func_02009d30(data_02085e30, 0x80);
	func_02011d60(0x100);
}

}
