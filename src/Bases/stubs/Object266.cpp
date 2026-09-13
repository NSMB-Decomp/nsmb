#include "Object266.hpp"

void *Object266::create()
{
	return new Object266();
}

// 0x02146ad8
ActorProfile Object266_Profile = { Object266::create, 266, 156, NULL };

bool Object266::onUpdate_0()
{
    return 1;
}


s32 Object266::onCreate()
{
  this->_3e6 = 1;
  this->collisionType = 1;
  return 1;
}

