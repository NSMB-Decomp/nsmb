#include "Scene.hpp"
#include "../system/app.hpp"

extern "C" {
	void func_02008558();
	bool func_02046c5c();
	void func_0200f3d8();
	void func_ov052_02152bf0();
	void func_0200e874(u32, u32, bool);
	void func_02018ac0();
	void func_0200e944(u32, u32, u32);
	u32 func_02013050(OptionSave *);
	void func_02006444(u32);
	void func_02007c44(Fader *);
	extern u8 data_02088f2c;
	extern u8 data_02087630;
	extern u16 data_0208883c;
}
// C++ linkage: the ROM symbols are _Z13func_02011e3cm and _Z13func_020131fcmm,
// not the C-linkage names AAA.hpp gives them.
void func_02011e3c(u32);
void func_020131fc(u32, u32);
u32 data_02085a84;
u32 data_0208ae58;
u32 data_02089504;
u8 data_0203bd28 = 1;
u16 data_0203bd2c = 0x181;
u16 data_0203bd30 = 0x181;
u16 data_0203bd34 = 0x181;
u32 data_02088f38;
Fader *data_02085b14;

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
		if ((Net::connectionState != 0) && (Net::connectionState != 0x9)) {
			b = true;
		}
		if (b && (Net::connectionState != 0x8)) {
			a = true;
		}
		if (a) {
			bool c = func_02046c5c();
			if (c != 0 && !Nitro::Wifi_isMultiBootCart()) {
				data_02085ad4[0] = save.options.controlOptions; // TODO: Do not offset using pointers
			}
			func_0200f3d8();
		}
		FS::Cache::clear();
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
		data_02085b14 = &GlobalFader;
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
	if (!Base::preUpdate()) {
		return 0;
	}
	if (data_0203bd30 != 0x181) {
		if (func_02007c68(&GlobalFader) == 0) {
			func_02007df0(&GlobalFader, 0x20);
		} else {
			if (func_02007c68(&GlobalFader) != 0) {
				this->destroy();
			}
		}
		return false;
	}
	if ((this->skipFlags & 1) != 0) {
		if (!this->hasChildPendingCreation()) {
			this->skipFlags &= ~1;
			this->skipFlags &= ~4;
		}
		return false;
	}
	s32 i = 0;
	do {
		if ((GlobalFader.fadingState[i] & 4) != 0) {
			func_02007e34(&GlobalFader, 0x20, i);
		}
		if ((GlobalFader.fadingState[i] & 0x20) != 0) {
			func_02007cf8(&GlobalFader, 0x20, i);
		}
		i += 1;
	} while (i < 2);
	if (data_02087630 != 0) {
		if ((data_02088f2c != 0) && (data_02088f30 != 0)) {
			if (Nitro::Wifi_isMultiBootCart()) {
				data_0208883c |= 0x8000;
			} else {
				data_02088f2c = 0;
				func_02011e3c(0x1e);
				func_02007c44(&GlobalFader);
				GlobalFader.func_02007bfc();
				func_020131fc(4, 0);
				data_02088f34 = 1;
			}
			return false;
		}
	} else {
		data_02088f2c = 1;
	}
	return true;
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

void Scene::prepareFirstScene()
{
	if (i32(&GlobalFader) != 0) {
		func_02008558();
	}
	if (Nitro::Wifi_isMultiBootCart()) {
		data_0203bd30 = 1;
	} else {
		u32 boot_scene = App::getBootScene();
		if (boot_scene == 0) {
			data_0203bd30 = 0;
		} else {
			App::initBoot();
			func_02018ac0();
			GlobalFader.brightnessFactor[0] = 0x1000;
			GlobalFader.brightnessFactor[1] = 0x1000;
			u32 iVar2 = func_02013050(&save.options);
			if (iVar2 == 0) {
				data_0203bd30 = 4;
				data_02085ad4[0] = save.options.controlOptions;
				func_02006444(save.options.soundMode);
			} else {
				if (iVar2 - 2U <= 1) {
					data_02088f38 = 7;
				} else {
					data_02088f38 = 6;
				}
				data_0203bd30 = 0xb;
				data_02088f30 = 0;
			}
		}
	}
	data_02088f2c = 0;
	data_0203bd28 = 0;
}

Scene *Scene::tryChangeScene()
{
	if (data_0203bd28 != 0 || data_0203bd30 == 0x181) {
		return 0;
	}
	data_0203bd2c = data_0203bd34;
	data_0203bd34 = data_0203bd30;
	App::sleepControl &= ~0x40;
	if (data_0203bd30 == 4) {
		data_02085a84 = 0;
		data_02088f30 = 1;
	}
#if !defined(VER_Y7QJ)
	if (data_0203bd30 == 0x146) {
		App::reset(0x10101);
	}
#endif
	Scene *result = (Scene *)Object::spawnScene(data_0203bd30, data_02088f38, 1);
	if (result != NULL) {
		data_0203bd30 = 0x181;
		data_0203bd28 = 1;
		return result;
	}
	return 0;
}
