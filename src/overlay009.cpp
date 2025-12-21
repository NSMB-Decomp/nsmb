#include "base_types.hpp"

// Titlescreen Logo
class Logo {
public: 
    u32 _00;
    u32 _04;
    u32 _08;
    u32 _0c;
    i32 _10;
    i32 _14;
    i32 _18;
    i16 _1c;
    i16 _1e;
    i16 _20;

    void func_ov009_020cc914();
    void func_ov009_020cc8ac();
    void func_ov009_020cc87c(u32);
    void func_ov009_020cd014();
    void func_ov009_020ccf38();
};

// func_0200421c - render sprite. Nitro Function?
void Logo::func_ov009_020cd014() { // render static logo segments
    /*
      if (*(int *)(param_1 + 0x78) != 0) {
                    // Unknown TODO: What does this render?
        func_0200421c(3,&data_ov009_020db9f4,0,0,0,0,0,0,0,1,-*(int *)(_DAT_020dbbb0 + 200) >> 0xc);
                        // Copyright
        func_0200421c(4,&data_ov009_020dba70,0,0,0,0,0,0,0,0,-*(int *)(_DAT_020dbbb0 + 200) >> 0xc);
                        // Logo with Shadow + Trademark
        func_0200421c(5,&data_ov009_020dba98,0,0,0,0,0,0,0,3,-*(int *)(_DAT_020dbbb0 + 200) >> 0xc);
    }
    iVar1 = 0;
    do {
        func_ov009_020ccf38(param_1,iVar1);
        iVar1 = iVar1 + 1;
        param_1 = param_1 + 0x28;
    } while (iVar1 < 3);
  */
}

void Logo::func_ov009_020ccf38() { // Render dynamic Logo
    /*

    {
    undefined4 *puVar1;
    undefined2 uVar2;
    
    puVar1 = (undefined4 *)(&data_ov009_020d9684 + *(int *)(param_1 + 0x24) * 0xc + param_2 * 0x18);
    if (*(int *)(param_1 + 0x24) == 0) {
        uVar2 = *(undefined2 *)(param_1 + 0x1c);
    }
    else {
        uVar2 = 0;
    }
                        // Main Logo
    func_0200421c(*puVar1,puVar1[1],0x10,*(undefined1 *)(puVar1 + 2),0,0,uVar2,0,0,
                    (int)*(char *)((int)puVar1 + 9),
                    (int)*(char *)((int)puVar1 + 10) +
                    (*(int *)(param_1 + 0x10) - *(int *)(_DAT_020dbbb0 + 200) >> 0xc));
    */
}

void Logo::func_ov009_020cc914() {

}

void Logo::func_ov009_020cc8ac() {
    if (0 <= this->_1e) {
        if (this->_14 > 0) {
            this->_20 = 0x11;
        }
        else {
            this ->_1e = 0;
            this ->_20 = 0;
        }
    }

    if (0 <= this->_10) {
        this->_14 = 0;
        this->_18 = 0;
        this->_1c = 0;
        this->_1e = 0;
        this->_20 = 0;
        Logo::func_ov009_020cc87c(0xf);
    }
}


void func_ov009_020cc8a8() {}

void Logo::func_ov009_020cc87c(u32 a) {
  this->_00 = a;
  this->_04 = *(int *)((a * 8) + 0x20dbd24);
  this->_08 = *(int *)((a * 8) + 0x20dbd28);
  this->_0c = 0;
}

void func_ov009_020cc85c() {

}

void func_ov009_020cc858() {

}

void func_ov009_020cc854() {

}

void func_ov009_020cc810(u32* a) {

}

void func_ov009_020cc70c(u32* a) {

}

void func_02007c44(void*);
void func_02007bfc(void*);
void* data_02088f48 = (void*)0x1234;
void func_ov009_020cc6e8() {
    func_02007c44(&data_02088f48);
    func_02007bfc(&data_02088f48);
}

void func_ov009_020cc6d4(i32 *a,i32 b,i32 c) {
  if (b > *a) {
    a[0] = b;
    a[1] = c;
  }
}

u32 _CurrentWindow = (*(u32*)0x02085b10);
void func_ov009_020cc6b4(u8 *a) {
    _CurrentWindow = (u32)a;
    a[0] = 0;
    a[1] = 0;
    a[2] = 0;
}

void func_ov009_020cc5f8() {

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