#include "StageEntity.hpp"

class Coin : StageEntity {
public:
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