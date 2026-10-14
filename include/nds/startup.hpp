#pragma once
#include "../../src/base_types.hpp"

extern "C" {

	// Defined by this file, referenced before they are defined.
	void func_02000920(u32 value, void* dest, u32 size);
	void func_02000934(void* bottom);
	void func_020009e0();
	void AutoloadCallback();
	void func_02000a5c();

	// Defined elsewhere.

	// Autoload list / static bounds followed by the NitroSDK module signature,
	// at 0x02000b48. It is data sitting in .text, which mwccarm cannot emit
	// from C++ (`#pragma section ".text"` still lands in .rodata) and dsd
	// refuses to type as a function, so it stays outside this file.
	extern u8 BuildInfo[];
	void NitroMain();
	void NitroStartUp();
	void _fp_init();
	void __call_static_initializers();
	void func_01ffd5e4();

	// DTCM base, and the protection unit descriptor built from it.
	extern u8 data_027e0000[];
	extern u8 data_027e0021[];

}
