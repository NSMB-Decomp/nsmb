#include "Object19.hpp"

void *Object19::create()
{
	return new Object19();
}

s32 Object19::onCreate() {
    if (READ_NIBBLE(this->settings, 0) == 0) {
        this->_1 = 0xc8;
    } else {
        this->_1 = 0x200;
    }
    return true;
}

s32 Object19::onUpdate() {
    if (this->_1 != 0) {
        this->_1 -= 1;
    }
    return true;
}

s32 Object19::onRender() {

    return true;
}

void Object19::pendingDestroy() {

}

s32 Object19::onDestroy() {

    return true;
}

Object19::~Object19() {

}
