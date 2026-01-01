#include "PlayerBase.hpp"

class PendulumController
{
public:
    PendulumController();
};

class Unknown
{
public:
    Vec3_32 a;
    Unknown();
    ~Unknown();
};

class Unknown2
{
public:
    ~Unknown2();
};

class PlayerActor : public PlayerBase
{
public:
    u8 _pad0[0x48];
    ActiveCollider _814;
    PendulumController _8c4;
    u8 _pad1[0x18];
    Unknown _8e0;
    u8 _pad2[0x24];
    Vec3_16 _914;
    Vec3_16 _920;
    Vec3_32 _92c;
    Vec3_32 _93c;
    Vec3_32 _94c;
    Vec2_32 _95c;
    Vec2_32 _968;
    Vec2_32 _974;
    u8 _pad3[588];

    PlayerActor();
    ~PlayerActor();
};
size_assert(PlayerActor, 0xbcc);