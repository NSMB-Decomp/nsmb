#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 331  |  ov130  |  profile @ 0x02138c20
class Object331 : public StageEntity {
public:
	static void *create();
	inline Object331() {};
	inline ~Object331() {};
};

extern ObjectProfile Object331_Profile;

