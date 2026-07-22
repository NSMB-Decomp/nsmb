#include "../ExceptionHandler.hpp"
#include "app.hpp"
#include "../base_types.hpp"
#include "../Heap.hpp"

Heap *_data_0208b72c;
Heap *_data_0208b730;

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
	REG_BLDCNT = 0;
	REG_BLDCNT_SUB = 0;
	NDS::Graphics::assignMainBackgroundBank(0x40);
	NDS::Graphics::assignSubBackgroundBank(0x80);
	REG_DISPCNT = REG_DISPCNT & ~0x1f00 | 0x200;
	REG_DISPCNT_SUB = REG_DISPCNT_SUB & ~0x1f00 | 0x200;
	REG_BG1CNT = REG_BG1CNT & 0x43 | 0x400;
	REG_BG1CNT_SUB = REG_BG1CNT_SUB & 0x43 | 0x400;
	//  iVar1 = NDS::Graphics::mainBackground1Tiles();
	//  NDS::Memory::decompressLz16(&data_02039218,iVar1 + 0x400);
	//  iVar1 = NDS::Graphics::subBackground1Tiles();
	//  NDS::Memory::decompressLz16(&data_02039218,iVar1 + 0x400);
	//  Upload the recovered palette data once its owning object is typed.
	//  NDS::Graphics::uploadSubBackgroundPalette(&data_02039838,0x1a0,0x60);
	//  _DAT_05000000 = 0x7c00;
	//  uRam05000018 = 0x7c00;
	//  uRam05000400 = 0x7c00;
	//  uRam05000418 = 0x7c00;
	//  _data_020859ec = NDS::Graphics::mainBackground1Map();
	//  _data_020859e8 = NDS::Graphics::subBackground1Map();
	//  func_02005e68();
	//  NDS::Graphics::enableDisplays();
	//  REG_DISPCNT_SUB = REG_DISPCNT_SUB | 0x10000;
}
void func_02005cdc()
{
}

#define UNKWN *((u16 *)0x27ffa8)

u32 ExceptionHandlerState;
u32 ExceptionHandlerKeys;
void func_02005b34()
{
	u32 newState = ExceptionHandlerState;
	u32 keys = (REG_KEYINPUT | UNKWN) ^ KEYS_ALL;
	u32 keysHeld = keys & (KEY_A | KEY_B | KEY_SELECT | KEY_START | KEY_RIGHT | KEY_LEFT | KEY_UP | KEY_DOWN | KEY_R | KEY_L);
	u32 keysPressed = keysHeld ^ ExceptionHandlerKeys;
	ExceptionHandlerKeys = keysHeld;
	switch (ExceptionHandlerState) {
	case 0:
		if (keysHeld == 0x321) {
			newState = ExceptionHandlerState + 1;
		}
		break;
	case 1:
		if (keysHeld == 0x0) {
			newState = ExceptionHandlerState + 1;
		}
		break;
	case 2:
		if ((keys & 0x37d) == 0) {
			if (keysHeld == 0x82) {
				newState = ExceptionHandlerState + 1;
			}
		} else {
			newState = '\0';
		}
		break;
	case 3:
		if (keysHeld == 0x0) {
			newState = ExceptionHandlerState + 1;
		}
		break;
	case 4:
		if ((keys & 0x3f3) == 0) {
			if (keysHeld == 0xc) {
				newState = ExceptionHandlerState + 1;
			}
		} else {
			newState = '\0';
		}
		break;
	case 5:
		setupGraphicsForDebugScreen2();
		showExceptionHandler();
		newState += 1;
	case 6:
		showExceptionHandler();
		showExceptionHandlerSub();
		newState += 1;
		u32 iVar2;
		if (((((keys & 4) != 0) && ((keysHeld & keysPressed & 1) != 0)) && ((keys & 4) != 0)) && (iVar2 = NDS::Cpu::readMode(), iVar2 == 0x1f)) {
			if ((keys & 0x20) == 0) {
				if ((keys & 0x10) == 0) {
					if ((keys & 0x40) != 0) {
						_data_0208b72c->test();
					}
				} else {
					Memory_gameHeap->test();
				}
			} else {
				_data_0208b730->test();
			}
		}
	}
	func_02005cdc();
	ExceptionHandlerState = newState;
}

void ExceptionHandlerLoop()
{
    (void)REG_IME;

    REG_IME = 0;
	while (true) {
		func_02005b34();
	}
}
