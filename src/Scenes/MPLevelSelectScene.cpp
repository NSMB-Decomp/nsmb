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

u32 MPLevelSelectScene::func_ov052_02155540() {

}

bool MPLevelSelectScene::func_ov052_0215552() {
	return true;
}

s32 MPLevelSelectScene::onCreate() {

}

s32 MPLevelSelectScene::onDestroy() {
	func_020180a4(&this->a);
  	func_02005700();
	return true;
}

void MPLevelSelectScene::pendingDestroy() {
}

//void (Object229::*data_ov099_02186614[4])() = {
//    Object229::func_ov099_021860f0,
//    Object229::func_ov099_02186080,
//    Object229::func_ov099_02186028,
//    Object229::func_ov099_02185fb4,
//};

s32 MPLevelSelectScene::onUpdate() {
	static void (MPLevelSelectScene::*ptmfs[20])() = {
		MPLevelSelectScene::func_ov052_02155210,
		MPLevelSelectScene::func_ov052_021551e4,
		MPLevelSelectScene::func_ov052_0215515c,
		MPLevelSelectScene::func_ov052_02154c9c,
		MPLevelSelectScene::func_ov052_02154bb4,
		MPLevelSelectScene::func_ov052_02154a60,
		MPLevelSelectScene::func_ov052_0215476c,
		MPLevelSelectScene::func_ov052_021546d0,
		MPLevelSelectScene::func_ov052_02154698,
		MPLevelSelectScene::func_ov052_0215459c,
		MPLevelSelectScene::func_ov052_02154698,
		MPLevelSelectScene::func_ov052_02155178,
		MPLevelSelectScene::func_ov052_02154b64,
		MPLevelSelectScene::func_ov052_02154af4,
		MPLevelSelectScene::func_ov052_02154a24,
		MPLevelSelectScene::func_ov052_0215454c,
		MPLevelSelectScene::func_ov052_021544a0,
		MPLevelSelectScene::func_ov052_02154c68,
		MPLevelSelectScene::func_ov052_02154c34,
		MPLevelSelectScene::func_ov052_021549f8
	};
	func_02021808();
	if (this->_144 > 0) {
		this->_144 -= 1;
	}
	(this->*ptmfs[this->_64])();
	return 1;
}

s32 MPLevelSelectScene::onRender() {
	static void (MPLevelSelectScene::*ptmfs[20])() = {
		MPLevelSelectScene::func_ov052_02154244,
		MPLevelSelectScene::func_ov052_02154238,
		MPLevelSelectScene::func_ov052_02154220,
		MPLevelSelectScene::func_ov052_02153d5c,
		MPLevelSelectScene::func_ov052_02153d14,
		MPLevelSelectScene::func_ov052_02153d08,
		MPLevelSelectScene::func_ov052_02153b44,
		MPLevelSelectScene::func_ov052_02153b38,
		MPLevelSelectScene::func_ov052_02153b04,
		MPLevelSelectScene::func_ov052_02153ad0,
		MPLevelSelectScene::func_ov052_02153b04,
		MPLevelSelectScene::func_ov052_0215422c,
		MPLevelSelectScene::func_ov052_02153d2c,
		MPLevelSelectScene::func_ov052_02153d20,
		MPLevelSelectScene::func_ov052_02153cfc,
		MPLevelSelectScene::func_ov052_02153ac4,
		MPLevelSelectScene::func_ov052_02153ab8,
		MPLevelSelectScene::func_ov052_02153d50,
		MPLevelSelectScene::func_ov052_02153d44,
		MPLevelSelectScene::func_ov052_02153d38
	};
	(this->*ptmfs[this->_64])();
	return true;
}