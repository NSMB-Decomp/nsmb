#include "StageEntity.hpp"

class Goomba : public StageEntity {
    u8 _pad0[0x68];
    
    static void* create();
    inline Goomba();

    bool onCreate();
};