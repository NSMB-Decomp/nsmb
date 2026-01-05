#include "ExceptionHandler.hpp"
#include "base_types.hpp"
#include "Nitro.hpp"

void* data_0208b720;
void* _data_0208b72c;
void* _data_0208b730;

u32 Nitro_GetCpsrM();
void func_02005cdc();
void Heap_dump(void*);
void setupGraphicsForDebugScreen();

void showExceptionHandler() {}
void showExceptionHandlerSub() {}
void func_02005ea8() {}
void func_02005e68() {}
void setupGraphicsForDebugScreen2() {
    setupGraphicsForDebugScreen();
    REG_POWER_CNT |= 1;
    REG_BLDCNT = 0;
    REG_BLDCNT_SUB = 0;
    Nitro::func_02061ac4(0x40);
    Nitro::func_020613c8(0x80);
    REG_DISPCNT = REG_DISPCNT & ~0x1f00 | 0x200;
    REG_DISPCNT_SUB = REG_DISPCNT_SUB & ~0x1f00 | 0x200;
    REG_BG1CNT = REG_BG1CNT & 0x43 | 0x400;
    REG_BG1CNT_SUB = REG_BG1CNT_SUB & 0x43 | 0x400;
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
void func_02005cdc() {}

#define UNKWN         *((u16*)0x27ffa8)

u32 ExceptionHandlerState;
u32 ExceptionHandlerKeys;
u16 func_02005b34(u16) {
    u32 newState = ExceptionHandlerState;
    u32 keys = ( REG_KEYINPUT | UNKWN ) ^ KEYS_ALL;
    u32 keysHeld = keys & (KEY_A|KEY_B|KEY_SELECT|KEY_START|KEY_RIGHT|KEY_LEFT|KEY_UP|KEY_DOWN|KEY_R|KEY_L);
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
            }
            else {
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
            }
            else {
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
            if (((((keys & 4) != 0) && ((keysHeld & keysPressed & 1) != 0)) && ((keys & 4) != 0)) &&
                (iVar2 = Nitro_GetCpsrM(), iVar2 == 0x1f)) {
                if ((keys & 0x20) == 0) {
                    if ((keys & 0x10) == 0) {
                    if ((keys & 0x40) != 0) {
                        Heap_dump(_data_0208b72c);
                    }
                    }
                    else {
                    Heap_dump(data_0208b720);
                    }
                }
                else {
                    Heap_dump(_data_0208b730);
                }
                }
    }
    func_02005cdc();
    ExceptionHandlerState = newState;
}

void ExceptionHandlerLoop() {
    u16 a = REG_IME;
    REG_IME = 0;
    while (true) {
        a = func_02005b34(a);
    }
}