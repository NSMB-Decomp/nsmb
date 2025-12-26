#include "Coin.hpp"

Coin::Coin() {

}

void* Coin::operator new(u32 a) {
    return new Coin();
}

void Coin::_21() {}

void (func_ov000_020ab350)(Collider*);
void (func_ov010_020d9d84)(Coin*);
void (func_ov010_020d9b40)(Coin*);
void (func_ov010_020d99a8)(Coin*);
void (func_ov000_0209adb0)(Coin*, i32);
void (func_ov000_020ab2cc)(Collider*);
bool Coin::_00() {
    func_ov000_020ab350(&this->_444);
    func_ov010_020d9d84(this);
    if (
        (this->_4c0 - 1 <= 1) && (this->_01() == false)
    ) {
        this->_3e4 = 1;
    } 
    func_ov010_020d9b40(this);
    func_ov010_020d99a8(this);
    func_ov000_0209adb0(this, 0);
    func_ov000_020ab2cc(&this->_444);
    return true;
}

void Coin::_11() {}

void Coin::_34() {}

u32 (func_ov000_02098798)(void*, u32);
void (func_ov010_020d8488)();
void (func_0200d578)();
u32 data_ov010_02129438;
bool Coin::onRender() {
    if (this->_4ce == 0) {
        if (this->_4df == 0) {
            u32 a = data_ov010_02129438;
            if (this->_4c0 != 0) {
                a = this->_4e0;
            }
            u32 b = func_ov000_02098798(this, 0);
            if ((this->_4c0 == 0) && (this->_4c4 != 0)) {
                b = 0x20;
            }
        }
        return true;
    } else if (this->_4d8 == 0) {
        u32 a = func_ov000_02098798(this, 0);
    } else {
        if (this->_4d9 != 0) {

        }
    }
    return true;
}

PTMF data_ov010_021293f4;
u32 *data_ov010_0212163c;
void Coin::func_ov010_020d81dc(u32 a) {
    if ((this->_430 != &data_ov010_021293f4) != 0 ? true : false) {
        this->func_ov010_020d9dcc(&data_ov010_021293f4);
        this->velocity.x = data_ov010_0212163c[a];
        this->velocity.y = 0;
    }
}

void Coin::func_ov010_020d823c(u32 a) {
    this->_3f4 = a;
}

bool Coin::onDestroy() {
    return true;
}

Coin::~Coin() {}