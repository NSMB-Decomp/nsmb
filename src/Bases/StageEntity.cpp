#include "StageEntity.hpp"

bool (func_0201f000)(Vec3_32*);
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

bool StageEntity::_00() {
    return true;
}

bool StageEntity::onUpdate() {
    this->_20();
    i32 state = this->_340;
    if (state == 0) {
        return this->_00();
    }if (state == 1) {
        return this->_02();
    }if (state == 2) {
        return this->_03();
    }if (state == 3) {
        return this->_04();
    }if (state == 4) {
        return this->_05();
    }if (state == 5) {
        return this->_06();
    }if (state == 6) {
        return this->_07();
    }if (state == 7) {
        return this->_08();
    }if (state == 8) {
        return this->_09();
    }if (state == 9) {
        return this->_10();
    }
    this->_340 = 0;
    return this->_00();
}

bool (func_0200ae9c)(Vec3_32*);
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

bool StageEntity::_02() {
    return true;
}
bool StageEntity::_03() {}
bool StageEntity::_04() {}
bool StageEntity::_05() {
    return true;
}
bool StageEntity::_06() {}
bool StageEntity::_07() {
    this->_11();
    return true;
}
bool StageEntity::_08() {}
bool StageEntity::_09() {}
bool StageEntity::_10() {}
void StageEntity::_11() {}
