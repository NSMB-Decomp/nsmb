#include "DebugScene.hpp"

DebugScene::DebugScene() {}
void *DebugScene::operator new(u32 a)
{
    return new DebugScene();
}

bool DebugScene::onCreate()
{
    return true;
}

bool DebugScene::onHeapCreated()
{
    return true;
}

bool DebugScene::onDestroy()
{
    u16 a[1];
    FS::Cache::clear();
    a[0] = 0;
    Nitro_::func_02063af0(a, 0, 2);
    return true;
}

void DebugScene::pendingDestroy()
{
}

bool DebugScene::onRender()
{
    return true;
}

bool DebugScene::onUpdate()
{
    return true;
}

void DebugScene::func_ov002_020cc514()
{
}

void DebugScene::func_ov002_020cc328()
{
    u8 a = Input::localConsoleID;
    if ((Input::consoleKeys[a][0] & 4) != 0)
    {
        this->_1d8 = 0;
        return;
    }

    u32 b = this->_1fc / 5;
    u32 c = this->_1fc % 5;
    u32 d = 5;
    if (b == 2)
    {
        d = 4;
    }
    i32 e = 3;
    if (3 < c)
    {
        e = 2;
    }

    if ((Input::consoleKeysRepeated[0] & 0x10) == 0)
    {
        if ((Input::consoleKeysRepeated[0] & 0x20) == 0)
        {
            if ((Input::consoleKeysRepeated[0] & 0x80) == 0)
            {
                if ((Input::consoleKeysRepeated[0] & 0x40) != 0)
                {
                    b += -1;
                    if (b < 0)
                    {
                        this->_204 = e + -10;
                        b = e + -1;
                        if (this->_204 < 0)
                        {
                            this->_204 = 0;
                        }
                    }
                }
            }
            else if (b < *(int *)((int)this + 0x204))
            {
                this->_204 -= 1;
            }
            else
            {
                b += 1;
                if (b < e)
                {
                    if (this->_204 + 10 <= b)
                    {
                        this->_204 += 1;
                    }
                }
                else
                {
                    b = 0;
                    this->_204 = 0;
                }
            }
        }
        else
        {
            c += -1;
            if (c < 0)
            {
                c = d + -1;
            }
        }
    }
    else
    {
        c += 1;
        if (d <= c)
        {
            c = 0;
        }
    }

    this->_1fc = b * 5 + c;
    u32 f = Input::consoleKeys[a][0];
    if (((f & 1) == 0) && ((f & 8) == 0))
    {
        return;
    }
    Stage::stageGroup = this->_1dc;
    Stage::stageID = this->_1e0;
    Stage::stageAreaID = this->_1e4;

    u32 g;
    // if ((f & 1) == 0) {
    //     b = this->_1fc * 0xc;
    //     g = data_ov002_020cd11c[]
    // }
}

DebugScene::~DebugScene() {}

struct SomethingElse
{
    char *a;
    u16 b;
    u16 c;
    u32 d;
};

const SomethingElse data_ov002_020cd11c[] = {
    {"KINOK", 0x9, 0x9, 0xA000},
    {"KINO2", 0x9, 0x9, 0xC000},
    {"KINO3", 0x9, 0x9, 0xA001},
    {"WORLD", 0x8, 0x8, 0x0},
    {"SAVE", 0x7, 0x7, 0x0},
    {"TITLE", 0x4, 0x4, 0x0},
    {"ENDIN", 0xC, 0xC, 0x0},
    {"CRSIN", 0xD, 0xD, 0x0},
    {"GOVER", 0xE, 0xE, 0x0},
    {"KEY", 0x11, 0x11, 0x0},
    {"SOUND", 0x10, 0x10, 0x0},
    {"ENTRY", 0x6, 0x6, 0x0},
    {"ERROR", 0xB, 0xB, 0x0},
    {"MGVS", 0x146, 0x146, 0x0},
};

const u8 data_ov002_020cd114[4] = {0, 1, 3, 0};
u8 data_ov002_020cd240[4][2] = {
    {0, 0},
    {1, 0},
    {0, 1},
    {0, 0},
};

struct Profile
{
    u32 constructor;
    u16 a;
    u16 b;
};
Profile Scene2_Profile = {(u32)DebugScene::operator new, 2, 9};

struct LPTMF
{
    void (DebugScene::*a)();
    u8 b;
};
LPTMF data_ov002_020cd308[] = {
    {DebugScene::func_ov002_020cc514, 0},
    {DebugScene::func_ov002_020cc328, 0}};

u8 data_ov002_020cd220[4] = {1, 1, 3, 0};

