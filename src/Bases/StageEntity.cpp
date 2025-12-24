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

bool StageEntity::__00() {
    return true;
}