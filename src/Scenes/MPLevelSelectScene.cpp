#include "MPLevelSelectScene.hpp"

void *MPLevelSelectScene::create()
{
	return new MPLevelSelectScene();
}

void MPLevelSelectScene::func_ov052_02155cf8()
{
	void *uVar1 = Nitro::func_02061f2c();
	func_02008784(0xc90d, uVar1);
	uVar1 = Nitro::func_02061f84();
	func_02008784(0xc90d, uVar1);
	func_02008784(0xc920, (void *)0x6600000);
}

void MPLevelSelectScene::func_ov052_02155c9c()
{
	// TODO, these are paletes, how best to define them?
	func_02008784(0xc90e, (void *)0x05000000);
	func_02008784(0xc910, (void *)0x05000200);
	Nitro::func_02066f28((void *)0x05000000, (void *)0x05000400, 0xe0);
	Nitro::func_02066f28((void *)0x05000200, (void *)0x05000600, 0x1a0);
}

void MPLevelSelectScene::func_ov052_02155ba8()
{
	//uVar1 = Nitro::func_020621b8();
	//func_02008784(0xc916, uVar1);
	//uVar1 = Nitro::func_020620ac();
	//func_02008784(0xc90c, uVar1);
	//uVar1 = Nitro::func_02062298();
	//func_02008784(0xc913, uVar1);
	//uVar1 = func_02009c64(0xc912, 1);
	//*(undefined4 *)(this->_pad1 + 0xaf) = uVar1;
	//uVar1 = func_02009acc(0xc912);
	//*(undefined4 *)(this->_pad1 + 0xb3) = uVar1;
	//uVar1 = Nitro::func_02062244();
	//Nitro::func_0206707c(*(undefined4 *)(this->_pad1 + 0xaf), uVar1, *(undefined4 *)(this->_pad1 + 0xb3));
	//iVar2 = Nitro::func_02062244();
	//func_02008784(0xc915, iVar2 + 0x800);
	//iVar2 = Nitro::func_02062244();
	//Nitro::func_02066fe8(iVar2 + 0x1000, 0, 0x1000);
	//uVar1 = Nitro::func_02062138();
	//func_02008784(0xc911, uVar1);
	//iVar2 = Nitro::func_02062138();
	//func_02008784(0xc914, iVar2 + 0x800);
	//iVar2 = Nitro::func_02062138();
	//Nitro::func_02066fe8(iVar2 + 0x1000, 0, 0x1000);
	//uVar1 = Nitro::func_0206202c();
	//func_02008784(0xc90f, uVar1);
}

struct data_0208588c_ {
	u32 _0[2];
	u32 _1[2];
};
data_0208588c_ data_0208588c;
void MPLevelSelectScene::func_ov052_02155b00() {
  if ((this->_64 == 0) || (this->_64 == 0x10)) {
    u32 uVar1 = func_02009c64(0xc91c,0);
    u32 uVar2 = func_02009c64(0xc91d,0);
    func_02004564(0,uVar2,uVar1);
  }
  else {
    u32 uVar1 = func_02009c64(0xc91e,0);
    u32 uVar2 = func_02009c64(0xc91f,0);
    func_02004564(0,uVar2,uVar1);
  }
  this->_70 = data_0208588c._0[1] + 8;
  return;
}

MPLevelSelectScene::MPLevelSelectScene()
{
}

MPLevelSelectScene::~MPLevelSelectScene()
{
}