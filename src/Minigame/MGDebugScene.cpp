#include "MGDebugScene.hpp"

extern "C" u32 strlen(const char *);

bool func_0200a4c8(u32, u32);
bool func_0200a488(u32, u32);
bool func_0204354c(s16 *, s16, s16);
bool func_02021514(u32);
void func_ov130_021232bc(u32);
void func_02023ba8(u32, u32);
void func_02023b58(u32, u32);
extern u8 data_0208b4c8[];
extern char data_02088bb4[];
extern u8 data_02039218[];
extern u16 data_02039210[];
extern volatile u8 data_0208b594;
extern volatile u8 data_0208b590;

// One 8x8 16-colour (4bpp) character
struct CharTile {
	u8 data[0x20];
};

// 0x02137c0c
const s16 data_ov130_02137c0c[6] = {20, 12, 8, 6, 4, 0};

void MGDebugScene::func_ov130_021271d0()
{
	if (func_0200a4c8(0, 0x1)) {
		func_ov130_021232bc(0xf);
		this->virt_20(this->_6c);
		return;
	}
	if (!func_02021514(0)) {
		return;
	}

	s32 count = this->_68;
	u8 touchX = data_0208b4c8[2];
	u8 touchY = data_0208b4c8[3];
	if (count >= 10) {
		count = 10;
	}
	for (s32 i = 0; i < count; i++) {
		s32 len = strlen(this->virt_19(i));
		s32 right = len * 8 + 32;
		s32 top = (4 + i * 2) * 8 - 4;
		s32 bottom = top + 16;
		if ((s32)touchX >= 32 && touchX <= right && touchY >= top && touchY < bottom && this->_64 != 0) {
			func_ov130_021232bc(0xf);
			if (this->_68 < 10) {
				this->virt_20(i);
			} else if (this->_6c <= this->_68 - 10) {
				this->virt_20(i + this->_6c);
			} else {
				this->virt_20(i + this->_68 - 10);
			}
		}
	}
}

bool MGDebugScene::func_ov130_02127110()
{
	if (func_0200a4c8(0, 0x40)) {
		this->_70 = 0;
		this->_76 = 0;
		this->_74 = data_ov130_02137c0c[this->_76];
		return true;
	}
	if (func_0200a488(0, 0x40)) {
		if (func_0204354c(&this->_70, this->_74, 1)) {
			this->_70 = 0;
			this->_74 = data_ov130_02137c0c[this->_76];
			func_0204354c(&this->_76, 4, 1);
			return true;
		}
	} else {
		this->_70 = 0;
		this->_76 = 0;
		this->_74 = 0;
	}
	return false;
}

bool MGDebugScene::func_ov130_02127050()
{
	if (func_0200a4c8(0, 0x80)) {
		this->_72 = 0;
		this->_7a = 0;
		this->_78 = data_ov130_02137c0c[this->_7a];
		return true;
	}
	if (func_0200a488(0, 0x80)) {
		if (func_0204354c(&this->_72, this->_78, 1)) {
			this->_78 = data_ov130_02137c0c[this->_7a];
			func_0204354c(&this->_7a, 4, 1);
			this->_72 = 0;
			return true;
		}
	} else {
		this->_72 = 0;
		this->_7a = 0;
		this->_78 = 0;
	}
	return false;
}

void MGDebugScene::func_ov130_02126fc8()
{
	if (this->func_ov130_02127110()) {
		func_ov130_021232bc(6);
		if (this->_6c > 0) {
			this->_6c--;
		} else {
			this->_6c = this->_68 - 1;
		}
		this->func_ov130_02126c7c();
	} else if (this->func_ov130_02127050()) {
		func_ov130_021232bc(6);
		if (this->_6c < this->_68 - 1) {
			this->_6c++;
		} else {
			this->_6c = 0;
		}
		this->func_ov130_02126c7c();
	}
}

