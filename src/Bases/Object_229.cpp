#include "Object_229.hpp"

Object_229 *Object_229::create()
{
	return new Object_229();
}

u32 data_0208af3c[2];
u8 data_ov000_020cac9c;
bool Object_229::onCreate()
{
	u32 uVar2 = this->settings;
	this->direction = (uVar2 >> 0x1c) & 1;
	this->scale.x = 0x1000;
	this->scale.y = 0x1000;
	this->scale.z = 0x1000;
	this->f = ((uVar2 << 4) >> 0x1c);
	if (this->f < 1) {
		this->f = 1;
	}
	if (4 < this->f) {
		this->f = 4;
	}
	u32 uVar1 = (uVar2 << 8) >> 0x1c;
	if (uVar1 == 0) {
		uVar1 = 1;
	}
	if (3 < uVar1) {
		uVar1 = 3;
	}
	this->_40d = (char)(1 << (uVar1 - 1 & 0xff));
	if ((data_0208af3c[1] & *(u32 *)(this->_pad2 + 0xc)) == 0 && (data_0208af3c[0] & *(u32 *)(this->_pad2 + 8)) == 0) {
		this->c = 3;
		this->func_ov099_02185f30(2); // this->func_ov099_02185f30(2);
		data_ov000_020cac9c |= this->_40d;

	} else {
		this->c = 0;
		this->func_ov099_02185f30(0);
		data_ov000_020cac9c &= ~this->_40d;
	}
	this->_3b4 = 1;
	return true;
}

bool Object_229::onDestroy()
{
	return true;
}

void Object_229::pendingDestroy()
{
}

bool Object_229::onRender()
{
	return true;
}

bool Object_229::onUpdate_0()
{
	this->func_ov099_02185ebc();
	this->func_ov000_0209adb0(0);
	return true;
}

void Object_229::func_ov099_021860f0()
{
}

void Object_229::func_ov099_021860a4()
{
}

void Object_229::func_ov099_02186080()
{
	data_ov000_020cac9c |= this->_40d;
	this->e = 1;
}

void Object_229::func_ov099_0218602c()
{
}

void Object_229::func_ov099_02186028()
{
}

void Object_229::func_ov099_02185fdc()
{
}

void Object_229::func_ov099_02185fb4()
{
	data_ov000_020cac9c &= ~this->_40d;
	this->e = 1;
}

void Object_229::func_ov099_02185f5c()
{
}

void (Object_229::*data_ov099_02186614[4])() = {};
void Object_229::func_ov099_02185f30(u32 param_1)
{
	this->b = param_1;
	this->a = data_ov099_02186614[param_1];
	this->c = 1;
}

void Object_229::func_ov099_02185ebc()
{
	if (this->c != 0) {
		(this->*(data_ov099_02186614[this->b]))();
		this->c = 0;
	}
	(this->*a)();
}

bool Object_229::func_ov099_02185eb4()
{
	return true;
}
