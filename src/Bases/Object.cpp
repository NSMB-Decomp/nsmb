#include "Object.hpp"

void Object::postCreate(u32 a) {
    if (a == 1) {
        Object::destroy();
    }
    Base::postCreate(a);
}

void Object::__stub() {}

Object::~Object() {}