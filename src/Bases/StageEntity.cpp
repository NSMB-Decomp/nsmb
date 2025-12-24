#include "StageEntity.hpp"

StageEntity::StageEntity() {
    //this->_40 = 0x2;
    this->actorType = 0x2;
    this->actorCategory = (1 << this->actorType) | 0x80;
    this->actorCategory = this->actorCategory | 0x20;
    this->_2d0 = 0;
    this->_3e7 = (u32)~0;
    this->_3b4 = 0x107;
    this->accelV = -0x300;
    this->minVelocity.x = 0;
    this->minVelocity.y = 0;
    this->minVelocity.z = 0;
}

StageEntity::~StageEntity() {
    
}

bool StageEntity::__00() {
    return true;
}