#include "MGScene_338.hpp"

char *MG_DEBUG_STRINGS[] = {
    "HANACHAN",
    "SNOWBALL",
    "LUIGI",
    "COIN",
    "MEMORY",
    "BOMROOM",
    "PACHINKO",
    "TAMAIRE",
    "JUMP",
    "JUMP2",
    "AMIDA",
    "FLOWER",
    "BOMTHROW",
    "SPEED",
    "CARD",
    "TERESA",
    "BLACKJACK",
    "PANEL",
    "TRAMPOLINE2",
    "MOGURA",
    "TAMAYOKE",
    "INDIPORKER",
    "RIVERSI",
    "BALLOON",
    "SNOWWAR",
    "MCARLO",
    "TITLE",
};

void *MGScene_338::create()
{
    return new MGScene_338();
}

void MGScene_338::virt_18()
{
    this->_68 = 0x1b;
}

u32 MGScene_338::virt_19(u32 param_1)
{
    u32 a[27];
    // TODO: Is this a ASM optimization?

    //u32 *x = (u32*)MG_DEBUG_STRINGS;
    //u32 a[27];
    //u32 *y = (u32*)a;
    //u8 i = 6;
    //do {
    //    (*y++) = *x++;
    //    (*y++) = *x++;
    //    (*y++) = *x++;
    //    (*y++) = *x++;
    //    i -= 1;
    //} while (i != 0);
    //char* a[] = *MG_DEBUG_STRINGS;

    return a[param_1];
}

void MGScene_338::virt_20()
{
}

bool MGScene_338::onCreate()
{
}

bool MGScene_338::onDestroy()
{
}

MGScene_338::MGScene_338() {}
MGScene_338::~MGScene_338() {}