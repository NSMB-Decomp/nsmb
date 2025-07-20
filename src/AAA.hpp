#include "base_types.hpp"

struct ObjectProfile {
    Base* (*constructor)() ;
    u16 updatePriority;
    u16 renderPriority;
};

extern ObjectProfile** CurrentProfileTable;

//
void func_02066fe8(void *, u32, u32);

//
void func_02044d94(void *, void *);
void* func_02045040(void*, u32, i32);
extern void * data_0208b720;

//
bool func_0204d82c();
u32 func_01ffd524(Base*, u32, u32, u32, u32, u32, u32);
