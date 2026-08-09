#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 17  |  ov007  |  profile @ 0x020cc620
class Object17 : public StageEntity {
public:
	static void *create();
	inline Object17() {};
	inline ~Object17() {};
};

extern ObjectProfile Object17_Profile;

