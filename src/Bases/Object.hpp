#pragma once
#include "Base.hpp"

class Object : public Base
{
      public:
	static Object *spawnObject(u16, Base *, u32, u8);
	static Object *spawnScene(u16, u32, u8);
	static void onInitialize();

	void postCreate(u32);
	inline ~Object() {};
};
NTR_SIZE_GUARD(Object, sizeof(Base));
