#include "../StageActor.hpp"
#include "PlayerModel.hpp"

class PlayerBase : public StageActor {
    u8 _pad0[0x4bc];
    u32 _77c;
    u8 _pad1[0x18];
    u32 _798;
    i8 _7ac;

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
    PlayerBase();
};