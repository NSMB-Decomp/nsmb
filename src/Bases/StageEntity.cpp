#include "StageEntity.hpp"

StageEntity::StageEntity()
{
    // this->_40 = 0x2;
    this->actorType = 0x2;
    this->actorCategory = (1 << this->actorType) | 0x80;
    this->actorCategory = this->actorCategory | 0x20;
    this->_2d0 = 0;
    this->_3e7 = ~0;
    this->_3b4 = 0x107;
    this->accelV = -0x300;
    this->minVelocity.x = 0;
    this->minVelocity.y = -0x4000;
    this->minVelocity.z = 0;
    this->_3d8 = 0;
    this->_3a8 = 0x1000;
    this->_36c.x = 0;
    this->_36c.y = 0;
    this->_384.x = 0;
    this->_384.y = 0;
    this->_378.x = 0;
    this->_378.y = 0;
    this->_31c.x = 0;
    this->_31c.y = 0;
    this->_31c.z = 0;
    this->_2ca = 0;
    this->_3c6[0] = 0;
    this->_3c6[1] = 0;
    this->_3d2 = 0;
    this->_3e8 = 0;
    this->_3ea = 0;
    this->_3e4 = 0;
    this->_3eb = 0;
    this->_358 = 0;
    this->_3ec = 0;
    this->_2c4 = 0;
    this->_34c = 0x6e;
    this->_2be = func_0201f000(&this->position);
    this->_3ed = 0;
    this->_3ef = 0;
    this->linked_player = ~0;
    this->_3df = 0;
    this->_3d0 = 0;
    this->_3de = 0;
    this->_350 = 1;
    this->_3f1 = 0;
}

bool StageEntity::onUpdate_0()
{
    return true;
}

bool StageEntity::onUpdate()
{
    this->onUpdate_xx();
    i32 state = this->_340;
    if (state == 0)
    {
        return this->onUpdate_0();
    }
    if (state == 1)
    {
        return this->onUpdate_1();
    }
    if (state == 2)
    {
        return this->onUpdate_defeated();
    }
    if (state == 3)
    {
        return this->onUpdate_3();
    }
    if (state == 4)
    {
        return this->onUpdate_4();
    }
    if (state == 5)
    {
        return this->onUpdate_5();
    }
    if (state == 6)
    {
        return this->onUpdate_6();
    }
    if (state == 7)
    {
        return this->onUpdate_7();
    }
    if (state == 8)
    {
        return this->onUpdate_8();
    }
    if (state == 9)
    {
        return this->onUpdate_9();
    }
    this->_340 = 0;
    return this->onUpdate_0();
}

bool StageEntity::_01()
{
    if (this->_3e9 != 0)
    {
        return false;
    }
    if (this->_340 != 5)
    {
        i32 a = this->_384.x << 0xc;
        i32 b = this->_384.y << 0xc;
        i32 c = this->_378.x;
        i32 d = this->_378.y;
        return func_0200ae9c(&this->position);
    }
    return false;
}

void StageEntity::_12()
{
    this->_3c6[this->linked_player] = 0xc;
    (this->active_collider)._26 |= 0x140;
    if (this->_3c2 != 0)
    {
        (this->active_collider)._25 = 0xa;
        (this->active_collider)._2c = (void *)shellCallback;
    }
}

void StageEntity::_13()
{
    (this->active_collider)._26 &= ~0x140;
    (this->active_collider)._25 = 0x0;
    (this->active_collider)._2c = (void *)damagePlayerCallback;
    this->accelH = 0;
    (this->minVelocity).x = 0;
    this->_2c6 &= 0xfffe;
}

u32 data_ov000_020c1f60[2];
void StageEntity::_19()
{
    if (this->_3f1 != 0x0)
    {
        (this->velocity).x = data_ov000_020c1f60[this->direction];
    }
    else
    {
        this->_pad4[1] = 0x0;
    }
    this->active_collider._26 &= ~0x140;
    this->active_collider._25 = 0x0;
    this->active_collider._2c = damagePlayerCallback;
    this->_3f1 = 0x0;
    this->accelH = 0;
    this->minVelocity.x = 0;
    this->minVelocity.y = -0x4000;
    this->minVelocity.z = 0;
    this->_2c6 = this->_2c6 & 0xfffe;
    this->_340 = 0;
    return;
}

bool StageEntity::_14()

{
    this->active_collider._25 = 0xa;
    this->active_collider._26 = 0x113;
    return 0;
}

PlayerActor *GAME_getPlayer(u32);
void func_0201d954(PlatformManager *, u32);
void StageEntity::_16()
{
    PlayerBase *player;

    if (this->linked_player == ~0)
    {
        return;
    }
    player = GAME_getPlayer(this->linked_player);
    player->func_ov011_0212bde0(this);
    this->active_collider._26 &= ~0x100;
    this->active_collider._25 = 0x0;
    this->active_collider._2c = damagePlayerCallback;
    this->linked_player = -1;
    func_0201d954(&this->platform_manager, 0);
    this->collision_manager._rawr = 0x0;
    this->_2c6 = this->_2c6 & 0xfffe;
    return;
}

