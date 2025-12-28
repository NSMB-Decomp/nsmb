#include "StageEntity.hpp"

StageEntity::StageEntity() {
    //this->_40 = 0x2;
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
    this->_3c6 = 0;
    this->_3c8 = 0;
    this->_3d2 = 0;
    this->_3e8 = 0;
    this->_3ea = 0;
    this->_3e4 = 0;
    this->_3eb = 0;
    this->_358 = 0;
    this->_3ec = 0;
    this->_2c4 = 0;
    this->_34c = 0x6e;
    this->__4 = func_0201f000(&this->position);
    this->_3ed = 0;
    this->_3ef = 0;
    this->linked_player = ~0;
    this->_3df = 0;
    this->_3d0 = 0;
    this->_3de = 0;
    this->_350 = 1;
    this->_3f1 = 0;
}

bool StageEntity::onUpdate_0() {
    return true;
}

bool StageEntity::onUpdate() {
    this->onUpdate_xx();
    i32 state = this->_340;
    if (state == 0) {
        return this->onUpdate_0();
    }if (state == 1) {
        return this->onUpdate_1();
    }if (state == 2) {
        return this->onUpdate_2();
    }if (state == 3) {
        return this->onUpdate_3();
    }if (state == 4) {
        return this->onUpdate_4();
    }if (state == 5) {
        return this->onUpdate_5();
    }if (state == 6) {
        return this->onUpdate_6();
    }if (state == 7) {
        return this->onUpdate_7();
    }if (state == 8) {
        return this->onUpdate_8();
    }if (state == 9) {
        return this->onUpdate_9();
    }
    this->_340 = 0;
    return this->onUpdate_0();
}

bool StageEntity::_01() {
    if (this->_3e9 != 0) {
        return false;
    }
    if (this->_340 != 5) {
        i32 a = this->_384.x << 0xc;
        i32 b = this->_384.y << 0xc;
        i32 c = this->_378.x;
        i32 d = this->_378.y;
        return func_0200ae9c(&this->position);
    }
    return false;
}

bool StageEntity::onUpdate_1() {
    return true;
}
bool StageEntity::onUpdate_2() {}
bool StageEntity::onUpdate_3() {}
bool StageEntity::onUpdate_4() {
    return true;
}
bool StageEntity::onUpdate_5() {}
bool StageEntity::onUpdate_6() {
    this->_11();
    return true;
}
bool StageEntity::onUpdate_7() {}
bool StageEntity::onUpdate_8() {}
bool StageEntity::onUpdate_9() {}
void StageEntity::_11() {}

void StageEntity::isPlayerInZone(void* player, u32 id) {}

void StageEntity::assignView(Vec3_32* position) {}

void StageEntity::func_ov000_020988d0(u32 bit) {
    data_ov000_020ca2b8 |= 1 << (bit & 0x1f);
}

void StageEntity::func_ov000_020988ac(u32 bit) {
    data_ov000_020ca2b8 &= ~(1 << (0x1f & bit));
}

Vec3_32 StageEntity::tryNormalizeVec3(Vec3_32* input) {
    if (input->x == 0 && input->x == 0 && input->z == 0) {
        return *input;
    }
    Vec3_32 result;

    return result;
}

u32 StageEntity::getSpritePriority(u32 a, u32 b, u32 c) {}


u16 * StageEntity::getObjectBank(u32 sprite_id) {
    return &Stage::ObjectBankTable[sprite_id];
}