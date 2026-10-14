#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 165  |  ov010  |  profile @ 0x02125dd8
class Object165 : public StageEntity {
public:
	static void *create();
	inline Object165() {};
	inline ~Object165() {};
};

extern ActorProfile Object165_Profile;

