#include "StageEntity.hpp"

class Goomba : public StageEntity {
    u8 _pad0[0x68];
    
    void* operator new(u32);
    inline Goomba();

    bool onCreate();
};