void func_02012398(u32, Vec3_32 *);
void StageEntity::_43(u32 param_1, u32 param_2, u32 param_3)
{
    this->_42(param_1, param_2, param_3, 0);
    this->_340 = 3;
    func_02012398(0x178, &this->position);
    return;
}

u16 data_ov000_020c1f44[2];
bool func_ov000_020a76d4();
void StageEntity::_18()
{
    PlayerBase *player;
    i32 iVar1;
    u32 uVar1;
    i32 iVar2;

    player = GAME_getPlayer((int)this->linked_player);
    (this->active_collider)._pad_a2[2] = (player->active_collider)._pad_a2[2];
    (this->collision_manager)._b7 = (player->active_collider)._pad_a2[2];
    if (((
             //((*(uint *)player->_pad2 & 1) == 0) &&
             ((player->velocity).y < 0)) &&
         (iVar1 = func_ov000_020a76d4(), iVar1 != 0)) &&
        ((uVar1 = (this->position).x + (this->centerOffset).x & 0xffff, 0x400 < uVar1 &&
                                                                            (uVar1 < 0x8001))))
    {
        iVar2 = (this->velocity).x;
        if (iVar2 < 0)
        {
            iVar2 = -iVar2;
        }
        if (iVar2 < 0x2c00)
        {
            this->_3f1 = 0x1;
        }
    }
    if (this->_3f1 == 0x0)
    {
        this->_3c6[this->linked_player] = 0x10;
    }
    else
    {
        this->_3b8 = 0;
        (this->velocity).x = (int)(short)data_ov000_020c1f44[this->direction];
        this->_3c6[this->linked_player] = 5;
    }
    (this->active_collider)._26 = (this->active_collider)._26 | 0x140;
    (this->active_collider)._25 = 0xa;
    (this->active_collider)._2c = shellCallback;
    this->accelH = 0x100;
    this->accelV = -0x300;
    (this->minVelocity).x = (this->velocity).x;
    (this->minVelocity).y = -0x4000;
    (this->minVelocity).z = 0;
}

void StageEntity::_45()
{
    this->direction ^= 1;
    this->velocity.x = -(this->velocity).x;
    this->active_collider._2c = damagePlayerCallback;
}

void StageEntity::_44() {
    this->active_collider._2c = (void *)0x0;
}

bool StageEntity::onUpdate_1()
{
    return true;
}
bool StageEntity::onUpdate_defeated()
{
    if (this->_3e8 != 0x0)
    {
        if (this->direction != '\0')
        {
            this->rotation.x += -0x300;
        }
        else
        {
            this->rotation.x += 0x300;
        }
    }
    else
    {
        this->rotation.x += 0x300;
    }
    this->updateVerticalVelocity();
    this->func_ov000_0209c85c();
    this->func_ov000_0209c820(0xfffffd00);
    this->_11();
    this->func_ov000_0209adb0(((u32)(this->_2c6 & 2) << 0xf) >> 0x10);
    return true;
}
bool StageEntity::onUpdate_3()
{
    if (this->_3e8 != 0x0)
    {
        u16 rotation = this->rotation.x;
        if (this->direction != '\0')
        {
            rotation -= 0xc00;
        }
        else
        {
            rotation += 0xc00;
        }
        this->rotation.x = rotation;
    }
    else
    {
        this->rotation.x += 0xc00;
    }
    this->updateVerticalVelocity();
    this->func_ov000_0209c85c();
    this->_11();
    this->func_ov000_0209adb0(((u32)(this->_2c6 & 2) << 0xf) >> 0x10);
    return true;
}
bool StageEntity::onUpdate_4()
{
    return true;
}
bool StageEntity::onUpdate_5() {}
bool StageEntity::onUpdate_6()
{
    this->_11();
    return true;
}
bool StageEntity::onUpdate_7() {}
bool StageEntity::onUpdate_8() {}
bool StageEntity::onUpdate_9() {}
void StageEntity::_11() {}

u16 data_ov000_020c22b8[2];
u16 getActorID(u8 sprite_id)
{
    return data_ov000_020c22b8[sprite_id];
}

void StageEntity::onUpdate_xx()
{
    if ((this->_2c6 & 0x4000) != 0)
    {
        return;
    }

    if ((u32)((this->active_collider._1c0 & 0x80) << 0x10) >> 0x10)
    {
        this->_3bc = 0x18;
        this->_3a8 = 0x1000;
    }

    if (this->_3bc == 0)
    {
        this->_35c.x = this->scale.x;
        this->_35c.y = this->scale.y;
        this->_35c.z = this->scale.z;
        this->_3a8 = 0x1000;
        return;
    }
    this->_3bc -= 1;
    if (this->_3bc & 0x4)
    {
        this->_3a8 += 0x100;
    }
    else
    {
        this->_3a8 -= 0x100;
    }
}

