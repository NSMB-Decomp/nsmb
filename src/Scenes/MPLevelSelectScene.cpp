#include "MPLevelSelectScene.hpp"

void *MPLevelSelectScene::create()
{
	return new MPLevelSelectScene();
}

void MPLevelSelectScene::func_ov052_02155cf8() {
	void * uVar1 = Nitro::func_02061f2c();
	func_02008784(0xc90d,uVar1);
	uVar1 = Nitro::func_02061f84();
	func_02008784(0xc90d,uVar1);
	func_02008784(0xc920,(void*)0x6600000);
}

void MPLevelSelectScene::func_ov052_02155c9c() {
	// TODO, these are paletes, how best to define them?
	func_02008784(0xc90e,(void*)0x05000000);
	func_02008784(0xc910,(void*)0x05000200);
	Nitro::func_02066f28((void*)0x05000000,(void*)0x05000400,0xe0);
	Nitro::func_02066f28((void*)0x05000200,(void*)0x05000600,0x1a0);
}

MPLevelSelectScene::MPLevelSelectScene()
{
}

MPLevelSelectScene::~MPLevelSelectScene()
{

}