#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 333  |  ov130  |  profile @ 0x02138a28
class Object333 : public StageEntity {
public:
	static void *create();
	inline Object333() {};
	inline ~Object333() {};
};

extern ObjectProfile Object333_Profile;

