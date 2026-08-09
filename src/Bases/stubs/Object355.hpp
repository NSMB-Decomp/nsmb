#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 355  |  ov128  |  profile @ 0x02100c00
class Object355 : public StageEntity {
public:
	static void *create();
	inline Object355() {};
	inline ~Object355() {};
};

extern ObjectProfile Object355_Profile;

