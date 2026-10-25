#include "ExceptionHandler.hpp"
#include "base_types.hpp"
#include "system/app.hpp"

void *_data_0208b72c;
void *_data_0208b730;

u32 Nitro_GetCpsrM();
void Heap_dump(void *);

void showExceptionHandler()
{
}
void showExceptionHandlerSub()
{
}
void func_02005ea8()
{
}
void func_02005e68()
{
}
void setupGraphicsForDebugScreen2()
{
	App::resetGpu();
	REG_POWER_CNT |= 1;
	G2_BlendNone(); //REG_BLDCNT = 0;
	G2S_BlendNone(); //REG_BLDCNT_SUB = 0;
	Nitro::func_02061ac4(0x40);
	Nitro::func_020613c8(0x80);
	GX_SetVisiblePlane(0x2); // REG_DISPCNT = REG_DISPCNT & ~0x1f00 | 0x200;
	GXS_SetVisiblePlane(0x2); //REG_DISPCNT_SUB = REG_DISPCNT_SUB & ~0x1f00 | 0x200;
	G2_SetBG1Control(0,8,0,0,0); //REG_BG1CNT = REG_BG1CNT & 0x43 | 0x400;
	G2S_SetBG1Control(0,8,0,0,0); //REG_BG1CNT_SUB = REG_BG1CNT_SUB & 0x43 | 0x400;
	//  iVar1 = Nitro::func_02061fa4();
	//  Nitro::func_02067258(&data_02039218,iVar1 + 0x400);
	//  iVar1 = Nitro::func_02061f84();
	//  Nitro::func_02067258(&data_02039218,iVar1 + 0x400);
	//  Nitro::func_02063af0(&data_02039838,0x1a0,0x60);
	//  Nitro::func_02063a88(&data_02039838,0x1a0,0x60);
	//  _DAT_05000000 = 0x7c00;
	//  uRam05000018 = 0x7c00;
	//  uRam05000400 = 0x7c00;
	//  uRam05000418 = 0x7c00;
	//  _data_020859ec = Nitro::func_02062264();
	//  _data_020859e8 = Nitro::func_02062244();
	//  func_02005e68();
	//  Nitro::EnableDisplay();
	//  REG_DISPCNT_SUB = REG_DISPCNT_SUB | 0x10000;
}
void DebugScreenWaitForVblank()
{
	while(0xc0 < REG_VCOUNT) {}
	while(REG_VCOUNT < 0xc0){}
}

u8 ExceptionHandlerState;
u32 ExceptionHandlerKeys;
void func_02005b34()
{
	u8 newState = ExceptionHandlerState;
	u32 keys = PAD_Read() & 0x3FF;
	u32 keysPressed = ExceptionHandlerKeys ^ keys;
	ExceptionHandlerKeys = keys;
	u32 unknown = keys & keysPressed;
	switch (newState) {
	case 0: // Wait for L + R + LEFT + A
		if (unknown & 0x2000) { // If device is folded?
			newState = 5;
		}

		if (keys == (PAD_BUTTON_L | PAD_BUTTON_R | PAD_KEY_LEFT | PAD_BUTTON_A)) {
			newState += 1;
		}
		break;
	case 1: // Wait for release
		if (keys == 0x0) {
			newState += 1;
		}
		break;
	case 2: // Wait for Down + B
		if ((keys & ~(PAD_KEY_DOWN | PAD_BUTTON_B)) != 0) {
			newState = 0;
		} else {
			if (keys == (PAD_KEY_DOWN | PAD_BUTTON_B)) {
				newState += 1;
			}
		}
		break;
	case 3: // Wait for release
		if (keys == 0x0) {
			newState += 1;
		}
		break;
	case 4: // Wait for Start + Select
		if ((keys & ~(PAD_BUTTON_START | PAD_BUTTON_SELECT)) != 0) {
			newState = 0;
		} else if (keys == (PAD_BUTTON_START | PAD_BUTTON_SELECT)) {
			newState += 1;
		}
		break;
	case 5: // Setup the debug screen
		setupGraphicsForDebugScreen2();
		showExceptionHandler();
		newState += 1;
	case 6: // Loop the debug screen
		showExceptionHandler();
		showExceptionHandlerSub();
		if (keys & PAD_BUTTON_SELECT ) {
			if ((unknown & PAD_BUTTON_A ) && (keys & PAD_BUTTON_SELECT)) {
				if (Nitro_GetCpsrM() == 0x1F) {
					Heap* a = (Heap*)_data_0208b730;
					Heap* c = (Heap*)_data_0208b72c;
					Heap* b = Memory_gameHeap;
					if (keys & PAD_KEY_LEFT) {
                        Heap_dump(a);
					} else if (keys & PAD_KEY_RIGHT) {
						Heap_dump(b);
					} else if (keys & PAD_KEY_UP) {
						Heap_dump(c);
					}
				}
			}
		}
	}
	DebugScreenWaitForVblank();
	ExceptionHandlerState = newState;
}

void ExceptionHandlerLoop()
{
	OS_DisableIrq();
	while (true) {
		func_02005b34();
	}
}
