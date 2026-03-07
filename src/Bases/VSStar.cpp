#include "VSStar.hpp"

void *VsStar::create()
{
	return new VsStar();
}

bool VsStar::func_ov020_02132660(u32)
{
}

void VsStar::func_ov020_02132618()
{
}

void VsStar::func_ov020_02132510()
{
}

void VsStar::damagePlayer()
{
}

void VsStar::_24()
{
}

void VsStar::_26()
{
	return VsStar::_24();
}

void VsStar::_27()
{
	return VsStar::_24();
}

void VsStar::_30()
{
	return VsStar::_24();
}

void VsStar::_25()
{
	return VsStar::_24();
}

void VsStar::_31()
{
	return VsStar::_24();
}

void VsStar::_21()
{
}

void VsStar::func_ov020_0213238c()
{
}

bool VsStar::func_ov020_021322a4()
{
}

void VsStar::func_ov020_021320dc(u32)
{
}

bool VsStar::func_ov020_0213203c()
{
}

bool VsStar::func_ov020_02131f7c()
{
}

bool VsStar::func_ov020_02131c54()
{
}

void VsStar::func_ov020_02131bbc()
{
}

bool VsStar::onCreate()
{
	u32 settings = this->settings;
	this->setting_0 = READ_NIBBLE(settings, 0);
	this->setting_1 = READ_NIBBLE(settings, 1);
	return true;
}

bool VsStar::onUpdate_0()
{
}

bool VsStar::onRender()
{
}

bool VsStar::onDestroy()
{
	if (this->setting_0 == 1) {
		// func_ov010_020f9d64(&this->field_0x47c);
	}
	return true;
}

VsStar::~VsStar()
{
}