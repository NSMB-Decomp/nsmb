#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 380  |  ov129  |  profile @ 0x0211b294
class Object380 : public StageEntity {
public:
	static void *create();
	inline Object380() {};
	inline ~Object380() {};
};

extern ObjectProfile Object380_Profile;

