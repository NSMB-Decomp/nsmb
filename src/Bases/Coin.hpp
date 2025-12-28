#include "StageEntity.hpp"
#include "../Collision/Collider.hpp"

class Coin : public StageEntity {
public:
    u32 _3f4; // 0x3F4
    Vec3_32 _3f8; // 0x3F8
    Vec3_32 _408; // 0x408
    Vec2_32 _418; // 0x418
    Vec2_32 _424; // 0x424
    PTMF* _430; // 0x430
    Vec3_32 _434; // 0x434
    Collider _444; // 0x444
    u8 _pad0[9];
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
    u8 _pad3[0x3];
    u8 _4e3;
    u8 _4e4;

    inline Coin();
    ~Coin();
    void* operator new(u32);

    void func_ov010_020d81dc(u32);
    void func_ov010_020d9dcc(PTMF*);
    void func_ov010_020d823c(u32 a);
    void func_ov010_020d99a8();
    void func_ov010_020d8b40();

    bool onCreate();
    bool onDestroy();
    bool onRender();

    bool onUpdate_0();
    void _11();
    void _21();
    void onStageComplete(PlayerActor* player);
};
size_assert(Coin, 0x4e8);