i32 StageEntity::attachToPlayerHands(i32 z, i32 y, i32 x) {}

i32 StageEntity::tryAttachToPlayerHands(i32 z, i32 y, i32 x) {}

u32 StageEntity::random()
{
    return WiFi::random();
}

bool StageEntity::spawnBrokenPipe(i32 a, i32 b, u32 c, u32 d, u8 e, u8 f, i8 g)
{
    Vec3_32 vec;
    vec.z = 0;
    vec.x = a;
    vec.y = b;
    Actor *actor = Actor::spawnActor(0xd3, d | e << 8 | c << 0x10 | f << 0x1c | g << 0x1f, &vec, 0, 0, 0);

    if (actor == NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void StageEntity::simpleCallback(ActiveCollider *collider) {}

void StageEntity::shellCallback(ActiveCollider *collider) {}

void StageEntity::damageEntityCallback(ActiveCollider *collider) {}

void StageEntity::updateBounce(i32 a, i32 b, i32 c) {}

void StageEntity::destroy(bool permanent)
{
    Base::destroy();
    u8 *_3d8 = this->_3d8;
    u16 *_3cc = this->_3cc;
    if (!permanent)
    {
        if (_3d8 != 0)
        {
            *_3d8 &= ~1;
        }
    }
    else
    {
        if (_3d8 != 0)
        {
            *_3d8 |= 8;
        }
        if (_3cc != 0)
        {
            *_3cc = 300;
        }
        return;
    }
}

void StageEntity::setTimedEvent(u32 event_id, i32 time, bool enable, bool switch_event, bool play_sfx) {}

void StageEntity::applyFireballWiggle() {}

bool StageEntity::rotateToTarget(i16 a[2], i16 b[2]) {}

bool StageEntity::checkPlayersInOffset(i32 x) {}

bool StageEntity::checkPlayersInOffset(i32 x, i32 y) {}

u32 StageEntity::updateCollisionSensors() {}

bool StageEntity::checkLavaCollision(Vec3_32 *pos) {}

void StageEntity::stopVelocity()
{
    this->velocity.x = 0;
    this->velocity.y = 0;
    this->accelV = 0;
}

u32 StageEntity::updateBottomSensors() {}

u32 StageEntity::updateSideSensors() {}

void StageEntity::onMegaGroundPound()
{
    this->active_collider.delink();
    this->_42(0, 0x2000, 0xfffffd00, 0);
}

bool StageEntity::checkSquished()
{
    u32 _2bf = this->empty;
    if (_2bf != 0)
    {
        return true;
    }
}

void StageEntity::onStageComplete(PlayerActor *player) {}

bool StageEntity::setGroundPoundCollision(PlayerActor *player) {}

bool StageEntity::isBelowPlayer(i32 posY, ActiveCollider *collider, u8 player_id)
{
    return -((posY + collider->rect.y) - collider->rect.halfHeight) < (int)Game::cameraY[player_id];
}

void StageEntity::damagePlayerCallback(ActiveCollider *collider, ActiveCollider *other) {}

bool StageEntity::playerCollision(ActiveCollider *collider, ActiveCollider *other) {}

void StageEntity::entityCollision() {}

void StageEntity::damagePlayer(ActiveCollider *collider, PlayerBase *player)
{
    bool check;
    if ((player->_79c != 0) || (player->_7c1 != 0))
    {
        check = 1;
    }
    else
    {
        check = 0;
    }

    if (!check)
    {
        u32 shell_status = player->getShellStatus();
        if (shell_status != 1)
        {
            player->virt_25(this, 0, 0x4000, 0);
        }
    }
}

u32 StageEntity::stopPlayerInShell(ActiveCollider *collider, PlayerActor *player)
{
    if (player->getShellStatus() == 1)
    {
        if (
            (collider->_3c > 0 && player->velH > 0) ||
            (collider->_3c < 0 && player->velH < 0))
        {
            player->velH = 0;
            return 2;
        }
        return 1;
    }
    return 0;
}

void StageEntity::isPlayerInZone(PlayerActor *player, u32 id) {}

void StageEntity::assignView(Vec3_32 *position) {}

void StageEntity::func_ov000_020988d0(u32 bit)
{
    data_ov000_020ca2b8 |= 1 << (bit & 0x1f);
}

void StageEntity::func_ov000_020988ac(u32 bit)
{
    data_ov000_020ca2b8 &= ~(1 << (0x1f & bit));
}

Vec3_32 StageEntity::tryNormalizeVec3(Vec3_32 *input)
{
    if (input->x == 0 && input->x == 0 && input->z == 0)
    {
        return *input;
    }
    Vec3_32 result;

    return result;
}

u32 StageEntity::getSpritePriority(u32 a, u32 b, u32 c) {}

u16 *StageEntity::getObjectBank(u32 sprite_id)
{
    return &Stage::ObjectBankTable[sprite_id];
}