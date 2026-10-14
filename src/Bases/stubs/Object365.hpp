#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 365  |  ov129  |  profile @ 0x02119ba0
class Object365 : public StageEntity {
public:
	static void *create();
	inline Object365() {};
	inline ~Object365() {};
};

extern ObjectProfile Object365_Profile;

