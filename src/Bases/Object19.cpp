#include "Object19.hpp"

void *Object19::create()
{
	return new Object19();
}

bool Object19::onCreate() {
    if (READ_NIBBLE(this->settings, 0) == 0) {
        this->_1 = 0xc8;
    } else {
        this->_1 = 0x200;
    }
    return true;
}

bool Object19::onUpdate() {
    if (this->_1 != 0) {
        this->_1 -= 1;
    }
    return true;
}


Object19::~Object19() {

}
