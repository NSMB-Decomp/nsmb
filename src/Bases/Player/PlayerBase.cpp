#include "PlayerBase.hpp"

PlayerBase::PlayerBase()
{
}

bool PlayerBase::func_ov011_0212bde0(u32 a) {
  this->_77c = this->_77c & ~0x1;
  if ((BOOL)(this->_688 == a) == FALSE) {
    return false;
  }
  this->func_ov011_0212b26c(0);
  return true;
}

u32 PlayerBase::func_ov011_0212bdb8(u32 a) {

}

u32 PlayerBase::func_ov011_0212bd68(u32 a, u32 b, u32 c) {

}

u32 PlayerBase::func_ov011_0212bca4() {

}

bool PlayerBase::func_ov011_0212bc50(i32 a) {
  if (a < 0) {
    if (this->_788 == 0) {
      this->position.y += a;
      return true;
    }
  }
  else if ((0 < a) && (this->_788 <= 0)) {
    this->position.y += a;
    return true;
  }
  return false;
}

void PlayerBase::func_ov011_0212bbdc(u32 a) {

}

void PlayerBase::func_ov011_0212bbcc() {
  this->_780 &=~ 0x200;
}

u32 PlayerBase::func_ov011_0212bba4()
{
  u32 result;

  if (this->_7bf == 0)
  {
    return 0;
  }
  if (this->minVelH == 0)
  {
    result = 1;
  }
  else
  {
    result = 2;
  }
  return result;
}

bool PlayerBase::func_ov011_0212bb90()
{
  return this->_7bf == TRUE;
}

u16 data_0208b344[2];
void func_02020150(u32, u32);
void func_02020128(u32);
void PlayerBase::func_ov011_0212bac8()
{
  i32 _7ac = this->_7ac;
  if (_7ac != 3)
  {
    if (_7ac != 4)
    {
      func_02020150(this->linked_player, 0);
      data_0208b344[this->linked_player] = 0x168;
      this->func_ov011_0212b838(0x167, &this->position);
      return;
    }
    func_02020150(this->linked_player, 0);
    data_0208b344[this->linked_player] = 0;
    return;
  }
  func_02020150(this->linked_player, 0x348);
  data_0208b344[this->linked_player] = 0;
  func_02020128(this->linked_player);
  return;
}

bool PlayerBase::func_ov011_0212b9f8(u8 a)
{
  bool bVar2;

  i8 _7ac = this->_7ac;
  if (_7ac == 3)
  {
    return false;
  }
  switch (a)
  {
  case 3:
    return this->func_ov011_0212b9ac(a);
  case 2:
    if (((_7ac == 0) || (_7ac == 1)) || (_7ac == 4))
    {
      return this->func_ov011_0212b9ac(a);
    }
    break;
  case 5:
    if (_7ac != 5)
    {
      return this->func_ov011_0212b9ac(a);
    }
    break;
  case 4:
    if (_7ac != 4)
    {
      return this->func_ov011_0212b9ac(a);
    }
    break;
  case 1:
    if ((_7ac == 0) || (_7ac == 4))
    {
      return this->func_ov011_0212b9ac(a);
    }
    break;
  case 0:
  default:
    return this->func_ov011_0212b9ac(a);
  }
  return false;
}

bool PlayerBase::func_ov011_0212b9ac(u8 a)
{
  if (BOOL(this->_7a9 == 0x5) != FALSE)
  {
    return false;
  }
  if (this->_7ab == a)
  {
    return false;
  }
  this->_7ab = a;
  return this->_7ac != this->_7ab;
}

void PlayerBase::func_ov011_0212b9a8() {}

void PlayerBase::func_ov011_0212b998()
{
  this->_780 |= 0x20;
}

void PlayerBase::func_ov011_0212b984()
{
  if ((this->_780 & 0x20) != 0)
  {
    this->_780 &= 0xffffffdf;
  }
}

