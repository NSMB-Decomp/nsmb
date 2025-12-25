#include "StageEntity.hpp"

class Coin : StageEntity {
public:
    u8 _pad0[0x55];
    i32 _444;
    u8 _pad1[0x7c];
    u32 _4c0;

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