#include "DebugScene.hpp"

struct SomethingElse {
	char *a;
	u16 b;
	u16 c;
	u32 d;
};

u32 data_ov002_020cd304;
u32 data_ov002_020cd300;
const SomethingElse data_ov002_020cd11c[] = {
    {"KINOK", 0x9, 0x9, 0xA000}, {"KINO2", 0x9, 0x9, 0xC000}, {"KINO3", 0x9, 0x9, 0xA001}, {"WORLD", 0x8, 0x8, 0x0}, {"SAVE", 0x7, 0x7, 0x0}, {"TITLE", 0x4, 0x4, 0x0}, {"ENDIN", 0xC, 0xC, 0x0}, {"CRSIN", 0xD, 0xD, 0x0}, {"GOVER", 0xE, 0xE, 0x0}, {"KEY", 0x11, 0x11, 0x0}, {"SOUND", 0x10, 0x10, 0x0}, {"ENTRY", 0x6, 0x6, 0x0}, {"ERROR", 0xB, 0xB, 0x0}, {"MGVS", 0x146, 0x146, 0x0},
};

DebugScene::DebugScene()
{
}
void *DebugScene::create()
{
	return new DebugScene();
}

s32 DebugScene::onCreate()
{
	return true;
}

bool DebugScene::onHeapCreated()
{
	return true;
}

s32 DebugScene::onDestroy()
{
	u16 a[1];
	FS::Cache::clear();
	a[0] = 0;
	Nitro_::func_02063af0(a, 0, 2);
	return true;
}

void DebugScene::pendingDestroy()
{
}

s32 DebugScene::onRender()
{
	return true;
}

s32 DebugScene::onUpdate()
{
	return true;
}

