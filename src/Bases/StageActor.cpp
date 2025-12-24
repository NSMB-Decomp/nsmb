#include "StageActor.hpp"

StageActor::~StageActor() {
    ActiveCollider::delink((void*)&this->c);
};