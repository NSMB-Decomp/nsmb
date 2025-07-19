#include "base_types.hpp"

struct ObjectProfile {
    Base* (*constructor)() ;
    u16 updatePriority;
    u16 renderPriority;
};

ObjectProfile** CurrentProfileTable;

bool func_0204d82c();
void func_01ffd524(Base*, u32, u32, u32, u32, u32, u32);
u32* data_02085240;
u32* data_02085238;
u32* data_02085228;