void func_ov011_0212cfe4(void *);
void PlayerBase::func_ov011_0212b954()
{
  if ((this->_780 & 0x40) != 0)
  {
    this->_780 &= 0xffffffbf;
    func_ov011_0212cfe4(&this->_2c4);
  }
}

u8 data_ov000_020ca880;
u8 data_ov000_020ca898;
void PlayerBase::func_ov011_0212b908()
{
  data_ov000_020ca880 |= 0x10;
  data_ov000_020ca898 |= 0x40;
  this->_7b0 = 1;
  this->active_collider._1c6 |= 1;
}

void PlayerBase::func_ov011_0212b8bc()
{
  data_ov000_020ca880 &= ~0x10;
  data_ov000_020ca898 &= ~0x40;
  this->_7b0 = 0;
  this->active_collider._1c6 &= ~1;
}

u16 data_0208b350[2];
void PlayerBase::func_ov011_0212b878(u16 a)
{
  if (this->_7ac == 3)
  {
    return;
  }
  data_0208b350[this->linked_player] = a;
  this->func_ov011_0212b740(2);
  this->func_ov011_0212b998();
}

void func_02012314(u32, u32);
void PlayerBase::func_ov011_0212b864(u32 a, u32 b)
{
  func_02012314(a, b);
}

void func_020122d0(u32, u32, u32);
void PlayerBase::func_ov011_0212b84c(u32 a, u32 b, u32 c)
{
  func_020122d0(a, b, c);
}

void func_02012290(u32, Vec3_32 *);
void PlayerBase::func_ov011_0212b838(u32 a, Vec3_32 *b)
{
  func_02012290(a, b);
}

void func_0201224c(u32, u32, u32);
void PlayerBase::func_ov011_0212b820(u32 a, u32 b, u32 c)
{
  func_0201224c(a, b, c);
}

void func_020121e4(u32);
void PlayerBase::func_ov011_0212b810(u32 a)
{
  func_020121e4(a);
}

void func_0204e87c(u32, u32);
void func_02011e3c(u32);
void PlayerBase::func_ov011_0212b7f0(u32 a)
{
  func_0204e87c(a, 0x1e);
  func_02011e3c(a);
}

u32 data_02085a7c;
void PlayerBase::func_ov011_0212b7bc(u32 a)
{
  if (this->linked_player == data_02085a7c)
  {
    this->func_ov011_0212b7f0(a);
  }
}

u32 data_02085a84;
void func_02011dc4(u32);
void PlayerBase::func_ov011_0212b740(u32 a)
{
  if (this->linked_player != data_02085a7c)
  {
    return;
  }
  if (
      BOOL(data_02085a84 != 0) != FALSE &&
      (a == 3))
  {
    return;
  }
  this->_77c = this->_77c | 0x800000;
  func_02011dc4(a);
  this->_798 = a;
}

void func_02011d94(u32);
void PlayerBase::func_ov011_0212b710()
{
  if ((this->_77c & 0x800000) != 0)
  {
    this->_77c &= 0xff7fffff;
    func_02011d94(this->_798);
  }
}

void PlayerBase::func_ov011_0212b384(i16)
{
}

bool PlayerBase::func_ov011_0212b2bc()
{
}

void PlayerBase::func_ov011_0212b26c(u32 a)
{
}

void PlayerBase::setPosition(Vec3_32 *newPos)
{
  this->position.x = newPos->x;
  this->position.y = newPos->y;
}

u16 PlayerBase::func_ov011_0212b210(u16 a)
{
  if (this->_7ac == 4)
  {
    return (u16)(a * 0xd00 + 0x800 >> 0xc);
  }
  return a;
}

i8 PlayerBase::func_ov011_0212b1d4()

{
  int scale = this->scale.y;
  if (scale < 0xacc)
  {
    return 0;
  }

  if (0x1599 <= scale)
  {
    if (scale < 0x2000)
    {
      return 2;
    }
    return 3;
  }
  return 1;
}