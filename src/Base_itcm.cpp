#include "Base.hpp"

bool Base::onUpdate() {
    return true;
}

bool Base::preUpdate() {
    if (this->pending_destroy != false || (this->__4 & 2) != 0) {
        return false;
    }
    return true;
}

void Base::postUpdate() {}


bool Base::onRender() {
    return true;
}

bool Base::preRender() {
    if (this->pending_destroy != false || (this->__4 & 8) != 0) {
        return false;
    }
    return true;
}

void Base::postRender() {}

bool Base::func_01ffd290() {

}