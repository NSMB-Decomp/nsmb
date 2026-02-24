#include "StageEntity.hpp"
#include "../Collision/Collider.hpp"

class Coin : public StageEntity {
public:
    u32 _3f4; // 0x3F4
    Vec3_32 _3f8; // 0x3F8
    Vec3_32 _408; // 0x408
    Vec2_32 _418; // 0x418
    Vec2_32 _424; // 0x424
    bool (Coin::**_430)(); // 0x430
    Vec3_32 _434; // 0x434
    Collider _444; // 0x444
    u8 _pad99[4];
    u32 _4a8;
    u8 _4ad;
    u8 _pad5[1];
    u32 _4b0;
    u8 _pad7[12];
    u32 _4c0;
    u32 _4c4;
    u16 _4ce;
    u16 _4d0;
    u16 _4d8;
    u16 _4da;
    u16 _4dc;
    u16 _4de;
    u16 _4e0;
    u16 _4e2;
    u8 _4e8; // 0x4E8
    u8 _4e9;
    u8 _4ea;
    u8 _4eb;
    u8 _4ec;
    u8 _4ed;
    u8 _4ee;
    u8 _4ef;
    u8 _4f0;
    u8 _4f1;
    u8 _pad3[0x1];
    i8 _4e3;
    i8 _4e4;

    inline Coin();
    ~Coin();
    static void* create();

    void func_ov010_020d81dc(u32);
    void func_ov010_020d823c(u32);
    void func_ov010_020d8488();
    void func_ov010_020d8b40();
    bool func_ov010_020d8b9c();
    bool func_ov010_020d8d9c();
    bool func_ov010_020d8eec();
    bool func_ov010_020d8fb0();
    bool func_ov010_020d9004();
    bool func_ov010_020d91f4();
    bool func_ov010_020d923c();
    bool func_ov010_020d93b4();
    bool func_ov010_020d9634();
    bool func_ov010_020d9890();
    void func_ov010_020d9acc();
    void func_ov010_020d9b40();
    bool func_ov010_020d9c78();
    void func_ov010_020d9cf0(StageEntity*);
    void func_ov010_020d9d84();
    bool func_ov010_020d9dcc(bool (Coin::**)());

    void func_ov010_020d9b84();
    void func_ov010_020d99a8();
    void func_ov000_0209ab90(u8, u8, u8, i8);

    bool onCreate();
    bool onDestroy();
    bool onRender();

    bool onUpdate_0();
    void _11();
    void _21();
    void onStageComplete(PlayerActor* player);
};
size_assert(Coin, 0x4e8);

//extern void (Coin::*__5[3])();
//extern void (Coin::*__6[3])();
//extern void (Coin::*__7[3])();
//extern void (Coin::*__8[3])();
//extern void (Coin::*__9[3])();
