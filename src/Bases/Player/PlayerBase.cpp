#include "PlayerBase.hpp"

PlayerBase::PlayerBase()
{
}

u32 data_02085a7c;
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