extern u32 func_0201f5fc(u32);
extern u32 func_0201f590(u32, u32);
extern u32 func_0201f53c(u32, u32, u32);
extern u32 func_02020580(u32, u32);
extern u32 func_0200696c(u32, u32, u32, u32);
extern void func_02011e3c(u32);
extern void func_020066f8();
extern void func_02006740();
extern u16 data_02087648[2];
extern u32 data_02087650[2];
extern u32 iRam020cd304;
extern u32 iRam020cd300;
extern u32 data_02085a0c;
extern u32 _data_02085a90;
extern u32 data_0208b4f0;
extern u32 data_02085a1c;
extern u32 data_02085a10;
extern u32 data_02088e04;
extern u32 uRam02088e06;
extern u32 uRam02088bfc;
extern u32 uRam02088e07;
extern u32 uRam02088c04;
extern u32 uRam02088e05;
void DebugScene::func_ov002_020cc514()
{
	u32 console_id = (u32)Input::localConsoleID;
	if ((Input::consoleKeys[console_id][0] & 4) != 0) {
		this->_190 = 1;
		return;
	}
	if ((data_02087648[0] & 0x80) == 0) {
		if (((data_02087648[0] & 0x40) != 0) && (this->_1ac = this->_1ac - 1, this->_1ac < 0)) {
			this->_1ac = 0xf;
		}
	} else {
		this->_1ac = this->_1ac + 1;
		if (0xf < this->_1ac) {
			this->_1ac = 0;
		}
	}
	u32 iVar2 = *(int *)this->_pad1;
	u32 uVar1 = this->_1ac;
	if (uVar1 < iVar2 + 10) {
		if (uVar1 < iVar2) {
			*(u32 *)this->_pad1 = uVar1;
		}
	} else {
		*(u32 *)this->_pad1 = uVar1 - 9;
	}
	switch (this->_1ac) {
	case 0:
		if ((data_02087648[0] & 0x10) == 0) {
			if ((data_02087648[0] & 0x20) != 0) {
				this->_194 = this->_194 - 1;
				if (this->_194 < 0) {
					this->_194 = 9;
				}
				iVar2 = func_0201f5fc(this->_194);
				if (iVar2 == 0) {
					u32 *puVar3 = &this->_194;
					do {
						*puVar3 = *puVar3 - 1;
						if (this->_194 < 0) {
							this->_194 = 9;
						}
						iVar2 = func_0201f5fc(this->_194);
					} while (iVar2 == 0);
				}
			}
		} else {
			this->_194 = this->_194 + 1;
			if (9 < this->_194) {
				this->_194 = 0;
			}
			iVar2 = func_0201f5fc(this->_194);
			if (iVar2 == 0) {
				u32 *puVar3 = &this->_194;
				do {
					*puVar3 = *puVar3 + 1;
					iVar2 = func_0201f5fc(this->_194);
				} while (iVar2 == 0);
			}
		}
		iVar2 = func_0201f5fc(this->_194);
		if (iVar2 <= this->_198) {
			this->_198 = 0;
		}
		iVar2 = func_0201f590(this->_194, this->_198);
		if (iVar2 <= this->_19c) {
			this->_19c = 0;
		}
		iVar2 = func_0201f53c(this->_194, this->_198, this->_19c);
		if (this->_pad0[iVar2 + -0x44] <= this->_1a0) {
			this->_1a0 = 0xffffffff;
		}
		break;
	case 1:
		if ((data_02087648[0] & 0x10) == 0) {
			if ((data_02087648[0] & 0x20) == 0) {
				if ((data_02087648[0] & 0x100) == 0) {
					if (((data_02087648[0] & 0x200) != 0) && (this->_198 = this->_198 - 10, this->_198 < 0)) {
						iVar2 = func_0201f5fc(this->_194);
						this->_198 = iVar2 - 1;
					}
				} else {
					this->_198 = this->_198 + 10;
					iVar2 = func_0201f5fc(this->_194);
					if (iVar2 <= this->_198) {
						this->_198 = 0;
					}
				}
			} else {
				this->_198 = this->_198 - 1;
				if (this->_198 < 0) {
					iVar2 = func_0201f5fc(this->_194);
					this->_198 = iVar2 - 1;
				}
			}
		} else {
			this->_198 = this->_198 + 1;
			iVar2 = func_0201f5fc(this->_194);
			if (iVar2 <= this->_198) {
				this->_198 = 0;
			}
		}
		iVar2 = func_0201f590(this->_194, this->_198);
		if (iVar2 <= this->_19c) {
			this->_19c = 0;
		}
		iVar2 = func_0201f53c(this->_194, this->_198, this->_19c);
		if (this->_pad0[iVar2 + -0x44] <= this->_1a0) {
			this->_1a0 = 0xffffffff;
		}
		break;
	case 2:
		if ((data_02087648[0] & 0x10) == 0) {
			if ((data_02087648[0] & 0x20) != 0) {
				if (((data_02087650[console_id] & 0x200) == 0) && ((data_02087650[console_id] & 0x100) == 0)) {
					this->_19c = this->_19c - 1;
				} else {
					this->_19c = this->_19c - 10;
				}
				if (this->_19c < 0) {
					iVar2 = func_0201f590(this->_194, this->_198);
					this->_19c = iVar2 - 1;
				}
			}
		} else {
			if (((data_02087650[console_id] & 0x200) == 0) && ((data_02087650[console_id] & 0x100) == 0)) {
				this->_19c = this->_19c + 1;
			} else {
				this->_19c = this->_19c + 10;
			}
			iVar2 = func_0201f590(this->_194, this->_198);
			if (iVar2 <= this->_19c) {
				this->_19c = 0;
			}
		}
		iVar2 = func_0201f53c(this->_194, this->_198, this->_19c);
		if (this->_pad0[iVar2 + -0x44] <= this->_1a0) {
			this->_1a0 = 0xffffffff;
		}
		break;
	case 3:
		iVar2 = func_0201f53c(this->_194, this->_198, this->_19c);
		if ((data_02087648[0] & 0x10) == 0) {
			if (((data_02087648[0] & 0x20) != 0) && (this->_1a0 = this->_1a0 - 1, this->_1a0 < -2)) {
				this->_1a0 = this->_pad0[iVar2 + -0x44] - 1;
			}
		} else {
			this->_1a0 = this->_1a0 + 1;
			if (this->_pad0[iVar2 + -0x44] <= this->_1a0) {
				this->_1a0 = 0xfffffffe;
			}
		}
		break;
	case 4:
		if ((data_02087648[0] & 0x10) == 0) {
			if (((data_02087648[0] & 0x20) != 0) && (this->_1a4 = this->_1a4 - 1, this->_1a4 < 0)) {
				this->_1a4 = 2;
			}
		} else {
			this->_1a4 = this->_1a4 + 1;
			if (2 < this->_1a4) {
				this->_1a4 = 0;
			}
		}
		break;
	case 5:
		if ((data_02087648[0] & 0x10) == 0) {
			if (((data_02087648[0] & 0x20) != 0) && (iRam020cd304 += -1, iRam020cd304 < 0)) {
				iRam020cd304 = 3;
			}
		} else {
			iRam020cd304 += 1;
			if (3 < iRam020cd304) {
				iRam020cd304 = 0;
			}
		}
		break;
	case 6:
		if ((data_02087648[0] & 0x10) == 0) {
			if (((data_02087648[0] & 0x20) != 0) && (iRam020cd300 += -1, iRam020cd300 < 0)) {
				iRam020cd300 = 5;
			}
		} else {
			iRam020cd300 += 1;
			if (5 < iRam020cd300) {
				iRam020cd300 = 0;
			}
		}
		break;
	case 7:
		if ((data_02087648[0] & 0x10) == 0) {
			if (((data_02087648[0] & 0x20) != 0) && (this->_1d8 = this->_1d8 - 1, this->_1d8 < 0)) {
				this->_1d8 = 4;
			}
		} else {
			this->_1d8 = this->_1d8 + 1;
			if (4 < this->_1d8) {
				this->_1d8 = 0;
			}
		}
		data_02085a0c = this->_1d8;
		break;
	case 8:
		if (((data_02087648[0] & 0x10) != 0) || ((data_02087648[0] & 0x20) != 0)) {
			this->_1cc = this->_1cc ^ 1;
		}
		break;
	case 9:
		if ((data_02087648[0] & 0x10) == 0) {
			if (((data_02087648[0] & 0x20) != 0) && (this->_1d0 = this->_1d0 - 1, this->_1d0 < -2)) {
				this->_1d0 = 0x6f;
			}
		} else {
			this->_1d0 = this->_1d0 + 1;
			if (0x6f < this->_1d0) {
				this->_1d0 = 0xfffffffe;
			}
		}
		if ((data_02087648[0] & 0x100) == 0) {
			if ((data_02087648[0] & 0x200) != 0) {
				this->_1d0 = this->_1d0 - 0x80;
			}
		} else {
			this->_1d0 = this->_1d0 + 0x80;
		}
		_data_02085a90 = this->_1d0;
		break;
	case 10:
		if (((data_02087648[0] & 0x10) != 0) || ((data_02087648[0] & 0x20) != 0)) {
			this->_1c8 = this->_1c8 ^ 1;
		}
		data_02085ad4[0] = this->_1c8; // data_02085ad4 = this->_1c8;
		break;
	case 0xb:
		if ((data_02087648[0] & 0x10) == 0) {
			if ((data_02087648[0] & 0x20) != 0) {
				if (((data_02087650[console_id] & 0x200) == 0) && ((data_02087650[console_id] & 0x100) == 0)) {

					this->_1d4 = this->_1d4 - 1;
				} else {
					this->_1d4 = this->_1d4 - 10;
				}
				if (this->_1d4 < 0) {
					this->_1d4 = 999;
				}
			}
		} else {
			if (((data_02087650[console_id] & 0x200) == 0) && ((data_02087650[console_id] & 0x100) == 0)) {

				this->_1d4 = this->_1d4 + 1;
			} else {
				this->_1d4 = this->_1d4 + 10;
			}
			if (999 < this->_1d4) {
				this->_1d4 = 0;
			}
		}
		if (this->_1d4 == 0) {
			func_02020580(0, 3);
			func_02020580(1, 3);
		} else {
			func_02020580(0, 0);
			func_02020580(1, this->_1d4);
		}
		break;
	case 0xc:
		if ((data_02087648[0] & 0x10) == 0) {
			if (((data_02087648[0] & 0x20) != 0) && (this->_1dc = this->_1dc - 1, this->_1dc < 0)) {
				this->_1dc = 2;
			}
		} else {
			this->_1dc = this->_1dc + 1;
			if (2 < this->_1dc) {
				this->_1dc = 0;
			}
		}
		break;
	case 0xd:
		if (((data_02087648[0] & 0x10) != 0) || ((data_02087648[0] & 0x20) != 0)) {
			this->_1e0 = this->_1e0 ^ 1;
		}
		break;
	case 0xe:
		if ((data_02087648[0] & 0x10) == 0) {
			if (((data_02087648[0] & 0x20) != 0) && (this->_1e4 = this->_1e4 - 1, this->_1e4 < 0)) {
				this->_1e4 = 2;
			}
		} else {
			this->_1e4 = this->_1e4 + 1;
			if (2 < this->_1e4) {
				this->_1e4 = 0;
			}
		}
		break;
	case 0xf:
		if ((data_02087648[0] & 0x10) == 0) {
			if (((data_02087648[0] & 0x20) != 0) && (this->_1e8 = this->_1e8 - 1, this->_1e8 < 0)) {
				this->_1e8 = 2;
			}
		} else {
			this->_1e8 = this->_1e8 + 1;
			if (2 < this->_1e8) {
				this->_1e8 = 0;
			}
		}
	}
	if (((Input::consoleKeys[Input::localConsoleID][0] & 1) == 0) && ((Input::consoleKeys[Input::localConsoleID][0] & 8) == 0)) {
		if (this->_1a8 == 0) {
			return;
		}
		if (data_0208b4f0 == '\0') {
			return;
		}
	}
	u32 bVar4 = this->_1a0 != 0xfffffffe;
	if (bVar4) {
		func_020066f8();
	} else {
		this->_1a0 = 0xffffffff;
		func_02006740();
	}
	data_02085a1c = !bVar4;
	data_02085a10 = this->_1dc;
	func_0200696c(0xd, 0, this->_194 & 0xff, this->_198 & 0xff);
	uVar1 = this->_1e8;
	if (uVar1 == 0) {
		data_02088e04 = 0xff;
		uRam02088e06 = 0xff;
	} else if (uVar1 == 1) {
		uRam02088bfc = 0;
		uRam02088c04 = 0;
		data_02088e04 = 0;
		uRam02088e06 = 0xff;
		uRam02088e05 = 0;
	} else if (uVar1 == 2) {
		uRam02088bfc = 0;
		uRam02088c04 = 0;
		data_02088e04 = 0xff;
		uRam02088e06 = 0;
		uRam02088e07 = 1;
	}
	func_02011e3c(0x1e);
}

