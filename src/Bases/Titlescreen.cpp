#include "../base_types.hpp"

void func_ov009_020cc6d4(u32 *a,u32 b,u32 c) {
  if (*a < b) {
    a[0] = b;
    a[1] = c;
  }
}

u32 _CurrentWindow = (*(u32*)0x02085b10);
void func_ov009_020cc6b4(u8 *a) {
    _CurrentWindow = (u32)&a;
    a[0] = 0;
    a[1] = 0;
    a[2] = 0;
}

void func_ov009_020cc5e8(u8 *a, u8 b) {
  a[0] = 1;
  a[1] = b;
}

void func_ov009_020cc5d4() {
    _CurrentWindow = 0;
}


void func_ov009_020cc560(u32*a) {
    u16* _REG_BG0CNT = (u16*)0x04000008;
    u16* _REG_BG1CNT = (u16*)0x0400000a;
    u16* _REG_BG2CNT = (u16*)0x0400000c;
    u16* _REG_BG3CNT = (u16*)0x0400000e;

    // TODO: Turn this into a Macro
    *_REG_BG0CNT = *_REG_BG0CNT & ~3;
    *_REG_BG1CNT = *_REG_BG1CNT & ~3 | 3;
    *_REG_BG2CNT = *_REG_BG2CNT & ~3 | 1;
    *_REG_BG3CNT = *_REG_BG3CNT & ~3 | 2;
    *a = 0;
}

void func_ov009_020cc4ec(u32 *a) {
    u16* _REG_BG0CNT = (u16*)0x04000008;
    u16* _REG_BG1CNT = (u16*)0x0400000a;
    u16* _REG_BG2CNT = (u16*)0x0400000c;
    u16* _REG_BG3CNT = (u16*)0x0400000e;

    // TODO: Turn this into a Macro
    *_REG_BG0CNT = *_REG_BG0CNT & ~3 | 1;
    *_REG_BG1CNT = *_REG_BG1CNT & ~3 | 3;
    *_REG_BG2CNT = *_REG_BG2CNT & ~3;
    *_REG_BG3CNT = *_REG_BG3CNT & ~3 | 2;
    *a = 1;
}

void func_ov009_020cc4d0(u32* a) {
    a[0] = 0;
    a[2] = 0;
    a[3] = 0;
    a[4] = 0;
    a[5] = 0;
}

void func_ov009_020cc310(u32 *a) {

}

void func_ov009_020cc304(u32* a) {
    *a = 1;
}

void func_ov009_020cc2f8(u32* a) {
    *a = 2;
}

void func_ov009_020cc2ec(u32* a) {
    *a = 3;
}

void func_ov009_020cc2e0(u32* a) {
    *a = 4;
}