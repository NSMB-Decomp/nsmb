#include "Coin.hpp"

Coin::Coin()
{
}

void *Coin::operator new(u32 a)
{
    return new Coin();
}

void Coin::_21() {}

void(func_ov000_020ab350)(Collider *);
void(func_ov010_020d9d84)(Coin *);
void(func_ov010_020d9b40)(Coin *);
void(func_ov000_0209adb0)(Coin *, i32);
void(func_ov000_020ab2cc)(Collider *);
bool Coin::onUpdate_0()
{
    func_ov000_020ab350(&this->_444);
    func_ov010_020d9d84(this);
    if (
        (this->_4c0 - 1 <= 1) && (this->_01() == false))
    {
        this->_3e4 = 1;
    }
    func_ov010_020d9b40(this);
    this->func_ov010_020d99a8();
    func_ov000_0209adb0(this, 0);
    func_ov000_020ab2cc(&this->_444);
    return true;
}

void Coin::_11() {}

void Coin::onStageComplete(PlayerActor* player) {
    Vec3_32 vec = this->position;
    this->destroy(true);
}

u32(func_ov000_02098798)(void *, u32);
void(func_ov010_020d8488)();
void(func_0200d578)();
u32 data_ov010_02129438;
bool Coin::onRender()
{
    //    if (this->_4ce == 0) {
    //        if (this->_4df == 0) {
    //            u32 a = data_ov010_02129438;
    //            if (this->_4c0 != 0) {
    //                a = this->_4e0;
    //            }
    //            u32 b = func_ov000_02098798(this, 0);
    //            if ((this->_4c0 == 0) && (this->_4c4 != 0)) {
    //                b = 0x20;
    //            }
    //        }
    //        return true;
    //    } else if (this->_4d8 == 0) {
    //        u32 a = func_ov000_02098798(this, 0);
    //    } else {
    //        if (this->_4d9 != 0) {
    //
    //        }
    //    }
    //    return true;
}

PTMF data_ov010_021293f4;
u32 data_ov010_0212163c[2];
void Coin::func_ov010_020d81dc(u32 a)
{
    if ((BOOL)(this->_430 == &data_ov010_021293f4) == FALSE)
    {
        this->func_ov010_020d9dcc(&data_ov010_021293f4);
        this->velocity.x = data_ov010_0212163c[a];
        this->velocity.y = 0;
    }
}

void Coin::func_ov010_020d99a8()
{
    if (this->_4e8 == '\0')
    {
        return;
    }
    this->_4b0 = this->_4b0 + 0x10;
    if (0x40 <= (int)this->_4b0)
    {
        this->_4b0 = 0x40;
    }
    u8 uVar1 = this->_4ee;
    if (uVar1 == '\0')
    {
        this->_424.y = this->_424.y + this->_4b0;
        if (0x1200 <= this->_424.y)
        {
            this->_4ee = this->_4ee + 1 & 3;
            this->_4b0 = 0;
            return;
        }
        return;
    }
    if (uVar1 == '\x01')
    {
        this->_424.y = this->_424.y - this->_4b0;
        if (this->_424.y <= 0x1000)
        {
            this->_4ee = this->_4ee + 1 & 3;
            this->_4b0 = 0;
            return;
        }
        return;
    }
    if (uVar1 == '\x02')
    {
        this->_424.x = this->_424.x + this->_4b0;
        if (0x1200 <= this->_424.x)
        {
            this->_4ee = this->_4ee + 1 & 3;
            this->_4b0 = 0;
            return;
        }
        return;
    }
    this->_424.x = this->_424.x - this->_4b0;
    if (this->_424.x <= 0x1000)
    {
        this->_4ee = this->_4ee + 1 & 3;
        this->_4b0 = 0;
        return;
    }
    return;
}

u8 data_ov000_020c4ec0[2];
void *data_ov010_02125204;
bool Coin::onCreate()
{
    this->_408 = this->position;
    this->position.x += 0x8000;
    this->position.y -= 0x10000;
    this->_4c0 = this->settings & 0xf;
    this->direction = this->settings >> 0x1c;
    this->_4c4 = 0;
    if (this->_4c0 == 0)
    {
        this->_4c0 = this->settings >> 8 & 0xf;
    }
    this->_4eb = (this->settings >> 8) & 0xf;
    this->_4d0 = 0x1c2;
    this->_4d8 = 4;
    this->_4da = 0;
    this->_3ea = 0;
    this->_4ef = 0;
    this->_4e8 = 0;
    this->_4ea = 0;
    this->_4e3 = 0;
    this->_4ec = 0;
    this->_4e9 = 0;
    this->scale.x = 0x1200;
    this->scale.y = 0x1200;
    this->scale.z = 0x1200;
    this->_3b4 &= 0xfffffff9;
    Collider *c = &this->_444;
    c->init((Base *)this, data_ov010_02125204, 0x20000, 0, 0);
    if (this->_4c4 == 0)
    {
        this->_4ad = 0;
    }
    else
    {
        this->_4ad = data_ov000_020c4ec0[this->_4c4];
    }
    this->func_ov000_0209c820(0xfffffd80);

    u32 _4c0 = this->_4c0;
    if (_4c0 != 0)
    {
    }
}

u32 func_0200e6f4();
void Coin::func_ov010_020d8b40()
{
    this->_4e8 = 1;
    this->_4ef = 1;
    this->_4ec = 1;
    this->_4ed = 0;
    this->_4b0 = 0;
    this->_418.x = 0x1000;
    this->_418.y = 0x1000;
    this->_424.x = 0x1000;
    this->_424.y = 0x1000;
    u32 uVar1 = func_0200e6f4();
    // TODO: Is this a typecast? Can we make the syntax better?
    this->_4ee = ((((uVar1 & 0x7fff) << 1) >> 0xf) << 1);
}

void Coin::func_ov010_020d823c(u32 a)
{
    this->_3f4 = a;
}

bool Coin::onDestroy()
{
    this->_444.unlink();
    return true;
}

Coin::~Coin() {}