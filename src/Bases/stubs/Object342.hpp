#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 342  |  ov128  |  profile @ 0x020ffbb0
class Object342 : public StageEntity {
public:
	static void *create();
	inline Object342() {};
	inline ~Object342() {};
};

extern ObjectProfile Object342_Profile;