void MGDebugScene::func_ov130_02126c7c()
{
	u16 *mainScr = (u16 *)G2_GetBG1ScrPtr();
	u16 *subScr = (u16 *)Nitro::func_02062244();

	s32 top = this->_6c;
	if (this->_68 <= 10) {
		top = 0;
	} else if (top > this->_68 - 10) {
		top = this->_68 - 10;
	}

	for (s32 row = 0; row < 24; row++) {
		if (row < 4) {
			if (row == 0) {
				s8 *str = (s8 *)data_02088bb4;
				for (s32 col = 0; col < 32; col++) {
					if (*str != 0) {
						MI_CpuFill16(mainScr, (u16)*str, 2);
						MI_CpuFill16(subScr, (u16)*str, 2);
						str++;
					} else {
						MI_CpuFill16(mainScr, ' ', 2);
						MI_CpuFill16(subScr, ' ', 2);
					}
					mainScr++;
					subScr++;
				}
			} else {
				MI_CpuFill16(mainScr, ' ', 64);
				MI_CpuFill16(subScr, ' ', 64);
				mainScr += 32;
				subScr += 32;
			}
		} else {
			s32 index = top + (row - 4);
			s32 col;
			s8 *str;
			if (index >= 0 && index < this->_68) {
				str = (s8 *)this->virt_19(index);
			} else {
				MI_CpuFill16(mainScr, ' ', 64);
				MI_CpuFill16(subScr, ' ', 64);
				mainScr += 32;
				subScr += 32;
				continue;
			}
			for (col = 0; col < 32; col++) {
				if (col > 4 && *str != 0) {
					MI_CpuFill16(mainScr, (u16)*str, 2);
					MI_CpuFill16(subScr, (u16)*str, 2);
					str++;
				} else {
					MI_CpuFill16(mainScr, ' ', 2);
					MI_CpuFill16(subScr, ' ', 2);
				}
				mainScr++;
				subScr++;
			}
			MI_CpuFill16(mainScr, ' ', 64);
			MI_CpuFill16(subScr, ' ', 64);
			mainScr += 32;
			subScr += 32;
		}
	}

	s32 count = this->_68;
	if (count <= 10) {
		MI_CpuFill16((u16 *)G2_GetBG1ScrPtr() + (this->_6c * 2 + 4) * 32 + 2, 0x103e, 2);
		MI_CpuFill16((u16 *)Nitro::func_02062244() + (this->_6c * 2 + 4) * 32 + 2, 0x103e, 2);
	} else if (this->_6c <= count - 10) {
		MI_CpuFill16((u16 *)G2_GetBG1ScrPtr() + 4 * 32 + 2, 0x103e, 2);
		MI_CpuFill16((u16 *)Nitro::func_02062244() + 4 * 32 + 2, 0x103e, 2);
	} else {
		MI_CpuFill16((u16 *)G2_GetBG1ScrPtr() + ((this->_6c - count + 10) * 2 + 4) * 32 + 2, 0x103e, 2);
		MI_CpuFill16((u16 *)Nitro::func_02062244() + ((this->_6c - this->_68 + 10) * 2 + 4) * 32 + 2, 0x103e, 2);
	}
}

bool MGDebugScene::preCreate()
{
	if (!MGScene::preCreate()) {
		return false;
	}
	MGScene::func_02024ee0();
	this->_64 = 1;
	this->virt_18();

	REG_DISPCNT_SUB |= 0x10000;
	GX_SetGraphicsMode(1, 0, 0);
	Nitro::func_02060d5c(0);
	GXS_SetOBJVRamModeChar(0);
	GX_SetBGCharOffset(0);
	GX_SetBGScrOffset(0);
	REG_POWER_CNT |= 0x8000;
	Nitro::func_02061ac4(3);
	GX_SetBankForOBJ(0x10);
	GX_SetBankForSubBG(4);
	Nitro::func_0206134c(8);
	REG_POWER_CNT |= 0x8000;
	G2_SetBG1Control(0, 0, 0, 4, 0);
	G2S_SetBG1Control(0, 0, 0, 4, 0);
	CharTile *mainFont = &((CharTile *)Nitro::func_02061fa4())[0x20];
	Nitro::func_02067258(data_02039218, mainFont);
	CharTile *subFont = &((CharTile *)Nitro::func_02061f84())[0x20];
	Nitro::func_02067258(data_02039218, subFont);
	Nitro_::func_02063af0(data_02039210, 0, 6);
	Nitro::func_02063a88((u32)data_02039210, 0, 6);

	this->_6c = 0;
	this->func_ov130_02126c7c();
	data_0208b594 = 2;
	data_0208b590 = 2;
	func_02023ba8(0, 0);
	func_02023b58(0, 0);
	return true;
}

bool MGDebugScene::preUpdate()
{
	if (!MGScene::preUpdate()) {
		return false;
	}
	this->func_ov130_02126fc8();
	this->func_ov130_021271d0();
	return true;
}
