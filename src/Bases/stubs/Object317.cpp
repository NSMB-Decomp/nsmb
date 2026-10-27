#include "Object317.hpp"

extern s16 *data_ov000_020caa38;

u32 data_ov008_020e59b4[8] = {0x682, 0x683, 0x684, 0x685, 0x686, 0x687, 0x688, 0x689};

void *Object317::create()
{
	return new Object317();
}

s32 Object317::onCreate()
{
	if (this->prepareResourcesSafe(0, Memory_gameHeap)) {
		this->position.x = 0;
		this->position.y = 0;
		this->position.z = 0;
		this->rotation.x = 0;
		this->rotation.y = 0;
		this->rotation.z = 0;
		this->scale.x = 0x1000;
		this->scale.y = 0x1000;
		this->scale.z = 0x1000;
		this->_5b4 = 0x30000;
		this->_5b8 = 0;
		this->selected_world = 0;
		this->func_ov008_020cd520(0);
		return TRUE;
	} else {
		return FALSE;
	}
}

bool Object317::onHeapCreated()
{
	for (s32 i = 0; i < 8; i++) {
		void *bmd = FS::Cache::getFile(data_ov008_020e59b4[i]);
		BOOL a = this->models[i].create(bmd, 0, 0);
		if (a == FALSE) {
			return false;
		}
	}
	return true;
}

BOOL Object317::onDestroy()
{
	return TRUE;
}
void Object317::pendingDestroy()
{
}

BOOL Object317::onRender()
{
	Vec3_32 translation;
	Vec3_32 scale;
	s16 angle = data_ov000_020caa38[0x80];
	translation.y = 0;
	for (s32 i = 0; i < 8; i++) {
		if (i == (u32)(u16)this->_5b8 >> 0xd && this->_5a8 == 0) {// TODO: Is this a macro or inline function from nitro?
			scale.x = 0x1800;
			scale.y = 0x1800;
			scale.z = 0x1800;
		} else {
			scale.x = 0x1000;
			scale.y = 0x1000;
			scale.z = 0x1000;
		}

		u16 a = i * 0x2000 - this->_5b8; // TODO: Is this a macro or inline function from nitro?
		translation.x = _FixedMul(this->_5b4, _FixedSin(a));
		translation.z = _FixedMul(this->_5b4, _FixedCos(a));
		MTX::setTranslation(Game_modelMatrix, translation);
		MTX::rotateX(Game_modelMatrix, angle);
		this->models[i].matrix = Game_modelMatrix;
		this->models[i].render(&scale);
	}
	return TRUE;
}

BOOL Object317::onUpdate()
{
	this->func_ov008_020cd4ac();
	u8 id = Input::localConsoleID;
	u16 pressed = data_02087650[id][0];
	if ((pressed & PAD_BUTTON_R) != 0 || (pressed & PAD_BUTTON_L) != 0) {

		u16 pressed_2 = data_02087650[id][0];
		if ((pressed & PAD_BUTTON_L) != 0) {
			pressed_2 = Input::consoleKeys[id][0];
		}

		if ((pressed_2 & PAD_KEY_RIGHT) != 0) {
			this->_5b4 += 0x800;
		} else if ((pressed_2 & PAD_KEY_LEFT) != 0) {
			this->_5b4 -= 0x800;
		}
	}
	return TRUE;
}

void Object317::func_ov008_020cd664()
{
}

void Object317::func_ov008_020cd5e8()
{
	u32 input = Input::consoleKeys[Input::localConsoleID][0];
	if ((input & PAD_BUTTON_A) != 0) {
		func_02012398(0x2c, 0);
		func_020131fc(9, this->selected_world);
	} else if ((input & PAD_KEY_RIGHT) != 0) {
		this->direction = 0;
		this->func_ov008_020cd520(1);
	} else if ((input & PAD_KEY_LEFT) != 0) {
		this->direction = 1;
		this->func_ov008_020cd520(1);
	}
}

void Object317::func_ov008_020cd5dc() // Start animation?
{
	this->_5b0 = 0x20;
}

void Object317::func_ov008_020cd54c() // Finish Animation?
{
	if (this->direction != 0) {
		this->_5b8 -= 0x100;
	} else {
		this->_5b8 += 0x100;
	}

	this->_5b0 -= 1;
	if (this->_5b0 == 0) {
		func_02012398(0x16, 0);
		this->func_ov008_020cd520(0);
		if (this->direction != 0) {
			this->selected_world -= 1;
		} else {
			this->selected_world += 1;
		}
		this->selected_world &= 7;
	}
}

void (Object317::*data_ov008_020ee354[2])() = {
    &Object317::func_ov008_020cd664,
    &Object317::func_ov008_020cd5dc,
};
void (Object317::*data_ov008_020ee364[2])() = {
    &Object317::func_ov008_020cd5e8,
    &Object317::func_ov008_020cd54c,
};
void Object317::func_ov008_020cd520(u32 param_1)
{
	this->_5a8 = param_1;
	this->_5a0 = data_ov008_020ee364[param_1];
	this->_5ac = 1;
}

void Object317::func_ov008_020cd4ac()
{
	if (this->_5ac != 0) {
		(this->*(data_ov008_020ee354[this->_5a8]))();
		this->_5ac = 0;
	}
	(this->*_5a0)();
}

bool Object317::loadResources()
{
	for (s32 i = 0; i < 8; i++) {
		FS::Cache::loadFile(data_ov008_020e59b4[i], 0);
	}
	return true;
}

// 0x020e59a8
ActorProfile Object317_Profile = {Object317::create, 317, 292, Object317::loadResources};
