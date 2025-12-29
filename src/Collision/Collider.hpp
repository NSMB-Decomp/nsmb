#include "../base_types.hpp"
#include "../Bases/Base.hpp"
#include "../Vec.hpp"


void func_ov000_020ac7bc();
void func_ov000_020acc78();
void func_ov000_020ac288();
void func_ov000_020ac750();
void func_ov000_020abcfc();
void func_ov000_020ac21c();
void func_ov000_020aba68();
void func_ov000_020abc90();
PTMF __1[3] = {
    {(u32)func_ov000_020ac7bc, 0},
    {(u32)func_ov000_020acc78, 0},
    {(u32)func_ov000_020acc78, 0}
};
PTMF __2[3] = {
    {(u32)func_ov000_020ac288, 0},
    {(u32)func_ov000_020ac750, 0},
    {(u32)func_ov000_020ac750, 0}
};
PTMF __3[3] = {
    {(u32)func_ov000_020abcfc, 0},
    {(u32)func_ov000_020ac21c, 0},
    {(u32)func_ov000_020ac21c, 0}
};
PTMF __4[3] = {
    {(u32)func_ov000_020aba68, 0},
    {(u32)func_ov000_020abc90, 0},
    {(u32)func_ov000_020abc90, 0}
};

class Collider {
public:
    u8 _pad[0x23];
    Vec2_32 a;
    Vec2_32 b;
    Vec2_32 c;
    Vec2_32 d;
    Vec2_32 e;

    Collider();
    ~Collider();

    void func_ov000_020ab18c();
    void Reset();
    void unlink();
    void updatePosition();
    void init(Base*, void*, u32, u32, u32);
};