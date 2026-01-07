#include "MGScene_338.hpp"

struct STRS
{
    char *strings[27];
};
const STRS MG_DEBUG_STRINGS = {
    {
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
    },
};

// const char *MG_DEBUG_STRINGS[27] = ;
u16 data_ov130_02139100[27] = {0x166, 0x169, 0x180, 0x16D, 0x16E, 0x16F, 0x171, 0x172, 0x167, 0x168, 0x16A, 0x16C, 0x170, 0x175, 0x174, 0x173, 0x176, 0x177, 0x178, 0x179, 0x17A, 0x17B, 0x17C, 0x17D, 0x17E, 0x17F, 0x148};

struct TEMP_2
{
    u16 a;
    i16 b;
    i16 c;
    i16 d;
    u8 e;
};

TEMP_2 data_ov130_02137df8[] = {
    {0x169, 0xC, 0x28, 0xC, 0x0},
};

void *MGScene_338::create()
{
    return new MGScene_338();
}

void MGScene_338::virt_18()
{
    this->_68 = 0x1b;
}

char* MGScene_338::virt_19(u32 param_1)
{
    STRS a = MG_DEBUG_STRINGS;
    return a.strings[param_1];
}

u16 data_0203d318;
void func_ov130_02135230(void *, u32);
u8 data_ov130_0213ace4;
u16 data_ov130_02137de0;
u16 data_ov130_02137dec;
u32 data_ov130_02137df0;
u16 data_ov130_02137de8;
u32 data_ov130_02137dfc;
u32 data_ov130_02137dfe;
u8 data_ov130_021395e4;
u32 data_ov130_02137bf0;
void *data_ov130_0213ad08;
void MGScene_338::virt_20(u32 param_1)
{
    bool a = false;
    bool b = false;
    u16 c = data_ov130_02139100[param_1];
    if ((data_020887fc != 0) && (data_020887fc != 9))
    {
        b = true;
    }
    if (b && (data_020887fc != 8))
    {
        a = true;
    }

    if (a)
    {
        if (c == 0x148)
        {
            return;
        }
        if (c == 0x14e)
        {
            return;
        }
    }
    if ((c == 0x148) || (c == 0x14e))
    {
        MGScene::func_02024ab8();
        MGScene::func_02024bec(c, 0, 0);
    }
    else
    {
        MGScene::func_02024ad0(&data_ov130_0213ad08);
        func_ov130_02135230(&data_ov130_0213ad08, 0);
        data_ov130_0213ace4 = 1;
        data_0203d318 = data_ov130_02139100[param_1];
        data_ov130_02137de0 = 0x1c;
        data_ov130_02137dec = 0;
        data_ov130_02137df0 = 0;
        MGScene::func_02024bec(0x151, 0, 0);
        u32 i = 0;
        //if ((u64)data_ov130_02137bf0 * (u64)0xcccccccd >> 3) {
        //    return;
        //}
        u32 z = u32((u64)data_ov130_02137bf0 * 0xcccccccd) >> 0x3;
        if (z) {
            do
            {
                if (c == data_ov130_02137df8[i].a)
                {
                    data_ov130_02137dec = data_ov130_02137df8[i].b;
                    data_ov130_02137de0 = data_ov130_02137df8[i].c;
                    data_ov130_02137de8 = data_ov130_02137df8[i].d;
                    data_ov130_021395e4 = data_ov130_02137df8[i].e;
                    break;
                }
                i += 1;
            } while (i < z);
        }
    }
    this->_64 = 0;
}

bool MGScene_338::onCreate()
{
}

bool MGScene_338::onDestroy()
{
}

MGScene_338::MGScene_338() {}
MGScene_338::~MGScene_338() {}