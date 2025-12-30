#include "Scene_2.hpp"

Scene_2::Scene_2() {}
void * Scene_2::operator new(u32 a) {
    return new Scene_2();
}