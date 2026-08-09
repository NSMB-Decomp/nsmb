#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 10  |  ov052  |  profile @ 0x0215bb9c
class Object10 : public StageEntity {
public:
	static void *create();
	inline Object10() {};
	inline ~Object10() {};
};

extern ObjectProfile Object10_Profile;

