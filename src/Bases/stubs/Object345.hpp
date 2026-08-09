#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 345  |  ov128  |  profile @ 0x020feb50
class Object345 : public StageEntity {
public:
	static void *create();
	inline Object345() {};
	inline ~Object345() {};
};

extern ObjectProfile Object345_Profile;

