#pragma once
#include "Base.hpp"

enum ObjectID {
	SC_Boot = 0,
	AC_Manhole = 187
};

class Object : public Base
{
      public:
	static Object *spawnObject(u16, Base *, u32, u8);
	static Object *spawnScene(u16, u32, u8);
	void __stub();

	void postCreate(u32);
	inline ~Object() {};
};
size_assert(Object, sizeof(Base));