void func_020131fc(u32, u32);
void DebugScene::func_ov002_020cc328()
{
	u16 local_console_id = Input::localConsoleID;
	if ((Input::consoleKeys[local_console_id][0] & 4) != 0) {
		this->_1d8 = 0;
		return;
	}

	i32 b = this->_1fc % 5;
	i32 c = this->_1fc / 5;
	i32 d = 5;
	if (c == 2) {
		d = 4;
	}
	i32 e = 3;
	if (4 <= b) {
		e -= 1;
	}

	if ((Input::consoleKeysRepeated[0] & 0x10)) {
		b += 1;
		if (b >= d) {
			b = 0;
		}
	} else if ((Input::consoleKeysRepeated[0] & 0x20)) {
		b -= 1;
		if (b < 0) {
			b = d + -1;
		}
	} else if ((Input::consoleKeysRepeated[0] & 0x80)) {
		c += 1;
		if (c >= e) {
			c = 0;
			this->_204 = 0;
		} else if (c >= this->_204 + 10) {
			this->_204 += 1;
		}
	} else if ((Input::consoleKeysRepeated[0] & 0x40)) {
		c -= 1;
		if (c < 0) {
			this->_204 = e - 10;
			c = e + -1;
			if (this->_204 < 0) {
				this->_204 = 0;
			}
		} else if (c < this->_204) {
			this->_204 -= 1;
		}
	}

	this->_1fc = c * 5 + b;
	if (((Input::consoleKeys[local_console_id][0] & 1) == 0) && ((Input::consoleKeys[local_console_id][0] & 8) == 0)) {
		return;
	}
	Stage::stageGroup = this->_1dc;
	Stage::stageID = this->_1e0;
	Stage::stageAreaID = this->_1e4;
	u32 uVar1;
	if (Input::consoleKeys[local_console_id][0] & 1) {
		uVar1 = data_ov002_020cd11c[this->_1fc].c;
	} else {
		uVar1 = data_ov002_020cd11c[this->_1fc].b;
	}
	func_020131fc(uVar1, data_ov002_020cd11c[this->_1fc].d);
	GlobalFader.func_02007bfc();
}

DebugScene::~DebugScene()
{
}


const u8 data_ov002_020cd114[4] = {0, 1, 3, 0};
u8 data_ov002_020cd240[4][2] = {
    {0, 0},
    {1, 0},
    {0, 1},
    {0, 0},
};
ObjectProfile DebugScene_Profile = {DebugScene::create, 2, 9};

void (DebugScene::*data_ov002_020cd308[])() = {DebugScene::func_ov002_020cc514, DebugScene::func_ov002_020cc328};

u8 data_ov002_020cd220[4] = {1, 1, 3, 0};
