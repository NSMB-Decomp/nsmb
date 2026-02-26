#include "Object_229.hpp"

Object_229 *Object_229::create()
{
	return new Object_229();
}

void (Object_229::*data_ov099_02186614[4])() = {
    Object_229::func_ov099_021860f0,
    Object_229::func_ov099_02186080,
    Object_229::func_ov099_02186028,
    Object_229::func_ov099_02185fb4,
};
void (Object_229::*data_ov099_02186634[4])() = {
    Object_229::func_ov099_021860a4,
    Object_229::func_ov099_0218602c,
    Object_229::func_ov099_02185fdc,
    Object_229::func_ov099_02185f5c,
};
struct UNKWN_STRUCT {
	u32 a;
	u32 b;
};
u32 data_0208af3c[2];
u8 data_ov000_020cac9c;
bool Object_229::onCreate()
{
	this->direction = (this->settings >> 0x1c) & 1;
	this->scale.x = 0x1000;
	this->scale.y = 0x1000;
	this->scale.z = 0x1000;
	this->setting_1 = ((this->settings << 4) >> 0x1c);
	if (this->setting_1 < 1) {
		this->setting_1 = 1;
	}
	if (4 < this->setting_1) {
		this->setting_1 = 4;
	}
	i32 uVar1 = (u8)((this->settings << 8) >> 0x1c);
	if (uVar1 < 1) {
		uVar1 = 1;
	}
	if (3 < uVar1) {
		uVar1 = 3;
	}
	this->setting_2 = (char)(1 << (uVar1 - 1));
	u32 a = (data_0208af3c[0] & this->_334);
	u32 b = (data_0208af3c[1] & this->_338);
	if (
		(a && b) == 0
	) {
		this->_404 = 3;
		this->func_ov099_02185f30(2);
		data_ov000_020cac9c |= this->setting_2;
	} else {
		this->_404 = 0;
		this->func_ov099_02185f30(0);
		data_ov000_020cac9c &= ~this->setting_2;
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
	this->onUpdate_CallPTMF();
	this->func_ov000_0209adb0(0);
	return true;
}

void Object_229::func_ov099_021860f0()
{
}

void Object_229::func_ov099_021860a4()
{
	if ((data_0208af3c[1] & this->_338) != 0 || (data_0208af3c[0] & this->_334) != 0) {
		this->func_ov099_02185f30(1);
		return;
	}
	return;
}

void Object_229::func_ov099_02186080()
{
	data_ov000_020cac9c |= this->setting_2;
	this->e = 1;
}

void Object_229::func_ov099_0218602c()
{
	this->e = this->e - 1;
	if (this->e != 0) {
		return;
	}
	this->e = 2;
	this->_404 = this->_404 + 1;
	if (3 <= (i32)this->_404) {
		this->func_ov099_02185f30(2);
		return;
	}
	return;
}

void Object_229::func_ov099_02186028()
{
}

void Object_229::func_ov099_02185fdc()
{
	if (BOOL(((data_0208af3c[0] & this->_334) == (data_0208af3c[1] & this->_338)) == 0) == TRUE) {
		this->func_ov099_02185f30(3);
	}
}

void Object_229::func_ov099_02185fb4()
{
	data_ov000_020cac9c &= ~this->setting_2;
	this->e = 1;
}

void Object_229::func_ov099_02185f5c()
{
	this->e = this->e - 1;
	if (this->e != 0) {
		return;
	}
	this->e = 2;
	this->_404 -= 1;
	if (this->_404 == 0) {
		this->func_ov099_02185f30(0);
	}
}

void Object_229::func_ov099_02185f30(u32 param_1)
{
	this->b = param_1;
	this->a = data_ov099_02186634[param_1];
	this->c = 1;
}

void Object_229::onUpdate_CallPTMF()
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
