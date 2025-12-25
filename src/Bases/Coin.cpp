#include "Coin.hpp"

void* Coin::operator new(u32 a) {

}

void Coin::_21() {}

void (func_ov000_020ab350)(i32);
void (func_ov010_020d9d84)(Coin*);
void (func_ov010_020d9b40)(Coin*);
void (func_ov010_020d99a8)(Coin*);
void (func_ov000_0209adb0)(Coin*, i32);
void (func_ov000_020ab2cc)(i32);
bool Coin::_00() {
    func_ov000_020ab350(this->_444);
    func_ov010_020d9d84(this);
    if (
        (this->_4c0 - 1 <= 1) && (this->_01() == false)
    ) {
        this->_3e4 = 1;
    } 
    func_ov010_020d9b40(this);
    func_ov010_020d99a8(this);
    func_ov000_0209adb0(this, 0);
    func_ov000_020ab2cc(this->_444);
    return true;
}

void Coin::_11() {}

void Coin::_34() {}

Coin::~Coin() {}