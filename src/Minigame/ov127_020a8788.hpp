#pragma once
#include "../nsmb_nitro.hpp"
#include "../Vec.hpp"

// Placeholder names: both classes are only known from the ov127 __sinit and their
// inline ctors/dtors.
class MGUnk148
{
      public:
	u8 _0[0x20];
	u32 _20;
	u8 _24[0x124];

	inline MGUnk148() { _20 = 0x2f; }
	inline ~MGUnk148() {}

	void func_ov127_0209af60();
	void func_ov127_0209b038();
	void func_ov127_0209b06c();
	void func_ov127_0209b2f0();
	void func_ov127_0209b310();
	void func_ov127_0209b32c();
	void func_ov127_0209b3e8();
	void func_ov127_0209b57c();
	void func_ov127_0209b5bc();
	void func_ov127_0209b898();
	void func_ov127_0209b9a8();
	void func_ov127_0209b9e4();
	void func_ov127_0209ba00();
	void func_ov127_0209bbd8();
	void func_ov127_0209bdb0();
	void func_ov127_0209bdd8();
	void func_ov127_0209bfa0();
	void func_ov127_0209bfc4();
	void func_ov127_0209c210();
	void func_ov127_0209c464();
	void func_ov127_0209c6b0();
	void func_ov127_0209c6d8();
	void func_ov127_0209c8a0();
	void func_ov127_0209c8d0();
	void func_ov127_0209c8dc();
	void func_ov127_0209c90c();
	void func_ov127_0209c918();
	void func_ov127_0209c930();
	void func_ov127_0209c93c();
	void func_ov127_0209c954();
};

class MGUnk30
{
      public:
	u32 _0;
	Vec2_32 _4;
	Vec2_32 _10;
	Vec2_32 _1c;
	u8 _28[6];
	s16 _2e;

	inline MGUnk30() {}
	inline ~MGUnk30() {}

	void func_ov127_0209c9ec();
	void func_ov127_0209ca40();
	void func_ov127_0209cb3c();
	void func_ov127_0209cc24();
};
