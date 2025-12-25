#include "StageEntity.hpp"

class Coin : StageEntity {
public:
    u8 _pad0[0x55];
    i32 _444;
    u8 _pad1[0x7c];
    u32 _4c0;
    u32 _4c4;
    u8 _pad2[0x4];
    u32 _4ce;
    u32 _4d8;
    u32 _4d9;
    u32 _4df;
    u32 _4e0;

    Coin();
    ~Coin();

    void* operator new(u32);

    bool onCreate();
    bool onDestroy();
    bool onRender();

    bool _00();
    void _11();
    void _21();
    void _34();
};