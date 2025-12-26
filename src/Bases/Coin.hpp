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
    u32 _4c0;
    u32 _4c4;
    u32 _4ce;
    u8 _4d8;
    u32 _4d9;
    u32 _4df;
    u32 _4e0;
    u8 _pad0[0x28];

    inline Coin();
    ~Coin();

    void func_ov010_020d81dc(u32);
    void func_ov010_020d9dcc(PTMF*);
    void func_ov010_020d823c(u32 a);

    void* operator new(u32);

    bool onCreate();
    bool onDestroy();
    bool onRender();

    bool _00();
    void _11();
    void _21();
    void _34();
};