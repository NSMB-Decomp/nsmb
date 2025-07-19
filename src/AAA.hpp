#include "base_types.hpp"

struct ObjectProfile {
    Base* (*constructor)() ;
    u16 updatePriority;
    u16 renderPriority;
};

extern ObjectProfile** CurrentProfileTable;

bool func_0204d82c();
u32 func_01ffd524(Base*, u32, u32, u32, u32, u32, u32);
extern u32 data_02085240[2] = {0, 0};
extern u32 data_02085238[2] = {0, 0};
extern u32 data_02085228[2] = {0, 0};

extern u32 data_02085230[2] = {0, 0};
extern u32 data_02085248[2] = {0, 0};
extern u32 data_02085250[2] = {0, 0};