#pragma once
#include "../nsmb_nitro.hpp"

// Placeholder names: 8-byte file holders built from an extended file ID. Their ctors
// and dtors live in ov130 (shared minigame code) and wrap main/autoload code.
class MGFileA
{
      public:
	u8 _0[8];

	MGFileA(u32 fileID);
	~MGFileA();
};

class MGFileB
{
      public:
	u8 _0[8];

	MGFileB(u32 fileID);
	~MGFileB();
};
