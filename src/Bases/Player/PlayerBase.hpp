#include "../StageActor.hpp"
#include "PlayerModel.hpp"

class PlayerBase : public StageActor {
    i8 _7ac;
    i8 func_ov011_0212b1d4();
    u16 func_ov011_0212b210(u16);
    void setPosition(Vec3_32*);
    void func_ov011_0212b26c(u32);
    bool func_ov011_0212b2bc();
    PlayerBase();
};