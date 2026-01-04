#include "../base_types.hpp"
#include "../Bases/Base.hpp"
#include "../Vec.hpp"

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
    void func_ov000_020ac7bc();
    void func_ov000_020acc78();
    void func_ov000_020ac288();
    void func_ov000_020ac750();
    void func_ov000_020abcfc();
    void func_ov000_020ac21c();
    void func_ov000_020aba68();
    void func_ov000_020abc90();
    void Reset();
    void unlink();
    void updatePosition();
    void init(Base*, void*, u32, u32, u32);
};

void (Collider::*__1[])() = {
    Collider::func_ov000_020ac7bc,
    Collider::func_ov000_020acc78,
    Collider::func_ov000_020acc78
};
void (Collider::*__2[])() = {
    Collider::func_ov000_020ac288,
    Collider::func_ov000_020ac750,
    Collider::func_ov000_020ac750
};
void (Collider::*__3[])() = {
    Collider::func_ov000_020abcfc,
    Collider::func_ov000_020ac21c,
    Collider::func_ov000_020ac21c
};
void (Collider::*__4[])() = {
    Collider::func_ov000_020aba68,
    Collider::func_ov000_020abc90,
    Collider::func_ov000_020abc90
};