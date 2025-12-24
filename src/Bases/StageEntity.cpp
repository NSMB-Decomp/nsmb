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
    this->velocity.x = 0;
}

StageEntity::~StageEntity() {
    
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

bool StageEntity::_01() {

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
