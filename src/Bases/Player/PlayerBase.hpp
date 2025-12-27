#include "../StageActor.hpp"
#include "PlayerModel.hpp"

class PlayerBase : public StageActor {
    u8 _pad0[0x4];
    u8 _2c4;
    u8 _pad1[0x4b4];
    u32 _77c;
    u32 _780;
    u8 _pad2[0x14];
    u32 _798;
    u8 _pad3[0xd];
    u8 _7a9;
    u8 _pad4[0x1];
    i8 _7ab;
    i8 _7ac;
    u8 _pad5[0x3];
    i8 _7b0;
    u8 _pad6[0xe];
    u8 _7bf;

    i8 func_ov011_0212b1d4();
    u16 func_ov011_0212b210(u16);
    void setPosition(Vec3_32*);
    void func_ov011_0212b26c(u32);
    bool func_ov011_0212b2bc();
    void func_ov011_0212b384(i16);
    void func_ov011_0212b710();
    void func_ov011_0212b740(u32);
    void func_ov011_0212b7bc(u32);
    void func_ov011_0212b7f0(u32);
    void func_ov011_0212b810(u32);
    void func_ov011_0212b820(u32, u32, u32);
    void func_ov011_0212b838(u32, Vec3_32*);
    void func_ov011_0212b84c(u32, u32, u32);
    void func_ov011_0212b864(u32, u32);
    void func_ov011_0212b878(u16);
    void func_ov011_0212b8bc();
    void func_ov011_0212b908();
    void func_ov011_0212b954();
    void func_ov011_0212b984();
    void func_ov011_0212b998();
    void func_ov011_0212b9a8();
    bool func_ov011_0212b9ac(u8);
    bool func_ov011_0212b9f8(u8);
    void func_ov011_0212bac8();
    bool func_ov011_0212bb90();
    u32 func_ov011_0212bba4();
    void func_ov011_0212bbcc();
    PlayerBase();
};