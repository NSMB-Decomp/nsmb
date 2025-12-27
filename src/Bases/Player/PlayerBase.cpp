#include "PlayerBase.hpp"

PlayerBase::PlayerBase()
{
}

u16 PlayerBase::func_ov011_0212b210(u16 a) {

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