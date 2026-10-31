#pragma once
#include "../Base.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 318  |  ov008  |  profile @ 0x020e58d0
class Object318 : public Base {
public:
	static void *create();
	inline Object318() {};
	inline ~Object318() {};

	void func_ov008_020ccd74();
	void func_ov008_020ccd78();
};

extern ObjectProfile Object318_Profile;

