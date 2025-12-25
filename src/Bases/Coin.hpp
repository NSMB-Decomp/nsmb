#include "StageEntity.hpp"

class Coin : StageEntity {
public:
    PTMF* _430;
    i32 _444;
    u32 _4c0;
    u32 _4c4;
    u32 _4ce;
    u8 _4d8;
    u32 _4d9;
    u32 _4df;
    u32 _4e0;

    Coin();
    ~Coin();

    void func_ov010_020d81dc(u32);
    void func_ov010_020d9dcc(PTMF*);

    void* operator new(u32);

    bool onCreate();
    bool onDestroy();
    bool onRender();

    bool _00();
    void _11();
    void _21();
    void _34();
};