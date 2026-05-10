#include "MPLevelSelectScene.hpp"

void *MPLevelSelectScene::create()
{
	return new MPLevelSelectScene();
}

void MPLevelSelectScene::func_ov052_02155cf8() {
	u32 uVar1 = Nitro::func_02061f2c();
	func_02008784(0xc90d,uVar1);
	uVar1 = Nitro::func_02061f84();
	func_02008784(0xc90d,uVar1);
	func_02008784(0xc920,0x6600000);
}

MPLevelSelectScene::MPLevelSelectScene()
{
}

MPLevelSelectScene::~MPLevelSelectScene()
{

}