#include "Actor.hpp"

bool Actor::preDestroy() {
    return Base::preDestroy() != false;
}