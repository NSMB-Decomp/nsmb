// This file is used solely as a placeholder for functions with a currently unknown location.
// We should avoid using this file.

#include "base_types.hpp"

struct ObjectProfile {
    Base* (*constructor)() ;
    u16 updatePriority;
    u16 renderPriority;
};

extern ObjectProfile** CurrentProfileTable;
extern u8 Stage_actorFreezeFlag;

//
void func_02066fe8(void *, u32, u32);
extern u8 data_0v000_020ca84c;

//
void func_02044d94(void*, void *);
void* func_02045040(void*, u32, i32);
extern void* data_0208b720;

//
bool func_0204d82c();

//