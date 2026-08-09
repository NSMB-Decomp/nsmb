#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 350  |  ov128  |  profile @ 0x02100000
class Object350 : public StageEntity {
public:
	static void *create();
	inline Object350() {};
	inline ~Object350() {};
};

extern ObjectProfile Object350_Profile;

