#include "Scene.hpp"

bool func_02046c5c();
bool Wifi_isMultiBootCart();
void func_0200f3d8();
void func_02009b64();
void func_ov052_02152bf0();
void func_0200e874(u32, u32, bool);
void func_0200514c(u32);
void sceneBaseInit();
void func_02018ac0();
void func_0200e944(u32, u32, u32);
u32 data_02088f18();
u32 func_02013050(u32);
u32 data_02085a84;
u32 data_0208ae58;
u32 data_02089504;
u8 data_0203bd28;
u8 data_02085974;
u16 data_0203bd2c;
u16 data_0203bd34;
u8 data_02088f30;
u32 data_02088f38;

Fader *PTR_02085b14;

Scene::Scene()
{
	this->skipFlags |= 1;
	this->skipFlags |= 4;
	Stage::actorFreezeFlag = 0;
	data_ov000_020ca84c = 0;
	data_02088f34 = 0;
}

Scene::~Scene()
{
	if (data_02088f34 != 0) {
		bool a = false;
		bool b = false;
		if ((data_020887fc != 0) && (data_020887fc != 0x9)) {
			b = true;
		}
		if (b && (data_020887fc != 0x8)) {
			a = true;
		}
		if (a) {
			bool c = func_02046c5c();
			if (c != 0 && !Wifi_isMultiBootCart()) {
				data_02085ad4[0] = *((u32 *)&data_02088bdc + 0xd2); // TODO: Do not offset using pointers
			}
			func_0200f3d8();
		}
		func_02009b64();
		if ((BOOL(data_02085a84 != 0) && (data_0208ae58 != 0)) == TRUE) {
			func_ov052_02152bf0();
			data_0208ae58 = 0;
		}

		GlobalFader.fadingTarget[0] |= 2;
		GlobalFader.fadingTarget[1] |= 2;
		GlobalFader.brightnessFactor[0] = 0x1000;
		GlobalFader.brightnessFactor[1] = 0x1000;
	}
}

bool Scene::preCreate()
{
	if (!Base::preCreate()) {
		return false;
	}
	if (this->object_id != 0) {
		GlobalFader.setupSceneFading(0, 0, 1);
	}
	this->_5c = 0x1fc;
	this->_60 = 0xf;
	return true;
}

void Scene::postCreate(u32 param_1)
{
	func_0200e944(this->_5c, this->_60, 1);
	if (param_1 == 2) {
		PTR_02085b14 = &GlobalFader;
	}
	Object::postCreate(param_1);
	return;
}

bool Scene::preDestroy()
{
	bool result = Base::preDestroy();
	if (!result) {
		return false;
	}
	GlobalFader.fadingType = 0;
	return true;
}

void Scene::postDestroy(u32 a)
{
	if (a == 2) {
		data_0203bd28 = 0;
	}
	Base::postDestroy(a);
}

bool Scene::preUpdate()
{
}

void Scene::postUpdate(u32 a)
{
	Base::postUpdate(a);
}

bool Scene::preRender()
{
	if (Base::preRender()) {
		func_0200e874(this->_5c, this->_60, true);
		return true;
	}
	return false;
}

void Scene::postRender(u32 a)
{
	Base::postRender(a);
}

void Scene::prepareFirstScreen()
{
	if (i32(&GlobalFader) == 0) {
		// GlobalFader = Fader();
		//*(i32*)(&GlobalFader) = 1;
	}
	if (Wifi_isMultiBootCart()) {
		data_0203bd30 = 1;
	} else {
		u32 boot_scene = Game::getBootScene();
		if (boot_scene == 0) {
			data_0203bd30 = 0;
		} else {
			sceneBaseInit();
			func_02018ac0();
			GlobalFader.brightnessFactor[0] = 0x1000;
			GlobalFader.brightnessFactor[1] = 0x1000;
			// iVar2 = func_02013050(&data_02088f18);
			//  if (iVar2 == 0) {
			//	data_0203bd30 = 4;
			//	data_02085ad4 = uRam02088f24;
			//	func_02006444(uRam02088f20);
			//  } else {
			//	if (iVar2 - 2U < 2) {
			//		data_02088f38 = 7;
			//	} else {
			//		data_02088f38 = 6;
			//	}
			//	data_0203bd30 = 0xb;
			//	data_02088f30 = 0;
			//  }
		}
	}
}

Scene *Scene::tryChangeScene()
{
	if (data_0203bd28 != 0 || data_0203bd30 == 0x181) {
		return 0;
	}
	data_0203bd2c = data_0203bd34;
	data_0203bd34 = data_0203bd30;
	data_02085974 &= ~0x40;
	if (data_0203bd30 == 4) {
		data_02085a84 = 0;
		data_02088f30 = 1;
	}
	if (data_0203bd30 == 0x146) {
		func_0200514c(0x10101);
	}
	Scene *result = (Scene *)Object::spawnScene(data_0203bd30, data_02088f38, 1);
	if (result != NULL) {
		data_0203bd30 = 0x181;
		data_0203bd28 = 1;
		return result;
	}
	return 0;
}
